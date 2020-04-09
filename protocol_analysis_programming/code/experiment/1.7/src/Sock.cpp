#include "Sock.h"

Sock::Sock() {
	hp = NULL;
    memset(&server,0,sizeof(server));
    num = 0;
    myRequest = WSAStartup(MAKEWORD(2,2),&mywsa);
	if (myRequest!=0) {
		throw runtime_error("找不到可使用的 WinSock dll!");
	}
	sock = socket(AF_INET,SOCK_STREAM,0);
	if (sock==-1) {
		throw runtime_error("socket 初始化失败!");
	}
}

Sock::~Sock() {
	closesocket(sock);
	WSACleanup();
}

bool Sock::Connect(const string host_id, const int &port) {
	server.sin_family = AF_INET;
	hp = gethostbyname(host_id.c_str());
	if ((hp==(struct hostent*)0)) {
		cerr<<"服务器地址获取失败!"<<endl;
		return false; 
	}
	
	memcpy((char*)&server.sin_addr,(char*)hp->h_addr,hp->h_length);
	cout<<"server.addr: "<<inet_ntoa(server.sin_addr)<<endl;
	server.sin_port = htons(port);
	if (connect(sock,(sockaddr*)&server,sizeof(server))==-1) {
		cerr<<"连接服务器失败!"<<endl;
		return false;
	} else {
		return true;
	}
}

void Sock::send_socket(const string s) {
	send(sock,s.c_str(),strlen(s.c_str()),0);
}

int Sock::recv_socket() {
    memset(recvbuf,0,BUFSIZ);
    return recv(sock,recvbuf,BUFSIZ,0);
}

const string Sock::get_recvbuf() {
	return recvbuf;
}
