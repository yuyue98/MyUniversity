#include "myFTP.h"

myFTP::myFTP():buf(nullptr),result(0),statFlag(true),len(0),sock(),r_sock(nullptr),username(""),password("") {
//	char buf[BUFSIZE];
//	int result;
//	ssize_t len;
//	Sock sock;
//	string username;
//	string password;
	cout<<this<<": myFTP start!"<<endl;
	
}

myFTP::~myFTP() {
	cout<<this<<": myFTP end!"<<endl;
	if (r_sock) {
		delete r_sock;
		r_sock = nullptr;
	}
	if (buf) {
		buf = nullptr;
	}
}

/* 连接到一个FTP服务器 */
bool myFTP::connect_server(const string host_id,const int &port) {
	if (!sock.Connect(host_id,port)) {
		return false;
	}
	cout<<"Client: connected!"<<endl;
	putRecv(sock);
	if (statFlag) {
		return true;
	} else {
		return false;
	} 
}

/* 登录FTP服务器 */
bool myFTP::login_server(string name,string pswd) {
	if (name=="EMPTY") {
		cout<<"Your username: "; 
		cin>>username;
	} else {
		username = name;
	}
	sock.send_socket("USER "+username+"\r\n");
	cout<<"Client: send name!"<<endl;
	putRecv(sock);
	if (statFlag && FTP_PASSWORD_REQUIRED!=result) {
		return true;
	} else if (FTP_PASSWORD_REQUIRED==result) {
		if (pswd=="EMPTY") {
			cout<<"Your password: "; 
			cin>>password;	
		} else {
			password = pswd;
		}
		sock.send_socket("PASS "+password+"\r\n");
		cout<<"Client: send pswd!"<<endl;
		putRecv(sock);
		if (statFlag) {
			return true;
		} else {
			return false;
		}
	} else {
		return false; 
	}
}

/* 重新登陆FTP服务器 */
bool myFTP::relogin_server(string name,string pswd) {
	sock.send_socket("REIN\r\n");
	cout<<"Client: relogin!"<<endl;
	putRecv(sock);
	if (statFlag) {
		if (login_server(name,pswd)) {
			return true;
		} else {
			return false;
		}
	} else {
		return false; 
	}
}

/* 设置FTP服务器传输类型 */
bool myFTP::ftp_type(const string mode) {
	sock.send_socket("TYPE "+mode+"\r\n");
	cout<<"Client: send type!"<<endl;
	putRecv(sock);
	if (statFlag) {
		return true;
	} else {
		return false; 
	}
}

/* 更改FTP服务器工作目录 */
bool myFTP::ftp_cwd(const string path) {
	sock.send_socket("CWD "+path+"\r\n");
	cout<<"Client: send workpath!"<<endl;
	putRecv(sock); 
	if (statFlag) {
		return true;
	} else {
		return false; 
	}
}

/* 返回上级目录 */
bool myFTP::ftp_cdup() {
	sock.send_socket("CDUP\r\n");
	cout<<"Client: send cdup!"<<endl;
	putRecv(sock); 
	if (statFlag) {
		return true;
	} else {
		return false; 
	}
}

/* 创建目录 */
bool myFTP::ftp_mkd(string path) {
	sock.send_socket("MKD "+path+"\r\n");
	cout<<"Client: send mkd!"<<endl;
	putRecv(sock); 
	if (statFlag) {
		return true;
	} else {
		return false; 
	}
}

/* 连接到PASV接口 */
bool myFTP::ftp_pasv_connect() {
	int addr[6];
	sock.send_socket("PASV\r\n");
	cout<<"Client: get pasv!"<<endl;
	putRecv(sock); 
	if (statFlag) {
		sscanf(sock.get_recvbuf().c_str(),"%*[^(](%d,%d,%d,%d,%d,%d)",&addr[0],&addr[1],&addr[2],&addr[3],&addr[4],&addr[5]);
		printf("%d.%d.%d.%d:%d\n",addr[0],addr[1],addr[2],addr[3],addr[4]*256+addr[5]);
		string host_id = to_string(addr[0])+"."+to_string(addr[1])+"."+to_string(addr[2])+"."+to_string(addr[3]);
		int port = addr[4]*256+addr[5];
		r_sock = new Sock();
		if (!r_sock->Connect(host_id,port)) {
			return false;
		} else {
			cout<<"Client: pasv connected!"<<endl<<endl;
			return true;
		}
	} else {
		return false; 
	}
}

/* 列出FTP工作空间的所有目录 */
bool myFTP::ftp_list(const string path) {
	if (ftp_pasv_connect()) {
		sock.send_socket("List "+path+"\r\n");
		cout<<"Client: send list!"<<endl;
		putRecv(sock); 
		if (statFlag) {
			putRecv(*r_sock);
			if (!r_sock) {
				delete r_sock;
			}
			cout<<buf;
			int num = 0;
			sscanf(sock.get_recvbuf().c_str(),"%*[^\n]%d",&num);
			if (!num) {
				putRecv(sock);
			} else {
				result = num;
			}
			judgeResult();
			cout<<endl;
			if (statFlag) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

/* 删除目录 */
bool myFTP::ftp_deletefolder(const string path) {
	sock.send_socket("RMD "+path+"\r\n");
	cout<<"Client: delete folder!"<<endl;
	putRecv(sock); 
	if (statFlag) {
		return true;
	} else {
		return false; 
	}
}

/* 删除文件 */ 
bool myFTP::ftp_deletefile(const string filename) {
	sock.send_socket("DELE "+filename+"\r\n");
	cout<<"Client: delete file!"<<endl;
	putRecv(sock); 
	if (statFlag) {
		return true;
	} else {
		return false; 
	}
}

/* 修改文件名&移动目录 */ 
bool myFTP::ftp_renamefile(const string path,const string new_path) {
	sock.send_socket("RNFR "+path+"\r\n");
	cout<<"Client: send oldpath!"<<endl;
	putRecv(sock); 
	if (statFlag) {
		sock.send_socket("RNTO "+new_path+"\r\n");
		cout<<"Client: send newpath!"<<endl;
		putRecv(sock); 
		if (statFlag) {
			return true;
		} else {
			return false;
		}
	} else {
		return false; 
	}
}

/* 从FTP服务器复制文件到本地 */
bool myFTP::ftp_server2local(const string path,const string new_path,const int size) {
	if (!ftp_type("I")) {
		cerr<<"传输模式更新失败!"<<endl;
		return false;
	}
	if (ftp_pasv_connect()) {
		sock.send_socket("RETR "+path+"\r\n");
		cout<<"Client: send retr thepath!"<<endl;
		putRecv(sock); 
		if (statFlag) {
			ofstream fout(new_path,ios::binary);
			if (!fout) {
				cerr<<"文件"+new_path+"创建失败!"<<endl;
				return false;
			}
			const char* str;
			ssize_t total_len = 0;
			while ((len=r_sock->recv_socket())>0) {
				str = r_sock->get_recvbuf_char();
				total_len += len;
				fout.write(str,len);
			}
			len = total_len;
			cout<<"FILE DOWN SUCCESS! file_len: "<<len<<endl;
			fout.close();
			if (r_sock) {
				delete r_sock;
				r_sock = nullptr;
			}
			
			int num = 0;
			sscanf(sock.get_recvbuf().c_str(),"%*[^\n]%d",&num);
			if (!num) {
				putRecv(sock);
			} else {
				result = num;
				judgeResult();
				cout<<endl;
			}
			if (statFlag) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}

	} else {
		return false;
	}
}

/* 从本地复制文件到FTP服务器 */ 
bool myFTP::ftp_local2server(const string path,const string new_path,const int size) {
	if (!ftp_type("I")) {
		cerr<<"传输模式更新失败!"<<endl;
		return false;
	}
	if (ftp_pasv_connect()) {
		sock.send_socket("STOR "+new_path+"\r\n");
		cout<<"Client: send stor thepath!"<<endl;
		putRecv(sock); 
		if (statFlag) {
			ifstream ifile(path,ios::binary);
			char zbuf[BUFSIZE];
			len = 0;
			while (ifile) {
				ifile.read(zbuf,BUFSIZE);
				len += ifile.gcount();
				r_sock->send_socket(zbuf,ifile.gcount());
			}
			cout<<"FILE LOAD SUCCESS! file_len: "<<len<<endl;
			ifile.close();
			if (r_sock) {
				delete r_sock;
				r_sock = nullptr;
			}
			int num = 0;
			sscanf(sock.get_recvbuf().c_str(),"%*[^\n]%d",&num);
			if (!num) {
				putRecv(sock);
			} else {
				result = num;
				judgeResult();
				cout<<endl; 
			}
			if (statFlag) {
				return true;
			} else {
				return false;
			}	
		} else {
			return false;
		}
	} else {
		return false;
	}
}

/* 断开FTP服务器 */
bool myFTP::quit_server() {
	sock.send_socket("QUIT\r\n");
	cout<<"Client: quit!"<<endl;
	putRecv(sock);
	if (statFlag) {
		return true;
	} else {
		return false; 
	}
}

void myFTP::putRecv(Sock& sk) {
	bool flag = true;
	cout<<"Server: "<<endl;
	int total_len = 0;
	while ((len=sk.recv_socket())>0) {
		total_len += len;
		buf = sk.get_recvbuf_char();
		if (flag) {
			if (&sk!=r_sock) {
				result = atoi(buf);
			}
			flag = false;
		}
		if (&sk!=r_sock) {
			cout<<buf;
		}
		if (len!=BUFSIZE||(buf[total_len-1]=='\n'&&buf[total_len-2]=='\r')) {
			len = total_len;
			break;
		}
	}
	judgeResult();
	cout<<endl;
}

string myFTP::readFileIntoString(ifstream& ifile,const int size) {
	//将文件读入到ostringstream对象buf中
	ostringstream zbuf;
	zbuf.str("");
	char ch;
	int num = 0;
	static int total_len = 0;
	while(zbuf&&size>num++&&ifile.get(ch))
	zbuf.put(ch);
	len = zbuf.str().size();
	total_len += len; 
	cout<<"len: "<<len<<endl;
	cout<<"total_len: "<<total_len<<endl;
	//返回与流对象buf关联的字符串
	return zbuf.str();
}

void myFTP::judgeResult() {
	if (FTP_DATALINK_OPENING==result) {
		cout<<"数据连接打开中!"<<endl;
		statFlag = true; 
	} else if (FTP_SUCCESS==result) {
		cout<<"成功"<<endl;
		statFlag = true;
	} else if (FTP_SERVICE_READY==result) {
		cout<<"服务器准备就绪!"<<endl;
		statFlag = true;
	} else if (FTP_SERVER_CLOSE==result) {
		cout<<"服务器断开连接!"<<endl;
		statFlag = true;
	} else if (FTP_DATALINK_OPEN==result) {
		cout<<"数据连接打开!"<<endl;
		statFlag = true;
	} else if (FTP_DATALINK_CLOSE==result) {
		cout<<"数据连接关闭!"<<endl;
		statFlag = true;
	} else if (FTP_GOTO_PASSIVE_MODE==result) {
		cout<<"进入被动模式!"<<endl;
		statFlag = true;
	} else if (FTP_LOGIN_SUCCESS==result) {
		cout<<"登陆成功!"<<endl;
		statFlag = true;
	} else if (FTP_FILE_ACTION_COMPLETE==result) {
		cout<<"文件行为完成!"<<endl;
		statFlag = true;
	} else if (FTP_FILE_CREATED==result) {
		cout<<"文件创建成功!"<<endl;
		statFlag = true;
	} else if (FTP_PASSWORD_REQUIRED==result) {
		cout<<"需要输入密码!"<<endl;
		statFlag = true;
	} else if (FTP_FILE_ACTION_UNKNOWN==result) {
		cout<<"需要等待下一步文件操作!"<<endl;
		statFlag = true; 
	} else if (FTP_LOGIN_PASSWORD_INCORRECT==result) {
		cerr<<"密码错误!"<<endl;
		statFlag = false; 
	} else if (FTP_ERROR_PARAMETER==result) {
		cerr<<"参数错误!"<<endl;
		statFlag = false;
	} else if (FTP_UNAVAILABLE_FILE==result) {
		cerr<<"该文件路径不可用!"<<endl;
		statFlag = false;
	} else  {
		cout<<"result: "<<result<<endl;
		cerr<<"该状态码意义未知!"<<endl;
		statFlag = false; 
	}
}
