#include "Sock1.h"

const int Sock::timeout = 3000;

Sock::Sock() {
	//int ret;
    //SOCKET sock;
    //WSADATA mywsa;
    //WORD myRequest;
    //struct sockaddr_in server;
    //struct hostent *hp;
    //char recvbuf[BUFSIZE];
	cout<<this<<": Sock start!"<<endl;
	hp = NULL;
    memset(&server,0,sizeof(server));
    ret = 0;
    /* 初始化 Socket dll */
    myRequest = WSAStartup(MAKEWORD(2,2),&mywsa);
	if (myRequest!=0) {
		throw runtime_error("找不到可使用的 WinSock dll!");
	}
	/* 创建Socket */ 
	sock = socket(AF_INET,SOCK_STREAM,0);
	if (SOCKET_ERROR==sock) {
		throw runtime_error("socket 初始化失败!");
	}
	/* 设置超时连接 */
	ret =  setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
	ret =  setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
}

Sock::~Sock() {
	cout<<this<<": Sock end!"<<endl;
	closesocket(sock);
	WSACleanup();
}

bool Sock::Connect(const string& host_id, const int port) {
	server.sin_family = AF_INET;
	hp = gethostbyname(host_id.c_str());
	if ((hp==(struct hostent*)0)) {
		cerr<<"服务器地址获取失败!"<<endl;
		return false; 
	}
	
	memcpy((char*)&server.sin_addr,(char*)hp->h_addr,hp->h_length);
	//cout<<"name: "<<hp->h_name<<endl;
	//cout<<"addrtype: "<<hp->h_addrtype<<endl;
	//cout<<"length: "<<hp->h_length<<endl;
	cout<<"server.addr: "<<inet_ntoa(server.sin_addr)<<endl;
	server.sin_port = htons(port);
	if (SOCKET_ERROR==connect(sock,(sockaddr*)&server,sizeof(server))) {
		cerr<<"连接服务器失败!"<<endl;
		return false;
	} else {
		return true;
	}
}

void Sock::send_socket(const string s) {
	send(sock,s.c_str(),strlen(s.c_str()),0);
}

void Sock::send_socket(const char* s,const int l) {
	send(sock,s,l,0);
}

int Sock::recv_socket() {
    memset(recvbuf,0,BUFSIZE);
    return recv(sock,recvbuf,BUFSIZE,0);
}

const string Sock::get_recvbuf() {
	return recvbuf;
}

const char* Sock::get_recvbuf_char() {
	return recvbuf;
}

void Sock::putBuf() {
	for (int i=0;i<BUFSIZE;i++) {
		printf(" %02x",recvbuf[i]);
		if ((i+1)%32==0) cout<<endl;
	}
}
