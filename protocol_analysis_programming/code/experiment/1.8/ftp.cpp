#include "myFTP.h"
#include "Sock1.h" 
#include "Base64.h"

int main(int argc, char** argv) {
	cout<<"Hellp ftp!"<<endl;
	myFTP myftp;
	const string host_id = "192.168.239.134";
	int port = 21;
	string newtext = "Hello, What's your name?";
	if (!myftp.connect_server(host_id,port)) {
		cerr<<"连接失败!"<<endl;
		return 0;
	}
	if (!myftp.login_server("Lily","12345678")) {
		cerr<<"登陆失败!"<<endl;
		return 0;
	}
	if (!myftp.relogin_server("Lily","12345678")) {
		cerr<<"重新登陆失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_type("A")) {
		cerr<<"传输模式更新失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_cwd("./")) {
		cerr<<"工作目录更新失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_cdup()) {
		cerr<<"返回上级目录失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_cdup()) {
		cerr<<"返回上级目录失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_mkd("c_demo")) {
		cerr<<"创建目录失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_deletefolder("c_demo")) {
		cerr<<"删除目录失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_list("./")) {
		cerr<<"获取当前工作空间列表失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_renamefile("1.txt","01.txt")) {
		cerr<<"重命名&移动文件失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_renamefile("01.txt","1.txt")) {
		cerr<<"重命名&移动文件失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_server2local("tubiao.ico","C:/Users/yuyue/Desktop/1.ico",0)) {
		cerr<<"从服务器下载文件失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_local2server("C:/Users/yuyue/Desktop/0.ico","0.ico",0)) {
		cerr<<"向服务器上载文件失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_local2server("C:/Users/yuyue/Desktop/0.txt","0.txt",0)) {
		cerr<<"向服务器上载文件失败!"<<endl;
		return 0;
	}
	if (!myftp.ftp_deletefile("0.txt")) {
		cerr<<"删除文件失败!"<<endl;
		return 0;
	}
	if (!myftp.quit_server()) {
		cerr<<"断开连接失败!"<<endl;
		return 0;
	}
	return 0;
}
