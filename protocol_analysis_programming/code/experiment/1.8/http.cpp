#include "myHTTP.h"
#include "Sock1.h" 

int main(int argc, char** argv) {
	cout<<"Hello http!"<<endl;
	myHTTP myhttp;
	//const string host_id = "120.78.89.40";
	const string host_id = "192.168.239.134";
	int port = 8080;
	if (!myhttp.connect_server(host_id,port)) {
		cerr<<"连接失败!"<<endl;
		return 0;
	}
	if (!myhttp.the_get("/demo/","C:/Users/yuyue/Desktop/demo/index.html")) {
		cerr<<"获取HTML失败!"<<endl;
		return 0;
	}
	if (!myhttp.the_get("/demo/css/style.css","C:/Users/yuyue/Desktop/demo/css/style.css")) {
		cerr<<"获取CSS失败!"<<endl;
		return 0;
	}
	if (!myhttp.the_get("/demo/js/main.js","C:/Users/yuyue/Desktop/demo/js/main.js")) {
		cerr<<"获取js失败!"<<endl;
		return 0;
	}
	if (!myhttp.the_get("/demo/lib/vue.js","C:/Users/yuyue/Desktop/demo/lib/vue.js")) {
		cerr<<"获取js失败!"<<endl;
		return 0;
	} 
	if (!myhttp.close_connect()) {
		cerr<<"断开连接失败!"<<endl;
		return 0;
	}
//	if (!myhttp.the_post("/duidui/getMonthSource?websiteId=1&startdate=2019-04-03&enddate=2019-04-07&usertype=123&area=123","C:/Users/yuyue/Desktop/demo/123.json")) {
//		cerr<<"获取json失败!"<<endl;
//		return 0;
//	}
	return 0;
}
