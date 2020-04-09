#ifndef MYFTP_H
#define MYFTP_H

#include <fstream>
#include <sstream>

#include "Sock.h"

#define FTP_NEWFILE_RESETSIGN 110			//新文件指示器上的重启标记
#define FTP_DATALINK_OPENING 125			//数据连接已打开，在短时间内开始传输 
#define FTP_SUCCESS 200						//成功
#define FTP_SERVICE_READY 220				//服务器就绪
#define FTP_SERVER_CLOSE 221				//服务关闭 
#define FTP_DATALINK_OPEN 225				//数据连接打开
#define FTP_DATALINK_CLOSE 226				//数据连接关闭 
#define FTP_GOTO_PASSIVE_MODE 227			//进入被动模式 
#define FTP_LOGIN_SUCCESS 230				//登录因特网服务器
#define FTP_FILE_ACTION_COMPLETE 250		//文件行为完成
#define FTP_FILE_CREATED 257				//文件创建成功
#define FTP_PASSWORD_REQUIRED 331			//用户名有效，请求密码
#define FTP_FILE_ACTION_UNKNOWN 350			//文件行为未定 
#define FTP_ERROR_PARAMETER 501				//错误参数 
#define FTP_LOGIN_PASSWORD_INCORRECT 530	//用户密码错误
#define FTP_UNAVAILABLE_FILE 550			//不可用的文件 

class myFTP
{
	public:
		myFTP();
		~myFTP();
		/* 连接FTP服务器 */
		bool connect_server(const string host_id,const int &port);
		/* 登录FTP服务器 */
		bool login_server(string name="EMPTY",string pswd="EMPTY");
		/* 重新登陆FTP服务器 */
		bool relogin_server(string name="EMPTY",string pswd="EMPTY"); 
		/* 设置FTP服务器传输类型 */
		bool ftp_type(const string mode);
		/* 更改FTP服务器工作目录 */
		bool ftp_cwd(const string path);
		/* 返回上级目录 */
		bool ftp_cdup();
		/* 创建目录 */
		bool ftp_mkd(string path);
		/* 连接到PASV接口 */
		bool ftp_pasv_connect();
		/* 列出FTP工作空间的所有目录 */
		bool ftp_list(const string path);
		/* 删除目录 */
		bool ftp_deletefolder(const string path);
		/* 删除文件 */ 
		bool ftp_deletefile(const string filename);
		/* 修改文件名&移动目录 */ 
		bool ftp_renamefile(const string path,const string new_path);
		/* 从FTP服务器复制文件到本地 */
		bool ftp_server2local(const string path,const string new_path,const int size);
		/* 从本地复制文件到FTP服务器 */ 
		bool ftp_local2server(const string path,const string new_path,const int size);
		/* 断开FTP服务器 */
		bool quit_server();
		
		void putRecv(Sock& sk);
		string readFileIntoString(ifstream& ifile,const int size);
		void judgeResult(); 
	private:
		string sbuf;
		const char* buf;
        int result;
        bool statFlag; 
        ssize_t len;
        Sock sock;
        Sock* r_sock;
        string username;
        string password;
	protected:
};

#endif
