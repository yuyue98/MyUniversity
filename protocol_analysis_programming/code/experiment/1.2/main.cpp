#include <windows.h>
#include <iostream>
#include <string>
#define HAVE_REMOTE
#include <pcap.h>
#define WIN32
#ifndef WIN32
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <unistd.h>
#else
    #include <winsock.h>
    #include <winsock2.h>
    #include <ws2tcpip.h>
#endif
#pragma comment(lib,"ws2_32.lib")

using namespace std;

char *iptos(u_long in);

int main(int argc, char** argv) {
    pcap_if_t *alldevs;
    pcap_if_t *d;
    pcap_addr_t *a;
    char ip6str[128];
    int i=0;
    char errbuf[PCAP_ERRBUF_SIZE+1];
    char source[PCAP_ERRBUF_SIZE+1];
    printf("Enter the device you want to list:\n"
            "rpcap://              ==> lists interfaces in the local machine\n"
            "rpcap://hostname:port ==> lists interfaces in a remote machine\n"
            "                          (rpcapd daemon must be up and running\n"
            "                           and it must accept 'null' authentication)\n"
            "file://foldername     ==> lists all pcap files in the give folder\n\n"
            "Enter your choice: ");

    fgets(source, PCAP_ERRBUF_SIZE, stdin);
    source[PCAP_ERRBUF_SIZE] = '\0';
    /* 获取本地机器设备列表 */
    if (pcap_findalldevs_ex(source, NULL /* auth is not needed */, &alldevs, errbuf) == -1) {
        fprintf(stderr,"Error in pcap_findalldevs_ex: %s\n", errbuf);
        exit(1);
    }

    /* 打印列表 */
    for(d= alldevs; d != NULL; d= d->next) {
        /* 设备名(Name) */
        printf("%d. %s\n", ++i, d->name);
        /* 设备描述(Description) */
        if (d->description)
            printf("\t(%s)\n", d->description);
        else
            printf("\t(No description available)\n");
        /* Loopback Address*/
        printf("\tLoopback: %s\n",(d->flags & PCAP_IF_LOOPBACK)?"yes":"no");
        /* IP addresses */
        for(a=d->addresses;a;a=a->next) {
            printf("\tAddress Family: #%d\n",a->addr->sa_family);
            switch(a->addr->sa_family)
            {
                case AF_INET:
                    printf("\tAddress Family Name: AF_INET\n");
                    if (a->addr)
                        printf("\tAddress: %s\n",iptos(((struct sockaddr_in *)a->addr)->sin_addr.s_addr));
                    if (a->netmask)
                        printf("\tNetmask: %s\n",iptos(((struct sockaddr_in *)a->netmask)->sin_addr.s_addr));
                    if (a->broadaddr)
                        printf("\tBroadcast Address: %s\n",iptos(((struct sockaddr_in *)a->broadaddr)->sin_addr.s_addr));
                    if (a->dstaddr)
                        printf("\tDestination Address: %s\n",iptos(((struct sockaddr_in *)a->dstaddr)->sin_addr.s_addr));
                    break;
                case AF_INET6:
                    printf("\tAddress Family Name: AF_INET6\n");
                    break;
                default:
                    printf("\tAddress Family Name: Unknown\n");
                    break;
            }
        }
    }

    if (i == 0) {
        printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
        return 0;
    }

    /* 不再需要设备列表了，释放它 */
    pcap_freealldevs(alldevs);
    return 0;
}

/* 将数字类型的IP地址转换成字符串类型的 */
#define IPTOSBUFFERS    12
char *iptos(u_long in) {
    static char output[IPTOSBUFFERS][3*4+3+1];
    static short which;
    u_char *p;

    p = (u_char *)&in;
    which = (which + 1 == IPTOSBUFFERS ? 0 : which + 1);
    sprintf(output[which], "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
    return output[which];
}