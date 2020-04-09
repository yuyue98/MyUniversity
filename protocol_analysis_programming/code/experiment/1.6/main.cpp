#include <iostream>
#include <winsock2.h>
#include <string>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

int my_scan(string IP="127.0.0.1",int StartPort=0,int EndPort=65535) {
	WORD myRequest;
	WSADATA mywsa;
	SOCKET s;
	struct sockaddr_in server;
	int ret;
	int num = 0;
	myRequest = WSAStartup(MAKEWORD(2,2),&mywsa);
	if (myRequest!=0) {
		cout<<"找不到可使用的WinSock dll!"<<endl;
		return -1;
	}
	if (StartPort<0||StartPort>EndPort||EndPort>65535) {
		cout<<"需扫描的端口号输入有误!"<<endl; 
		return 0;
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(IP.c_str());
	for (int CurrPort=StartPort;CurrPort<=EndPort;CurrPort++) {
		memset(&(server.sin_zero),0,sizeof(server.sin_zero));
		s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
		server.sin_port = htons(CurrPort);
		ret = connect(s,(struct sockaddr*)&server,sizeof(server));
		if (0==ret) {
			cout<<IP<<":"<<CurrPort<<" Success O(∩_∩)O~~"<<endl;
			num++;
		} else {
			cout<<IP<<":"<<CurrPort<<" Failed"<<endl;
		}
		closesocket(s);
	}
	cout<<"Success Port num is "<<num<<endl;
	WSACleanup();
	return 1;
	
} 

int main(int argc, char** argv) {
	string IP;
	int StartPort, EndPort;
	while (true) {
		cout<<"Please input the IP:";
		cin>>IP;
		cout<<"Please input the StartPort:";
		cin>>StartPort;
		cout<<"Please input the EndPort:";
		cin>>EndPort;
		my_scan(IP,StartPort,EndPort);
	}
	return 0;
}
