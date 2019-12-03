#ifndef MYTOOL_H
#define MYTOOL_H

#include <iostream>
#include <iomanip>
#include <sstream> 
#include <fstream>

#include <cstring>
#include <string>
#include <typeinfo>

#include <ctime>
#include <vector>

#include <io.h>
#include <direct.h>
#include <windows.h>
#include <algorithm>

#define BUFSIZE 256

using namespace std;

/* 格式化输出字符串变量 */
void putStr(string str,int width=6);
/* 去除输入前后的空格 */ 
void trim(string &s);
/* 文件拷贝 */
void cpfile(string src,string dst);
/* 判断文件夹是否存在，不存在则创建 */
bool createFolder(string path); 
/* 判断路径是否存在，不存在则创建 */ 
bool createDirectory(string path); 
/* 获取目录下内容信息 */
bool getFileStats(string folder_path,vector<_finddata_t*>& stats);
/* 获取目录下所有文件的路径 */
bool getFiles(string path, vector<string>& files); 
/* 查看内存 */
void putBuf(u_char* buf,int size);
/* 求两数的最大公因数 */
int getMAXcommon(int a,int b);
int gcd(int x, int y);

/* 交换两数 */
template<typename T> void mySwap(T& a,T& b) {
	T c;
	c = a;
	a = b;
	b = c;
} 
/* 将基本数据类型转换成string */ 
template<typename T> string toString(const T& t) {
    ostringstream oss;  //创建一个格式化输出流
    oss<<t;             //把值传递如流中
    return oss.str();  
}
/* 将string转换成基本数据类型 */
template <class Type> Type stringToNum(const string& str) { 
    istringstream iss(str); 
    Type num; 
    iss >> num; 
    return num;     
}

#endif
