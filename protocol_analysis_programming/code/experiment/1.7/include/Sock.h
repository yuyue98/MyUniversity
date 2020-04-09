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

class Sock
{
	public:
		Sock();
		bool Connect(const string host_id,const int &port);
		void send_socket(const string s);
        int recv_socket();
        const string get_recvbuf();
        ~Sock();
    private:
        char recvbuf[BUFSIZ];
        struct hostent *hp;
        struct sockaddr_in server;
        int num;
	    WORD myRequest;
	    WSADATA mywsa;
        SOCKET sock;
	protected:
};

#endif
