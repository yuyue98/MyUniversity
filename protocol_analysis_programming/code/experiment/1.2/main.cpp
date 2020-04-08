#include <winsock2.h>
#include <iostream>
using namespace std;

int main(void)
{
    WSADATA wsaData;

    if(int Ret=WSAStartup(MAKEWORD(2,2),&wsaData)!=0) {
        cout<<"WSAStartup failed with error "<<Ret<<endl;
    }
    else{
    	cout<<"WSAStartup success."<<endl;
    }

    if(WSACleanup()==SOCKET_ERROR){
    	cout<<"WSACleanup failed with error "<<WSAGetLastError()<<endl;
    }
    else{
    	cout<<"WSACleanup success."<<endl;
    }
	system("pause");
    return 0;
}