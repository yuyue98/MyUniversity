#include "Sock.h"
#include "Base64.h"

int main(int argc, char** argv) {

	cout<<"Hello smtp!"<<endl;
	
	Sock sock;
	string str;
	string rts;
	Base64Encrypt bs64;
	Base64Decrypt sb64;
	string username;
	string password;
	// 220.181.12.14 
	const string host_id = "smtp.163.com"; // 163邮箱SMTP 
	int port = 25;                         // SMTP协议专用端口 
	string newtext = "Hello, How are you?";
	
	/* 与SMTP服务器建立连接 */ 
	if (!sock.Connect(host_id,port)) {
		return 0;
	}
	sock.recv_socket();
	cout<<"Client: connected!"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 告诉SMTP服务器本主机名 */ 
	sock.send_socket("ehlo yuyue\r\n");
	sock.recv_socket();
	cout<< "Client: send ehlo"<<endl;
	cout<<"Server:"<<sock.get_recvbuf()<<endl;
	
	/* 告诉SMTP服务器以登陆方式认证 */ 
	sock.send_socket("auth login\r\n");
    sock.recv_socket();
    cout<<"Client: send auth login"<<endl;
	cout<<"Server: "<<sock.get_recvbuf()<<endl;
	
	/* 告知SMTP服务器用户名 */ 
	cin>>username;
	cin.clear();
	bs64.Update(username.c_str(),username.length());
	cout<<bs64.GetString()<<endl;
	sock.send_socket(bs64.GetString());
	sock.send_socket("\r\n");
	sock.recv_socket();
    cout<<"Client: send name"<<endl;
	cout<<"Server:"<<sock.get_recvbuf()<<endl;
	
	/* 告知SMTP服务器密码  */ 
	cin>>password;
	cin.clear();
	bs64.Reset();
	bs64.Update(password.c_str(),password.length());
	//EncodeBase64(rts,password,password.length());
	cout<<bs64.GetString()<<endl;
	sock.send_socket(bs64.GetString());
    sock.send_socket("\r\n");
    sock.recv_socket();
    cout<<"Client: send password"<<endl;
	cout<<"Server:"<<sock.get_recvbuf()<<endl;
	
	/* 指定邮件发送者的邮箱地址  */ 
	sock.send_socket("mail From: <yuhonge123@163.com>\r\n");
    sock.recv_socket();
    cout<<"Client: send mail from"<<endl;
	cout<<"Server:"<<sock.get_recvbuf()<<endl;
	
	/* 指定邮件接收者的邮箱地址  */ 
	sock.send_socket("rcpt To: <yuhonge123@163.com>\r\n");
    sock.recv_socket();
    cout<<"Client: send rept to"<<endl;
	cout<<"Server:"<<sock.get_recvbuf()<<endl;
	
	/* 告知SMTP邮件发送程序准备开始输入邮件内容 */ 
    sock.send_socket("data\r\n");
    sock.recv_socket();
    cout<<"Client: send data"<<endl;
	cout<<"Server:"<<sock.get_recvbuf()<<endl;
	sock.send_socket("from: <myemail>\r\n"); //发送者邮箱地址 
	sock.send_socket("to: <youremail>\r\n");   //接收者邮箱地址 
	sock.send_socket("subject: testmail\r\n");          //邮件主题 
    sock.send_socket("\r\n\r\n");
    sock.send_socket(newtext); 
    sock.send_socket("\r\n");
    sock.send_socket(".\r\n");
    sock.recv_socket();
    cout<<"Client: send content"<<endl;
	cout<<"Server:"<<sock.get_recvbuf()<<endl;
	
	/* 告知SMTP服务器断开连接 */
	sock.send_socket("quit\r\n");
    sock.recv_socket();
    cout<<"Client: send quit"<<endl;
	cout<<"Server:"<<sock.get_recvbuf()<<endl;
	
	return 0;
}
