#ifndef MYHTTP_H
#define MYHTTP_H

#include <fstream>
#include <sstream>

#include "Sock.h" 

class myHTTP
{
	public:
		myHTTP();
		~myHTTP();
		/* 连接HTTP服务器 */
		bool connect_server(const string host_id,const int &port);
		/* GET方法 */
		bool the_get(const string path,const string filepath); 
		/* POST方法 */
		bool the_post(const string path,const string filepath); 
		/* 断开HTTP服务器 */
		bool close_connect();
		bool saveFlie(const string path);
		string int2string(const int num);
		int getnumlen(const int num);
	private:
		string host_id;
		int port;
		ssize_t len;
        Sock sock;
        string url;
        string header;
	protected:
};

#endif
