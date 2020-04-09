#include "Sock.h"
#include "Base64.h"

void getmail(Sock& sock) {
	int flag = 0;
	do {
		sock.recv_socket();
		string a = sock.get_recvbuf();
		for (int k=0;k<a.length();k++) {
			if (a[k]=='(') flag++;
			if (a[k]==')') flag--;
		}
		cout<<"Server: "<<sock.get_recvbuf()<<endl;
	}while (flag);
}

int main(int argc, char** argv) {
	
	cout<<"Hello imap!"<<endl;
	
	Sock sock;
	string str;
	string rts;
	Base64Encrypt bs64;
	Base64Decrypt sb64;
	string username;
	string password;
	// 220.181.12.100
	const string host_id = "imap.163.com";  // 163邮箱POP3
	int port = 143;                         // SMTP协议专用端口 
	string newtext = "Hello, How are you?";
	
	/* 连接IMAP服务器 */
	if (!sock.Connect(host_id,port)) {
		return 0;
	}
	cout<<"Client: connected!"<<endl;
	sock.recv_socket();
	cout<<"Client: connect successfully!"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 告知IMAP需要服务器支持的功能列表 */	
	sock.send_socket("a001 capability\r\n");
	sock.recv_socket();
	cout<<"Client: send capability"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 用于防止连接过长时间处于不活动状态而中断 */
	sock.send_socket("a002 noop\r\n"); 
	sock.recv_socket();
	cout<<"Client: send noop"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 通过登陆方式进行认证 */
	sock.send_socket("a005 login myemail mypassword\r\n");
	sock.recv_socket();
	cout<<"Client: send login"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 选中一个邮箱 */
	sock.send_socket("a007 select inbox\r\n");
	sock.recv_socket();
	cout<<"Client: send search"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 列出邮箱中的邮件信息 */
	sock.send_socket("a008 list \".\" #news\r\n");
	sock.recv_socket();
	cout<<"Client: send list"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 检索邮箱以获取符合给定准则的邮件 */
	sock.send_socket("a009 search all\r\n");
	sock.recv_socket();
	cout<<"Client: send search all"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 根据序号获取邮件内容 */
	string id;
	cout<<"please input a id:";
	cin>>id;
	cin.clear();
	sock.send_socket("a010 fetch "+id+" full\r\n");
	sock.recv_socket();
	cout<<"Client: send fetch "+id+" full"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	sock.send_socket("a011 fetch "+id+" body[header]\r\n");
	cout<<"Client: send fetch "+id+" body[header]"<<endl;
	getmail(sock);
	
	sock.send_socket("a012 fetch "+id+" body[text]\r\n");
	cout<<"Client: send fetch "+id+" body[text]"<<endl;
	getmail(sock);
	
	/* 断开与IMAP服务器的连接 */
	sock.send_socket("a013 logout\r\n");
	sock.recv_socket();
	cout<<"Client: send quit"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	return 0;
}
