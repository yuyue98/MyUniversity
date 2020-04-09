#include "myHTTP.h"

myHTTP::myHTTP():host_id(""),port(0),len(0),sock(),url(""),header("") {
	cout<<this<<": myHTTP start!"<<endl;
}

myHTTP::~myHTTP() {
	cout<<this<<": myHTTP end!"<<endl;
}

/* 连接HTTP服务器 */
bool myHTTP::connect_server(const string host_id,const int &port) {
	this->host_id = host_id;
	this->port = port;
	if (!sock.Connect(host_id,port)) {
		return false;
	}
	cout<<"Client: connected!"<<endl;
	return true; 
}

/* GET方法 */
bool myHTTP::the_get(const string path,const string filepath) {
	cout<<"Client: get "+path+"!"<<endl;
	url = host_id+":"+int2string(port);
	header = "GET "+path+" HTTP/1.1\r\n";
	header += "Host: "+url+"\r\n";
	header += "Connection: keep-alive\r\n";
	header += "Cache-Control: max-age=0\r\n";
	header += "Upgrade-Insecure-Requests: 1\r\n";
	header += "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Safari/537.36\r\n";
	header += "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3\r\n";
	header += "Referer: http://"+url+"/demo/\r\n";
	header += "Accept-Encoding: deflate\r\n";
	header += "Accept-Language: zh-CN,zh;q=0.9\r\n";
	//header += "If-None-Match: \"d4fb73face66d41:0\"\r\n";
	//header += "If-Modified-Since: Thu, 18 Oct 2018 10:40:25 GMT\r\n";
	header += "\r\n";
	cout<<"header: "<<endl<<header<<endl;
	sock.send_socket(header);
	if (saveFlie(filepath)) {
		return true;
	} else {
		return false;
	}
}

/* POST方法 */ 
bool myHTTP::the_post(const string path,const string filepath) {
	cout<<"Client: post "+path+"!"<<endl;
	url = host_id+":"+int2string(port);
	header = "POST "+path+" HTTP/1.1\r\n";
	header += "Host: "+url+"\r\n";
	header += "Connection: keep-alive\r\n";
	header += "Cache-Control: no-cache\r\n";
	//header += "Upgrade-Insecure-Requests: 1\r\n";
	header += "Postman-Token: f57d5cf8-251f-4d43-9ad8-538250912731\r\n";
	header += "User-Agent: PostmanRuntime/7.6.1\r\n";
	header += "Accept: */*\r\n";
	//header += "Referer: http://"+url+"/\r\n";
	header += "Accept-Encoding: deflate\r\n";
	//header += "Accept-Language: zh-CN,zh;q=0.9\r\n";
	//header += "If-None-Match: \"d4fb73face66d41:0\"\r\n";
	//header += "If-Modified-Since: Thu, 18 Oct 2018 10:40:25 GMT\r\n";
	header += "Content-Length: 0\r\n";
	header += "\r\n";
	cout<<"header: "<<endl<<header<<endl;
	sock.send_socket(header);
	sock.recv_socket();
	cout<<sock.get_recvbuf()<<endl;
	return true;
}

/* 断开HTTP服务器 */
bool myHTTP::close_connect() {
	sock.send_socket("CLOSE\r\n");
	cout<<"Client: close!"<<endl;
	sock.recv_socket();
	cout<<sock.get_recvbuf()<<endl;
	return true;
}

bool myHTTP::saveFlie(const string path) {
	ofstream fout(path,ios::binary);
	if (!fout) {
		cerr<<"文件"+path+"创建失败!"<<endl;
		return false;
	}
	const char* str;
	const char* str1 = "Content-Length: ";
	const char* str2;
	ssize_t total_len = 0;
	ssize_t num = 0;
	ssize_t sum = 0;
	bool flag = true;
	while ((len=sock.recv_socket())>0) {
		str = sock.get_recvbuf_char();
		sum += len;
		if (flag) {
			str2 = strstr(str,str1)+strlen(str1);
			total_len = atoi(str2);
			for (int i=0;i<len;i++) {
				if (str[i]=='\n'&&str[i-1]=='\r'&&str[i-2]=='\n'&&str[i-3]=='\r') {
					str = &(str[i+1]);
					num = len-(i+1);
					sum -= (i+1);
					break;
				}
				printf("%c",str[i]);
			}
			cout<<endl;
			flag = false;	
		} else {
			num = len;
		}
//		cout<<"len: "<<len<<endl;
//		cout<<"num: "<<num<<endl;
//		cout<<"sum: "<<sum<<endl;
//		cout<<"total_len: "<<total_len<<endl;
		fout.write(str,num);
		if (len!=BUFSIZE||sum==total_len) {
			len = total_len;
			break;
		}
	}
	cout<<"GET DOWN SUCCESS! total_len: "<<total_len<<endl;
	fout.close();
	return true;
}

string myHTTP::int2string(const int num) {
	stringstream str;
	str<<num;
	return str.str();
}

int myHTTP::getnumlen(const int num) {
	int sum = 0;
	int n = num;
	while (n) {
		sum++;
		n /= 10;
	}
	cout<<"sum: "<<sum<<endl;
	return sum;
}
