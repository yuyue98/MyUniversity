#include "seat.h"

void seat::set_seat(int x, int y)
{
	MovieSeat[x - 1][y - 1] = 1;
}

void seat::set_seat_clearly()
{
	for(int i=0;i<10;i++)
		for (int j = 0; j < 10; j++)
		{
			if (MovieSeat[i][j] == 1)
				MovieSeat[i][j] = 2;
		}
}

void seat::draw_seat(COORD pos,HANDLE hout,int o_x)
{
	pos.X += 26;
	SetConsoleCursorPosition(hout, pos);
	cout << "荧幕";
	for (int i = 0; i < 10; i++)
	{
		pos.Y += 2; pos.X = o_x;
		SetConsoleCursorPosition(hout, pos);
		for (int j = 0; j < 10; j++)
		{
			pos.X+=6;
			if (MovieSeat[i][j] != 0)SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED);
			else
			{
				if (i >= 2 && i <= 5 && j <= 6 && j >= 3)SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
				else SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			}
			cout << "|I|";
			SetConsoleCursorPosition(hout, { 0,2 });
			SetConsoleCursorPosition(hout, pos);
		}
	}
	SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	pos.Y += 2; pos.X = o_x;
	SetConsoleCursorPosition(hout, pos);
	cout << "注：红色座位为已选座位，白色座位为最佳观影位，绿色座位为未选座位";
	pos.Y += 2; pos.X = o_x;
	SetConsoleCursorPosition(hout, pos);
	cout << "确认";
	pos.Y += 2; pos.X = o_x;
	SetConsoleCursorPosition(hout, pos);
	cout << "返回";
}

int seat::get_seat(int x,int y)
{
	return MovieSeat[x][y];
}

void seat::re_seat(int x, int y)
{
	MovieSeat[x][y] = 0;
}

void seat::re_all_seat()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (MovieSeat[i][j] == 1)MovieSeat[i][j] = 0;
}
