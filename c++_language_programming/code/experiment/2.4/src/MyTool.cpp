#include "MyTool.h"

void putStr(string str, int width) {
	str = str+"\t";
	cout<<setw(width)<<str;
//	cout<<str<<setw((width-str.length()+2)/2)<<"\t";
}

void trim(string &s) {
	if (!s.empty()) {
		s.erase(0,s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
}

void cpfile(string src,string dst) {
    ifstream in(src,ios::in|ios::binary);
    ofstream out(dst,ios::out|ios::binary);
    if (!in.is_open()) {
        cout<<src<<"旧文件打开失败！"<<endl;
	    in.clear();
	    out.clear();
        return;
    }
    if (!out.is_open()) {
        cout<<dst<<"新文件打开失败！"<<endl;
	    in.clear();
	    out.clear();
        return;
    }
    if (src == dst) {
        cout<<"新旧文件路径相同！"<<endl;
	    in.clear();
	    out.clear();
        return; 
    }
    char buf[4096];
    long long totalBytes = 0;
    while(in)
    {
        //read从in流中读取4096字节，放入buf数组中，同时文件指针向后移动4096字节
        //若不足4096字节遇到文件结尾，则以实际提取字节读取。
        in.read(buf,4096);    
        //gcount()用来提取读取的字节数，write将buf中的内容写入out流。
        out.write(buf, in.gcount());    
        totalBytes += in.gcount();
    }
    in.close();
    in.clear();
    out.close();
    out.clear();
}

bool createFolder(string path) {
	int ref; 
	if (-1==_access(path.c_str(),0))	//如果文件夹不存在
		ref = _mkdir(path.c_str());	            //则创建 
	else return false;
	if (-1==ref) return false;
	else return true;
}

bool createDirectory(string path) {
	int len = path.length();
	char tmpDirPath[256] = {0};
	for (int i=0;i<len;i++)
	{
		tmpDirPath[i] = path[i];
		if ('\\'==tmpDirPath[i]||'/'==tmpDirPath[i])
		{
			if (-1==_access(tmpDirPath, 0))
			{
				int ret = _mkdir(tmpDirPath);
				if (-1==ret) return false;
			}
		}
	}
	return true;
}

bool getFileStats(string path,vector<_finddata_t*>& stats) {
	intptr_t hFile = 0;
	_finddata_t* fileinfo;
	string p;
	try {
		fileinfo = new _finddata_t;
		hFile=_findfirst(p.assign(path).c_str(),fileinfo);
		if (-1!=hFile) {
			if (fileinfo->attrib&_A_SUBDIR) {
				_findclose(hFile);
				if (-1!=(hFile=_findfirst(p.assign(path).append("/*").c_str(),fileinfo))) {
					do {
						if (0!=strcmp(fileinfo->name,".")&&0!=strcmp(fileinfo->name,"..")) {
							stats.push_back(fileinfo);
							fileinfo = new _finddata_t;
						}
					} while (0==_findnext(hFile,fileinfo));
					delete fileinfo;
				}
			} else {
				stats.push_back(fileinfo);
			}
			_findclose(hFile);
			return true;
		} else {
			return false;
		}
	} catch(exception e) {
		return false;
	}
	return true;
}

bool getFiles(string folder_path, vector<string>& files) {
	//文件句柄
	intptr_t hFile = 0;//Win10
	//long hFile = 0;
	//文件信息  
	_finddata_t fileinfo;
	string p;
	try {
		if (-1!=(hFile=_findfirst(p.assign(folder_path).append("/*").c_str(),&fileinfo))) {
			do {
				//如果是目录,迭代之  
				//如果不是,加入列表  
				if ((fileinfo.attrib&_A_SUBDIR)) {
					if (0!=strcmp(fileinfo.name,".")&&0!=strcmp(fileinfo.name,".."))
						getFiles(p.assign(folder_path).append("/").append(fileinfo.name),files);
				} else {
					files.push_back(p.assign(folder_path).append("/").append(fileinfo.name));
				}
			} while (0==_findnext(hFile,&fileinfo));
			_findclose(hFile);
			return true;
		} else {
			return false;
		}
	} catch (exception e) {
		return false;
	}
}

void putBuf(u_char* buf,int size) {
	for (int i=0;i<size;i++) {
		printf("%02x ",buf[i]);
		if (0==(i+1)%16) cout<<endl;
	}
	cout<<endl;
} 

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int getMAXcommon(int a,int b) {
	int d;
	if (a<b) mySwap(a,b);
	if (0==b) return a;
	d = a%b;
	if (0==d) return b;
	while (0!=d) {
		a = b;
		b = d;
		d = a%b;
	}
	return b;
}
