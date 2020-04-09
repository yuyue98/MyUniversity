#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define _WSPIAPI_COUNTOF
#define HAVE_REMOTE
#include "pcap.h"

using namespace std;

/* 4字节的IP地址 */
typedef struct ip_address{
    u_char byte1;
    u_char byte2;
    u_char byte3;
    u_char byte4;
}ip_address;

#define ETH_ALEN       6    // 以太网地址大小
#define ETH_HLEN       14   // 以太网头部大小
#define ETH_DATA_LEN   1500 // 最大帧负载数据大小
#define ETH_FRAME_LEN  1514 // 最大帧大小，头部+负载数据
typedef struct mac_header{
	u_int8_t mac_dhost[ETH_ALEN]; // 目的MAC地址 
	u_int8_t mac_shost[ETH_ALEN]; // 源MAC地址 
	u_int16_t mac_type;           // 帧类型 
}mac_header;

#define ETHERTYPE_IP     0x0008 // IP数据包
#define ETHERTYPE_ARP    0x0608 // ARP请求应答
#define ETHERTYPE_REVARP 0x3508 // RARP请求应答

/* IPv4 首部 */
typedef struct ip_header{
    u_char  ver_ihl;        // 版本 (4 bits) + 首部长度 (4 bits)
    u_char  tos;            // 服务类型(Type of service) 
    u_short tlen;           // 总长(Total length) 
    u_short identification; // 标识(Identification)
    u_short flags_fo;       // 标志位(Flags) (3 bits) + 段偏移量(Fragment offset) (13 bits)
    u_char  ttl;            // 存活时间(Time to live)
    u_char  proto;          // 协议(Protocol)
    u_short crc;            // 首部校验和(Header checksum)
    ip_address  saddr;      // 源地址(Source address)
    ip_address  daddr;      // 目的地址(Destination address)
    u_int   op_pad;         // 选项与填充(Option + Padding)
}ip_header;

/* UDP 首部*/
typedef struct udp_header{
    u_short sport;          // 源端口(Source port)
    u_short dport;          // 目的端口(Destination port)
    u_short len;            // UDP数据包长度(Datagram length)
    u_short crc;            // 校验和(Checksum)
}udp_header;

#define ARP_REQUEST  0x0100 // ARP请求
#define ARP_RESPONSE   0x0200 // ARP应答
#define RARP_REQUEST 0x0300 // RARP请求
#define RARP_RESPONSE  0x0400 // RARP应答
/* ARP 首部*/
typedef struct arp_header{
	u_int8_t arp_hrd[2];        // 硬件类型 
	u_int16_t arp_pro;          // 协议类型
	u_int8_t arp_hln;           // 硬件地址长度
	u_int8_t arp_pln;           // 协议地址长度
	u_int16_t arp_op;           // ARP命令 1（ARP请求）2（ARP应答）3（RARP请求）4（RARP应答）
	u_int8_t arp_sha[ETH_ALEN]; // 源MAC地址 
    ip_address  sip;            // 源地址(Source address)
	u_int8_t arp_tha[ETH_ALEN]; // 目的端MAC地址 
    ip_address  tip;            // 目的地址(Destination address)	
}arp_header;

/* ARP应答 */ 
typedef struct arp_response{
	u_int8_t arp_resaddr[ETH_ALEN]; //应答端MAC地址 
	ip_address resip;               //应答端IP地址 
}arp_response;

/* ARP请求 */ 
typedef struct arp_request{ 
	u_int8_t arp_reqaddr[ETH_ALEN]; // 请求端MAC地址
	ip_address reqip;               // 请求端IP地址
	arp_response response[100];     // 当前请求应答端信息记录 
	int response_num;               // 当前请求应答端数量 
}arp_request;

/* ARP攻击检测 */ 
typedef struct arp_atkcheck{
	arp_request request[100]; // 当前请求端信息记录 
	int request_num;          // 当前请求端数量 
}arp_atkcheck; 

arp_atkcheck atkcheck; 

/* 回调函数原型 */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data); 
/* 打印MAC地址 */
void putmacaddr(u_int8_t macaddr[]);
/* 获得协议类型 */
string gettype(u_int16_t protype); 
/* 获得操作方式 */
string getway(u_int16_t arpway); 
/* 判断MAC地址是否相等 */
bool judgeeqaddr(u_int8_t addr1[], u_int8_t addr2[]);
/* 判断IP地址是否相等 */
bool judgeeqip(ip_address ip1, ip_address ip2); 
/* 判断请求包是否已存在 */
int judgeczreq(u_int8_t reqaddr[], ip_address reqip); 
/* 判断应答包是否存在 */
int judgeczres(arp_request request, u_int8_t resaddr[], ip_address resip);  


int main()
{
	pcap_if_t *alldevs;
	pcap_if_t *d;
	int inum;
	int i=0;
	pcap_t *adhandle;
	char errbuf[PCAP_ERRBUF_SIZE];
    u_int netmask;
	char packet_filter[] = "arp";
	struct bpf_program fcode;
	int res;
	struct tm *ltime;
	char timestr[16];
	struct pcap_pkthdr *header;
	const u_char *pkt_data;
	time_t local_tv_sec;
    
    /* 获取本机设备列表 */
    if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1)
    {
        fprintf(stderr,"Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }
    
    /* 打印列表 */
    for(d=alldevs; d; d=d->next)
    {
        printf("%d. %s", ++i, d->name);
        if (d->description)
            printf(" (%s)\n", d->description);
        else
            printf(" (No description available)\n");
    }
    
    if(i==0)
    {
        printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
        return -1;
    }
    
    printf("Enter the interface number (1-%d):",i);
    scanf("%d", &inum);
    
    if(inum < 1 || inum > i)
    {
        printf("\nInterface number out of range.\n");
        /* 释放设备列表 */
        pcap_freealldevs(alldevs);
        return -1;
    }
    
    /* 跳转到已选中的适配器 */
    for(d=alldevs, i=0; i< inum-1 ;d=d->next, i++);
    
    /* 打开设备 */
    if ( (adhandle= pcap_open(d->name,          // 设备名
                              65536,            // 要捕捉的数据包的部分 
                      // 65535保证能捕获到不同数据链路层上的每个数据包的全部内容
                              PCAP_OPENFLAG_PROMISCUOUS,    // 混杂模式
                              1000,             // 读取超时时间
                              NULL,             // 远程机器验证
                              errbuf            // 错误缓冲池
                              ) ) == NULL)
    {
        fprintf(stderr,"\nUnable to open the adapter. %s is not supported by WinPcap\n", d->name);
        /* 释放设列表 */
        pcap_freealldevs(alldevs);
        return -1;
    }
    
    /* 检查数据链路层，为了简单，我们只考虑以太网 */
    if(pcap_datalink(adhandle) != DLT_EN10MB)
    {
        fprintf(stderr,"\nThis program works only on Ethernet networks.\n");
        /* 释放设备列表 */
        pcap_freealldevs(alldevs);
        return -1;
    }
    
    if(d->addresses != NULL)
        /* 获得接口第一个地址的掩码 */
        netmask=((struct sockaddr_in *)(d->addresses->netmask))->sin_addr.S_un.S_addr;
    else
        /* 如果接口没有地址，那么我们假设一个C类的掩码 */
        netmask=0xffffff; 
        
    //编译过滤器
    if (pcap_compile(adhandle, &fcode, packet_filter, 1, netmask) <0 )
    {
        fprintf(stderr,"\nUnable to compile the packet filter. Check the syntax.\n");
        /* 释放设备列表 */
        pcap_freealldevs(alldevs);
        return -1;
    }
    
    //设置过滤器
    if (pcap_setfilter(adhandle, &fcode)<0)
    {
        fprintf(stderr,"\nError setting the filter.\n");
        /* 释放设备列表 */
        pcap_freealldevs(alldevs);
        return -1;
    }
    
    printf("\nlistening on %s...\n", d->description);
    
    /* 释放设备列表 */
    pcap_freealldevs(alldevs);
    
    /* 开始捕捉 */
    pcap_loop(adhandle, 0, packet_handler, NULL);
    
    return 0;
}

/* 回调函数，当收到每一个数据包时会被libpcap所调用 */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    struct tm *ltime;
    char timestr[16];
    mac_header *mh;
    ip_header *ih;
    udp_header *uh;
    arp_header *ah;
    u_int ip_len;
    u_short sport,dport;
    time_t local_tv_sec;
    
    /* 将时间戳转换成可识别的格式 */
    local_tv_sec = header->ts.tv_sec;
    ltime=localtime(&local_tv_sec);
    strftime( timestr, sizeof timestr, "%H:%M:%S", ltime);
    
    printf("\n%s,%.6d len:%d\n", timestr, header->ts.tv_usec, header->len);
    
    /* 打印数据包完整信息 */
	for (int i=0;i<header->len;i++) {
		printf("  %02x", *(pkt_data+i));
		if ((i+1)%16==0) printf("\n");
	}
	printf("\n");
	
	/* 获得MAC头部的位置 */
	mh = (mac_header *)pkt_data;
	
	/* 打印MAC头部信息 */
	printf("目的地址：%02x", mh->mac_dhost[0]);
	putmacaddr(mh->mac_dhost);
	printf("源地址：%02x", mh->mac_shost[0]);
	putmacaddr(mh->mac_shost);
	string mac_type = gettype(mh->mac_type);
	cout<<"类型："<<mac_type<<endl; 
	
	if (mac_type=="IP") {
		/* 获得IP数据包头部的位置 */
	    ih = (ip_header *) (pkt_data + ETH_HLEN); //以太网头部长度
		
		/* 获得UDP首部的位置 */
	    ip_len = (ih->ver_ihl & 0xf) * 4;
	    uh = (udp_header *) ((u_char*)ih + ip_len);
	    
//	    /* 将网络字节序列转换成主机字节序列 */
//	    sport = ntohs( uh->sport );
//	    dport = ntohs( uh->dport );
	
		/* 打印IP地址和UDP端口 */
	    printf("%d.%d.%d.%d:%d -> %d.%d.%d.%d:%d\n",
	        ih->saddr.byte1,
	        ih->saddr.byte2,
	        ih->saddr.byte3,
	        ih->saddr.byte4,
	        uh->sport,
	        ih->daddr.byte1,
	        ih->daddr.byte2,
	        ih->daddr.byte3,
	        ih->daddr.byte4,
	        uh->dport);
	} else if (mac_type=="ARP") {
		ah =  (arp_header *)(pkt_data + ETH_HLEN); //以太网头部长度
		if (ah->arp_op==ARP_REQUEST) {
			int reqid;
			if ((reqid=judgeczreq(ah->arp_sha,ah->sip))==-1) {
				for (int i=0;i<ETH_ALEN;i++)
					atkcheck.request[atkcheck.request_num].arp_reqaddr[i] = ah->arp_sha[i];
				atkcheck.request[atkcheck.request_num].reqip = ah->sip;
				atkcheck.request_num++;
			}
		}
		if (ah->arp_op==ARP_RESPONSE) {
			int reqid;
			if ((reqid=judgeczreq(ah->arp_tha,ah->tip))!=-1) {
				int resid;
				if ((resid=judgeczres(atkcheck.request[reqid],ah->arp_sha,ah->sip))==-1) {
					for (int i=0;i<ETH_ALEN;i++)
						atkcheck.request[reqid].response[atkcheck.request[reqid].response_num].arp_resaddr[i] = ah->arp_sha[i];
					atkcheck.request[reqid].response[atkcheck.request[reqid].response_num].resip = ah->sip;
					atkcheck.request[reqid].response_num++;
				}
				if (atkcheck.request[reqid].response_num>=2) {
					printf("源地址为：%02x", atkcheck.request[reqid].arp_reqaddr[0]);
					putmacaddr(atkcheck.request[reqid].arp_reqaddr);
					printf("\b正在遭受ARP攻击！\n");
					cin.get();
					cin.get();
				}
			}
		}
		
		printf("硬件类型：%02x%02x\n", ah->arp_hrd[0], ah->arp_hrd[1]); 
		string mac_type = gettype(ah->arp_pro);
		cout<<"协议类型："<<mac_type<<endl;
		printf("硬件地址长度：%d\n", ah->arp_hln);
		printf("协议地址长度：%d\n", ah->arp_pln);
		string arp_way = getway(ah->arp_op);
		cout<<"操作方式："<<arp_way<<endl;
		printf("源MAC地址：%02x", ah->arp_sha[0]);
		putmacaddr(ah->arp_sha);
		printf("源IP地址：%d.%d.%d.%d\n", 
			ah->sip.byte1, 
			ah->sip.byte2, 
			ah->sip.byte3, 
			ah->sip.byte4);
		printf("目的MAC地址：%02x", ah->arp_tha[0]);
		putmacaddr(ah->arp_tha);
		printf("目的IP地址：%d.%d.%d.%d\n", 
			ah->tip.byte1, 
			ah->tip.byte2, 
			ah->tip.byte3, 
			ah->tip.byte4);
	} else if (mac_type=="RARP") {
		
	} else {
		
	}
//	cin.get();
}

void putmacaddr(u_int8_t macaddr[]) {
	for (int i=1;i<ETH_ALEN;i++) 
		printf("-%02x", macaddr[i]);
	printf("\n");
}

string gettype(u_int16_t protype) {
	string mac_type = "";
	switch(protype)
	{
		case ETHERTYPE_IP: mac_type="IP";break;
		case ETHERTYPE_ARP: mac_type="ARP";break;
		case ETHERTYPE_REVARP: mac_type="RARP";break;
		default : mac_type="other";break;
	}
	return mac_type;
}

string getway(u_int16_t arpway) {
	string arp_way = "";
	switch(arpway)
	{
		case ARP_REQUEST: arp_way="ARP请求";break;
		case ARP_RESPONSE: arp_way="ARP应答";break;
		case RARP_REQUEST: arp_way="RARP请求";break;
		case RARP_RESPONSE: arp_way="RARP应答";break;
		default : arp_way="other";break;
	}
	return arp_way;
	
} 

bool judgeeqaddr(u_int8_t addr1[], u_int8_t addr2[]) {
	for (int i=0;i<ETH_ALEN;i++) {
		if (addr1[i]!=addr2[i]) return false; 
	}
	return true;
}

bool judgeeqip(ip_address ip1, ip_address ip2) {
	return (ip1.byte1==ip2.byte1&&
			ip1.byte2==ip2.byte2&&
			ip1.byte3==ip2.byte3&&
			ip1.byte4==ip2.byte4) ? true:false;
}

int judgeczreq(u_int8_t reqaddr[], ip_address reqip){
	for (int i=0;i<=atkcheck.request_num;i++) {
		if (judgeeqaddr(atkcheck.request[i].arp_reqaddr,reqaddr)&&judgeeqip(atkcheck.request[i].reqip,reqip)) {
			return i;
		}
	}
	return -1;
}

int judgeczres(arp_request request, u_int8_t resaddr[], ip_address resip) {
	for (int i=0;i<=request.response_num;i++) {
		if (judgeeqaddr(request.response[i].arp_resaddr,resaddr)&&judgeeqip(request.response[i].resip,resip)) {
			return i;
		}
	}
	return -1;
}
