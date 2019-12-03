#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<Windows.h>
#include<conio.h>	
#include<time.h>
#include"movie.h"
using namespace std;

struct seat_manage {
	int x[10][10];
};

class menu_0 :public movie//登录系统
{
private:
	int judge = 0;//判断是管理人员入口还是观众入口
	COORD pos_1;
	time_t t;
	struct tm pt;
	int judge_log_re;
protected:
	string special;//管理人员特别进入的隐藏代码
	seat_manage seat_1;
	vector<seat_manage> seat_2;
	string name_1;
	vector<string> name_2;
	vector<string> id_1;
	vector<string> password_1;
	vector<double> integral_1;//作为管理人员或者看电影的录入数据
	COORD pos_0;//初始位置的坐标
	string id;
	string password;
	double integral;
	double man_money;
	int man_people;
	int rand_inter;//生成随机进入凭证
	fstream log_system;
	int year, month, day, hour, minute;
	HANDLE hout;
	HANDLE hin;
public:
	menu_0() 
	{
		log_system.open("debug\\manager_cus.txt",ios::in);
		log_system >> special;//获得这个特别进入的数据
		log_system.close();

		log_system.open("debug\\manageinfor.txt", ios::in);
		log_system >> man_money;
		log_system >> man_people;
		log_system.close();

		time(&t);
		localtime_s(&pt, &t);
		year = pt.tm_year + 1900;
		month = pt.tm_mon + 1;
		day = pt.tm_mday;
		hour = pt.tm_hour;
		minute = pt.tm_min;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		hin = GetStdHandle(STD_INPUT_HANDLE);
		judge_log_re = 1;//为1登录，为2注册，为0成功登录

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				seat_1.x[i][j] = 0;
	}
	void draw_log_register();
	bool log();//登录成功判断
	bool record();
	void draw_log();
	void draw_clear();
	void draw_mouse();
	void draw_manager();
	void mouse_choose_log();
	void mouse_choose_re();
	void menu_00(int, int);
};

class menu_1:public menu_0//列出根据时间，电影名选电影的按钮  以及电影总表，智能推荐电影
{
private:
	int n;
	int judge;//来判断是第几次画图，第一次画要初始化pos_1等几个坐标，第二次就直接用这几个坐标了
	COORD pos_1;
	COORD pos_2;
	COORD pos_3;
protected:
	HWND hwnd;
	HDC hdc;
	int judge_return;//判断是否返回
	//COORD pos_0;//初始位置的坐标，提到了前一步做了
	COORD pos;//中间坐标，起到固定坐标不改变的效果
	vector<movie*> movies_1;//推荐电影内容
	int mouse_infor;//根据鼠标点击点得来的具体用户选择信息
	int b_time, e_time;//根据时间得来的大概时间
	string name;//根据电影名得来
	int movie_infor_number;//通过电影总表得来的电影序列
	int n_change;//根据推荐电影得来的电影序列，也即后面可以借助这个数据来看出到底在推挤电影栏里选的是那个电影
public:
	menu_1()
	{
		hwnd = GetActiveWindow();
		hdc = GetDC(hwnd);
	}
	void menu_01();
	void draw(COORD pos);//画出首页的内容
	void draw_button();//画出根据时间或者电影名字选电影的按钮
	void draw_movie();//画出所有的电影以及其排片时间
	void draw_goodmovie();//画出推荐的电影，根据get_goodmovie来得出，有换一换按钮
	void get_goodmovie();//通过评分等算出推荐的电影是什么
	void get_button_infor();
	void get_movie_infor(int);
	COORD get_pos() { return pos; };
	void set_pos(COORD pos) { this->pos = pos; };
	void mouse_choose();//鼠标按钮，控制选择好之后的变换
	int get_judge_return() { return judge_return; }
};

class menu_2 :public menu_1//列出电影列表,根据mouse_infor来变换列表
{
private:
	vector<movie*> movies_2;
protected:
	int judge_return_2;
	movie* e_movie;
public:
	void menu_02();
	void draw(COORD pos);
	void draw_time();
	void draw_name();
	void draw_movie();
	void draw_goodmovie();
	void mouse_choose();
	int get_judge_return_2() { return judge_return_2; }
};

class menu_3 :public menu_2//选座位
{
public:
	void menu_03();
	void draw(COORD pos);
	void draw_seat();
	void mouse_choose();
};

class menu_4:public menu_3//最后的确认，输入进文件里面
{
public:
	void menu_04();
	void draw(COORD pos);
	void change_movie_id();
};