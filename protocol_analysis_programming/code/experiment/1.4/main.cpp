#include<iostream>
#include<string>
#include <stdlib.h>
#include <stdio.h>
#define _WSPIAPI_COUNTOF
#define HAVE_REMOTE
#include <winsock2.h>
#include "pcap.h"
#pragma comment(lib, "wpcap.lib")
#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "ws2_32.lib")

using namespace std;

// 短整型大小端互换
#define BigLittleSwap16(A)  ((((u_short)(A) & 0xff00) >> 8) | \
                            (((u_short)(A) & 0x00ff) << 8))
 // 长整型大小端互换
#define BigLittleSwap32(A)  ((((u_long)(A) & 0xff000000) >> 24) | \
                            (((u_long)(A) & 0x00ff0000) >> 8) | \
                            (((u_long)(A) & 0x0000ff00) << 8) | \
                            (((u_long)(A) & 0x000000ff) << 24))

/* 4字节的IP地址 */
typedef struct ip_address{
    u_char byte1;
    u_char byte2;
    u_char byte3;
    u_char byte4;
}ip_address;

/* 16字节的IP地址 */
typedef struct ipv6_address{
    u_short dbyte1;
    u_short dbyte2;
    u_short dbyte3;
    u_short dbyte4;
    u_short dbyte5;
    u_short dbyte6;
    u_short dbyte7;
    u_short dbyte8;
}ipv6_address;

#define ETH_ALEN       6    // 以太网地址大小
#define ETH_HLEN       14   // 以太网头部大小
#define ETH_DATA_LEN   1500 // 最大帧负载数据大小
#define ETH_FRAME_LEN  1514 // 最大帧大小，头部+负载数据
#define ETHERTYPE_IPV4   0x0800 // IPv4数据包
#define ETHERTYPE_IPV6   0x86dd // IPv6数据包
#define ETHERTYPE_ARP    0x0806 // ARP请求应答
#define ETHERTYPE_REVARP 0x0835 // RARP请求应答
typedef struct mac_header{
	u_int8_t mac_dhost[ETH_ALEN]; // 目的MAC地址 
	u_int8_t mac_shost[ETH_ALEN]; // 源MAC地址 
	u_int16_t mac_type;           // 帧类型 
}mac_header;


#define ETHERTYPE_TCP       0x06 // TCP数据包 
#define ETHERTYPE_UDP       0x11 // UDP数据包
#define ETHERTYPE_ICMPV6    0x3a // ICMPv6数据包 
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

string ToS_2[8] = {
	"Routine-普通",
	"Priority-优先",
	"Immediate-快速",
	"Flash-闪速",
	"Flash Override-极速",
	"Critic-关键",
	"Internetwork Control-网间控制",
	"Network Control-网络控制"
};

string ToS_6[5] = {
	"Normal Service-普通服务",
	"Minimize Delay-最小延迟",
	"Maximize Throughput-最大吞吐量",
	"Maximize Reliability-最大可靠性",
	"Minimize Monetary Cost-最小成本"
};

/* UDP 首部*/
typedef struct udp_header{
    u_short sport;          // 源端口(Source port)
    u_short dport;          // 目的端口(Destination port)
    u_short len;            // UDP数据包长度(Datagram length)
    u_short crc;            // 校验和(Checksum)
}udp_header;


/* TCP 首部*/
typedef struct tcp_header{
    u_short sport;          // 源端口(Source port)
    u_short dport;          // 目的端口(Destination port)
    u_long sNo;             // 序号
	u_long aNo;             // 确认序号
	u_char hLen;            // 首部长度
	u_char flag;            // 标识
	u_short window;         // 窗口大小
	u_short chksum;         // 校验和
	u_short urgptr;         // 紧急指针 
}tcp_header;

#define IPV6_ALEN             16   // IPv6地址大小
#define IPV6_HLEN             40   // IPv6头部大小
/* IPv6 首部*/
typedef struct ipv6_header{
	u_char ver_tf;                // 版本号（4 bit）
	u_char traffic;               // 优先级（8 bit）
	u_short label;                // 流标识（20 bit）
	u_short length;               // 报文长度（16 bit）
	u_char next_header;           // 下一头部（8 bit）
	u_char limits;                // 跳数限制（8 bit）
	ipv6_address sipv6;           // 源IPv6地址（128 bit）
	ipv6_address dipv6;           // 目的IPv6地址（128 bit）
}ipv6_header;

#define ICMPV6_DHLEN             8   // ICMPv6信息报文头部大小
#define ICMPV6_NHLEN             4   // ICMPv6差错报文头部大小
/* ICMPv6 首部 */
typedef struct icmpv6_header{
	u_char type;             // 类型
	u_char code;             // 代码
	u_short crc;             // 校验和
	u_short identifier;      // 标识
	u_short sequence;        // 片段序列 
}icmpv6_header; 

#define ARP_REQUEST  0x0001 // ARP请求
#define ARP_RESPONSE   0x0002 // ARP应答
#define RARP_REQUEST 0x0003 // RARP请求
#define RARP_RESPONSE  0x0004 // RARP应答
/* ARP 首部*/
typedef struct arp_header{
	u_int16_t arp_hrd;          // 硬件类型 
	u_int16_t arp_pro;          // 协议类型
	u_int8_t arp_hln;           // 硬件地址长度
	u_int8_t arp_pln;           // 协议地址长度
	u_int16_t arp_op;           // ARP命令 1（ARP请求）2（ARP应答）3（RARP请求）4（RARP应答）
	u_int8_t arp_sha[ETH_ALEN]; // 源MAC地址 
    ip_address  sip;            // 源地址(Source address)
	u_int8_t arp_tha[ETH_ALEN]; // 目的端MAC地址 
    ip_address  tip;            // 目的地址(Destination address)	
}arp_header;

/* 回调函数原型 */
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);
// 本机大端返回1，小端返回0
int checkCPUendian();
// 模拟htonl函数，本机字节序转网络字节序
unsigned long int t_htonl(unsigned long int h);
// 模拟ntohl函数，网络字节序转本机字节序
unsigned long int t_ntohl(unsigned long int n);
// 模拟htons函数，本机字节序转网络字节序
unsigned short int t_htons(unsigned short int h);
// 模拟ntohs函数，网络字节序转本机字节序
unsigned short int t_ntohs(unsigned short int n);
// 打印mac地址 
void putmacaddr(u_int8_t macaddr[]);
// 获取帧类型 
string gettype(u_int16_t protype); 
// 获取协议类型
string getpro(u_int8_t protype); 
// 通用校验函数
unsigned short int check_cksum(unsigned short int *Buffer, int Bytes); 

int main()
{
	pcap_if_t *alldevs;
	pcap_if_t *d;
	int inum;
	int i=0;
	pcap_t *adhandle;
	char errbuf[PCAP_ERRBUF_SIZE];
	u_int netmask;
	char packet_filter[] = "";
	struct bpf_program fcode;

    /* 获得设备列表 */
    if (pcap_findalldevs_ex((char *)PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1) {
        fprintf(stderr,"Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }
    
    /* 打印列表 */
    for(d=alldevs; d; d=d->next) {
        printf("%d. %s", ++i, d->name);
        if (d->description)
            printf(" (%s)\n", d->description);
        else
            printf(" (No description available)\n");
    }

    if(i==0) {
        printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
        return -1;
    }
    
    printf("Enter the interface number (1-%d):",i);
    scanf("%d", &inum);
    
    if(inum < 1 || inum > i) {
        printf("\nInterface number out of range.\n");
        /* 释放设备列表 */
        pcap_freealldevs(alldevs);
        return -1;
    }

    /* 跳转到已选设备 */
    for(d=alldevs, i=0; i< inum-1 ;d=d->next, i++);
    
    /* 打开适配器 */
    if ( (adhandle= pcap_open(d->name,  // 设备名
                             65536,     // 要捕捉的数据包的部分 
                                        // 65535保证能捕获到不同数据链路层上的每个数据包的全部内容
                             PCAP_OPENFLAG_PROMISCUOUS,         // 混杂模式
                             1000,      // 读取超时时间
                             NULL,      // 远程机器验证
                             errbuf     // 错误缓冲池
                             ) ) == NULL)
	{
        fprintf(stderr,"\nUnable to open the adapter. %s is not supported by WinPcap\n");
        /* 释放设备列表 */
        pcap_freealldevs(alldevs);
        return -1;
    }
    
    /* 检查数据链路层，为了简单，我们只考虑以太网 */
    if(pcap_datalink(adhandle) != DLT_EN10MB) {
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
    if (pcap_compile(adhandle, &fcode, packet_filter, 1, netmask) <0 ) {
        fprintf(stderr,"\nUnable to compile the packet filter. Check the syntax.\n");
        /* 释放设备列表 */
        pcap_freealldevs(alldevs);
        return -1;
    }
    
    //设置过滤器
    if (pcap_setfilter(adhandle, &fcode)<0) {
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
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    struct tm *ltime;
    char timestr[16];
    mac_header *mh;
    ip_header *ih;
    udp_header *uh;
    tcp_header *th;
    ipv6_header *i6h;
    icmpv6_header *icmpv6h; 
    arp_header *ah;
    u_int ip_ver; 
    u_int ip_len;
    u_short sport,dport;
    time_t local_tv_sec;
    u_char flag;
    u_short checksum_self = 0xffff;
    u_long label;
    
    
    /* 将时间戳转换成可识别的格式 */
    local_tv_sec = header->ts.tv_sec;
    ltime=localtime(&local_tv_sec);
    strftime( timestr, sizeof timestr, "%H:%M:%S", ltime);
	/* 打印数据包的时间戳和长度 */
	printf("%s.%.6d len:%d ", timestr, header->ts.tv_usec, header->len);
	/* 打印数据包完整信息 */
    printf("The data is: \n");
	for (int i=0;i<header->len;i++) {
		printf("  %02x", *(pkt_data+i));
		if ((i+1)%16==0) printf("\n");
	}
	printf("\n");
	
	
	/* 获得MAC头部的位置 */
	mh = (mac_header *)pkt_data;
	printf("The MAC Header is:\n");
	printf("目的地址: ");
	putmacaddr(mh->mac_dhost);
	printf("源地址: ");
	putmacaddr(mh->mac_shost);
	string mac_type = gettype(mh->mac_type);
	if (mac_type=="IPv4") {
	    /* 获得IP数据包头部的位置 */
	    ih = (ip_header *) (pkt_data + ETH_HLEN); //以太网头部长度
		printf("The IPv4 Header is:\n");
		/* 获得当前IP数据包版本和首部长度 */
	    ip_len = (ih->ver_ihl & 0xf) * 4;
	    printf("版本: %s ",(ih->ver_ihl / 16)==4?"IPv4":"IPv6");
	    printf("首部长度: %dByte\n", ip_len);
		checksum_self = check_cksum((u_short*)ih,ip_len);
		if (checksum_self) {
			printf("校验和: %04x 该IP数据包接受错误！\n", checksum_self);
			return ;
		}
		/* 获得当前服务类型和IP数据包总长度 */
		if (!(ih->tos & 0x01)) {
			printf("优先级: %s ",ToS_2[(ih->tos)>>5].c_str());
			u_char fwsz = (ih->tos & 0x1f)>>1;
			int i = 0;
			while (fwsz) {
				fwsz = fwsz>>1;
				i++;
			}
			printf("服务类型: %s\n", ToS_6[i].c_str());
		} else {
			printf("当前ToS字段有误！\n");
		}
		printf("IP数据包总长度: %d ", t_ntohs(ih->tlen)); 
		/* 获取标识和分片信息 */
		printf("IP数据包标识: %d\n", t_ntohs(ih->identification));
		if (!((ih->flags_fo)>>15)) {
			if (!(ih->flags_fo & 0x40)) {
				printf("该IP数据包可以分片,");
				if (!(ih->flags_fo & 0x20)) {
					printf("且为最后一个分片的包,"); 
				} else {
					printf("且为分片中段的包,"); 
				}
				if (!(ih->flags_fo & 0x1f)) {
					printf("此为该IP数据包第一个分片！\n");
				} else {
					printf("片偏移: %d\n",ih->flags_fo & 0x1f);
				}
			} else {
				printf("该IP数据包不能分片！\n");
			} 
		} else {
			printf("当前分片信息有误！\n");
		}
		/* 该IP数据包生存时间以及包含协议类型 */
		printf("生存时间: %dHop ", ih->ttl);
		string ip_type = getpro(ih->proto);
		if (ip_type=="UDP") {
			/* 获得UDP首部的位置 */
		    uh = (udp_header *) ((u_char*)ih + ip_len);
			printf("The UDP Header is:\n");
			
		    /* 打印IP地址和UDP端口 */
		    printf("%d.%d.%d.%d.%d -> %d.%d.%d.%d.%d\n",
		        ih->saddr.byte1,
		        ih->saddr.byte2,
		        ih->saddr.byte3,
		        ih->saddr.byte4,
		        t_ntohs(uh->sport),
		        ih->daddr.byte1,
		        ih->daddr.byte2,
		        ih->daddr.byte3,
		        ih->daddr.byte4,
		        t_ntohs(uh->dport));
		} else if (ip_type=="TCP") {
			/* 获得TCP首部的位置 */
		    th = (tcp_header *) ((u_char*)ih + ip_len);
			printf("The TCP Header is:\n");
			
		    /* 打印IP地址和TCP端口 */
		    printf("%d.%d.%d.%d.%d -> %d.%d.%d.%d.%d\n",
		        ih->saddr.byte1,
		        ih->saddr.byte2,
		        ih->saddr.byte3,
		        ih->saddr.byte4,
		        t_ntohs(th->sport),
		        ih->daddr.byte1,
		        ih->daddr.byte2,
		        ih->daddr.byte3,
		        ih->daddr.byte4,
		        t_ntohs(th->dport));
		} else {
			printf("The OTHER Header is:\n");
		}
	    
	} else if (mac_type=="IPv6") {
		/* 获得IP数据包头部的位置 */
	    i6h = (ipv6_header *) (pkt_data + ETH_HLEN); //以太网头部长度
		printf("The IPv6 Header is:\n");
		/* 获得当前IP数据包版本和优先级*/
	    printf("版本: %s ",(i6h->ver_tf / 16)==4?"IPv4":"IPv6");
	    flag = i6h->ver_tf % 16;
	    flag = (flag<<4)+(i6h->traffic/16);
		if (!(flag & 0x01)) {
			printf("优先级: %s ",ToS_2[(flag)>>5].c_str());
			u_char fwsz = (flag & 0x1f)>>1;
			int i = 0;
			while (fwsz) {
				fwsz = fwsz>>1;
				i++;
			}
			printf("服务类型: %s\n", ToS_6[i].c_str());
		} else {
			printf("当前通讯分类字段有误！\n");
		}
		/* 获得当前IP数据包流标签和有效载荷长度*/
		label = i6h->traffic%16;
		label = (label<<16)+t_ntohs(i6h->label);
		printf("流标签: %05x ", label); 
		printf("有效载荷长度: %d\n", t_ntohs(i6h->length)); 
		/* 获得当前IP数据包下一个头部和跳数限制 */ 
		string ip_type = getpro(i6h->next_header);
		printf("跳数限制: %dHop\n", i6h->limits);
		/* 打印IPv6地址 */
	    printf("%04x:%04x:%04x:%04x:%04x:%04x:%04x:%04x -> %04x:%04x:%04x:%04x:%04x:%04x:%04x:%04x\n",
	        t_ntohs(i6h->sipv6.dbyte1),
	        t_ntohs(i6h->sipv6.dbyte2),
	        t_ntohs(i6h->sipv6.dbyte3),
	        t_ntohs(i6h->sipv6.dbyte4),
	        t_ntohs(i6h->sipv6.dbyte5),
	        t_ntohs(i6h->sipv6.dbyte6),
	        t_ntohs(i6h->sipv6.dbyte7),
	        t_ntohs(i6h->sipv6.dbyte8),
	        t_ntohs(i6h->dipv6.dbyte1),
	        t_ntohs(i6h->dipv6.dbyte2),
	        t_ntohs(i6h->dipv6.dbyte3),
	        t_ntohs(i6h->dipv6.dbyte4),
	        t_ntohs(i6h->dipv6.dbyte5),
	        t_ntohs(i6h->dipv6.dbyte6),
	        t_ntohs(i6h->dipv6.dbyte7),
	        t_ntohs(i6h->dipv6.dbyte8));
	    if (ip_type=="ICMPv6") {
		    icmpv6h = (icmpv6_header *) ((u_char*)i6h + IPV6_HLEN);
			printf("The ICMPv6 Header is:\n");
		    /* 获取ICMPV6数据包类型以及其含义 */
	    	if (icmpv6h->type & 0x80) {
	    		printf("此为ICMPv6信息报文！\n");
	    		printf("其中数据信息如下: \n");
	    		u_char* ch = (u_char*)icmpv6h+ICMPV6_DHLEN;
	    		for (int i = t_ntohs(i6h->length)-ICMPV6_DHLEN;i>0;i--,ch++) {
	    			printf("%c ", *ch);
					if ((t_ntohs(i6h->length)-ICMPV6_DHLEN-i+1)%16==0) printf("\n");
				}
				if (t_ntohs(i6h->length)%16!=0) printf("\n");
			} else {
				printf("此为ICMPv6差错报文！\n");
	    		printf("其中差错信息如下: \n");
				if (icmpv6h->type==1) {
					printf("目的不可达--");
					if (icmpv6h->code==0) {
						printf("没有到达目标路由！\n");
					} else if (icmpv6h->code==1) {
						printf("与目标的通讯被管理员策略禁止！\n");
					} else if (icmpv6h->code==2) {
						printf("未指定！\n");
					} else if (icmpv6h->code==3) {
						printf("地址不可达！\n");
					} else if (icmpv6h->code==4) {
						printf("端口不可达！\n");
					} else if (icmpv6h->code==5) {
						printf("源地址进入/退出策略失败！\n");
					} else if (icmpv6h->code==6) {
						printf("到目的地的路线被拒绝！\n");
					} else if (icmpv6h->code==7) {
						printf("源路由头出错！\n");
					} else {
						printf("其他原因！\n");
					}
				} else if (icmpv6h->type==2) {
					printf("数据包超长--");
					if (icmpv6h->code==0) {
						printf("无！\n");
					} else {
						printf("其他原因！\n");
					}
				} else if (icmpv6h->type==3) {
					printf("超时--");
					if (icmpv6h->code==0) {
						printf("在传输中超越了跳数限制！\n");
					} else if (icmpv6h->code==4) {
						printf("分片重组超时！\n");
					} else {
						printf("其他原因！\n");
					} 
				} else if (icmpv6h->type==4) {
					printf("参数问题--");
					if (icmpv6h->code==0) {
						printf("遇到错误的报头字段！\n");
					} else if (icmpv6h->code==3) {
						printf("遇到无法识别的下一个报头类型！\n");
					} else if (icmpv6h->code==4) {
						printf("遇到无法识别的IPv6选项！\n");
					} else {
						printf("其他原因！\n");
					}
				} else {
					printf("其他差错！\n");
				}
			}
		} else {
			printf("The OTHER Header is:\n");
		}
	} else if (mac_type=="ARP") {
		printf("The ARP Header is:\n");
	} else if (mac_type=="RARP") {
		printf("The RARP Header is:\n");
	} else {
		printf("The OTHER Header is:\n");
	}
    getchar();
}

int checkCPUendian() {
       union{
              unsigned long int i;
              unsigned char s[4];
       }c;
       c.i = 0x12345678;
       return (0x12 == c.s[0]);
}

unsigned long int t_htonl(unsigned long int h) {
       // 若本机为大端，与网络字节序同，直接返回
       // 若本机为小端，转换成大端再返回
       return checkCPUendian() ? h : BigLittleSwap32(h);
}

unsigned long int t_ntohl(unsigned long int n)
{
       // 若本机为大端，与网络字节序同，直接返回
       // 若本机为小端，网络数据转换成小端再返回
       return checkCPUendian() ? n : BigLittleSwap32(n);
}

unsigned short int t_htons(unsigned short int h) {
       // 若本机为大端，与网络字节序同，直接返回
       // 若本机为小端，转换成大端再返回
       return checkCPUendian() ? h : BigLittleSwap16(h);
}

unsigned short int t_ntohs(unsigned short int n) {
       // 若本机为大端，与网络字节序同，直接返回
       // 若本机为小端，网络数据转换成小端再返回
       return checkCPUendian() ? n : BigLittleSwap16(n);
}

void putmacaddr(u_int8_t macaddr[]) {
	printf("%02x", macaddr[0]);
	for (int i=1;i<ETH_ALEN;i++) 
		printf(":%02x", macaddr[i]);
	printf("\n");
}

string gettype(u_int16_t protype) {
	string mac_type;
	protype = t_ntohs(protype);
	switch(protype)
	{
		case ETHERTYPE_IPV4: mac_type="IPv4";break;
		case ETHERTYPE_IPV6: mac_type="IPv6";break;
		case ETHERTYPE_ARP: mac_type="ARP";break;
		case ETHERTYPE_REVARP: mac_type="RARP";break;
		default : mac_type="OTHER";break;
	}
	printf("帧类型: %s\n", mac_type.c_str());
	return mac_type;
}

string getpro(u_int8_t protype) {
	string ip_type;
	switch(protype)
	{
		case ETHERTYPE_UDP: ip_type="UDP";break;
		case ETHERTYPE_TCP: ip_type="TCP";break;
		case ETHERTYPE_ICMPV6: ip_type="ICMPv6";break;
		default : ip_type="OTHER";break;
	}
	printf("协议类型: %s\n", ip_type.c_str());
	return ip_type;
}

unsigned short int check_cksum(unsigned short int *Buffer, int Bytes) {
	u_long cksum = 0;
	while (Bytes>1) {
		cksum += *Buffer++;
		Bytes -= 2;
	}
	if (Bytes==1) {
		cksum += *(u_short *)Buffer;
	}
	cksum = (cksum>>16)+(cksum&0xffff);
	cksum += (cksum>>16);
	return (u_short)~cksum;
}
