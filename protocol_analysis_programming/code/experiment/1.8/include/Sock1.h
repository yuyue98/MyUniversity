#ifndef SOCK_H
#define SOCK_H

#include <windows.h>  
#include <stdio.h>  
#include <stdlib.h>
#include <iostream>  
#include <string>
#include <stdexcept>

using namespace std;  

#pragma comment(lib, "Ws2_32.lib") 

#define BUFSIZE (8*BUFSIZ)

class Sock
{
	public:
		Sock();
		bool Connect(const string& host_id,const int port);
		void send_socket(const string s);
		void send_socket(const char* s,const int l);
        int recv_socket();
        const string get_recvbuf();
        const char* get_recvbuf_char();
        void putBuf();
        ~Sock();
    private:
        char recvbuf[BUFSIZE];
        struct hostent *hp;
        struct sockaddr_in server;
        int ret;
	    WORD myRequest;
	    WSADATA mywsa;
        SOCKET sock;
        static const int timeout;
	protected:
};

#endif
