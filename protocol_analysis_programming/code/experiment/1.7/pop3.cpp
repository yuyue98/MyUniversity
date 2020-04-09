#include "Sock.h"
#include "Base64.h"

int main(int argc, char** argv) {
	
	cout<<"Hello pop3!"<<endl;
	
	Sock sock;
	string str;
	string rts;
	Base64Encrypt bs64;
	Base64Decrypt sb64;
	string username;
	string password;
	// 220.181.12.110 
	const string host_id = "pop.163.com";  // 163邮箱POP3
	int port = 110;                        // SMTP协议专用端口 
	string newtext = "Hello, How are you?";
	
	/* 连接POP3服务器 */
	if (!sock.Connect(host_id,port)) {
		return 0;
	}
	cout<<"Client: connected!"<<endl;
	sock.recv_socket();
	cout<<"Client: connect successfully!"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 告知pop3服务器邮箱用户名 */	
	sock.send_socket("user myemail\r\n");
	sock.recv_socket();
	cout<<"Client: send name"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 告知pop3服务器邮箱密码 */
	sock.send_socket("pass mypassword\r\n"); 
	sock.recv_socket();
	cout<<"Client: send password"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 查询邮箱中的统计信息 */
	sock.send_socket("stat\r\n");
	sock.recv_socket();
	cout<<"Client: send stat"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 列出邮箱中的邮件信息 */
	sock.send_socket("list\r\n");
	sock.recv_socket();
	cout<<"Client: send list"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 显示对应id的邮件内容 */
	string id;
	cout<<"please input a id:";
	cin>>id;
	cin.clear();
	sock.send_socket("retr ");
	sock.send_socket(id);
	sock.send_socket("\r\n");
	cout<<"Client: send retr "<<id<<endl;
	while (true) {
		int num = sock.recv_socket();
		string a = sock.get_recvbuf();
		int b = a.length();
		cout<<"Server: "<<sock.get_recvbuf()<<endl;
		if (a[b-1]=='\n' && a[b-2]=='\r' 
			&& a[b-3]=='.' && a[b-4]=='\n'
			&& a[b-5]=='\r') break;
	}
	
	/* 断开与pop3服务器的连接 */
	sock.send_socket("quit\r\n");
	sock.recv_socket();
	cout<<"Client: send quit"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	return 0;
}
