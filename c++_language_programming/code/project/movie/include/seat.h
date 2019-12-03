#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;
const int seat_1 = 10;

class seat
{
private:
	int MovieSeat[seat_1][seat_1];
public:
	seat()
	{
		for (int i = 0; i < seat_1; i++)
			for (int j = 0; j < seat_1; j++)
				MovieSeat[i][j] = 0;
	}
	void set_seat(int, int);//修改关于座位的数据
	void set_seat_clearly();
	void draw_seat(COORD pos,HANDLE hout,int o_x);//在控制台里面画出特定场次的座位
	int get_seat(int,int);
	void re_seat(int, int);
	void re_all_seat();
};
