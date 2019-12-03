#include "menu.h"

void menu_1::menu_01()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };  
	SetConsoleCursorInfo(hout, &cursor_info);
	judge_return = 1;
	name = "0";
	b_time = e_time = 0;
	judge = 0;
	n_change = 0;
	n = 0;
	insert_movies();
	get_goodmovie();
	draw(pos_0);
	mouse_choose();
}

void menu_1::draw(COORD pos)
{
	SetConsoleCursorPosition(hout, pos);
	for (int i = 0; i < 10000; i++)cout << ' ';
	SetConsoleCursorPosition(hout, pos);
	cout << "---欢迎 " << id << " 来到电影城---";
	pos.Y += 1;
	SetConsoleCursorPosition(hout, pos);
	cout << "你的积分为：" << integral;
	pos.Y += 1;
	set_pos(pos);
	draw_button();
	draw_movie();
	draw_goodmovie();
}

void menu_1::draw_button()
{
	pos.X = pos_0.X;//pos_1等与pos的作用是一次初始化以后，pos的初始值无用处，pos将做一个承接数据的作用，来作为中间变量来使得能够画出图形
	if (judge <= 2)
	{
		pos_1 = pos;
		judge++;
	}
	pos = pos_1;
	SetConsoleCursorPosition(hout, pos);
	cout << "根据时间段选电影入口：" << "入口";
	pos.Y++; pos.X = pos_0.X;
	SetConsoleCursorPosition(hout, pos);
	cout << "根据电影名选电影入口：" << "入口";
	pos.Y += 2;
}

void menu_1::draw_movie()
{
	pos.X = pos_0.X;
	if (judge <= 2)
	{
		pos_2 = pos;
		judge++;
	}
	pos = pos_2;
	SetConsoleCursorPosition(hout, pos);
	for (int i = 0; i < movies.size(); i++)
	{
		
		cout << i + 1 << movies[i]->get_name() << "--" << movies[i]->get_hour() << ':';  
		if (movies[i]->get_minute() < 10) cout << "0" << movies[i]->get_minute();//防止出现8:0这种情况
		else cout << movies[i]->get_minute();
		cout << "  " << movies[i]->get_movietime() << " 价格：" << movies[i]->get_price();
		pos.Y++; pos.X = pos_0.X;
		SetConsoleCursorPosition(hout, pos);
	}
	pos.Y += 1;
}

void menu_1::draw_goodmovie()
{
	pos.X = pos_0.X;
	if (judge <= 2)
	{
		pos_3 = pos;
		judge++;
	}
	if (n == 0)return;//表明如果没有好电影怎么办
	else
	{
		n_change--;
		if (n_change == 0)n_change = n;//使遍历一遍后可以回来再次遍历
		pos = pos_3;
		SetConsoleCursorPosition(hout, pos);
		for (int i = 0; i < 100; i++)cout << ' ';
		SetConsoleCursorPosition(hout, pos);
		cout << movies_1[n_change - 1]->get_name() << "--" << movies_1[n_change - 1]->get_hour() << ':';
		if (movies_1[n_change - 1]->get_minute() < 10)cout << "0" << movies_1[n_change - 1]->get_minute();
		else cout << movies_1[n_change - 1]->get_minute();
		cout << "  " << movies_1[n_change - 1]->get_movietime() << " 价格：" << movies_1[n_change - 1]->get_price() << " 评分：" << movies_1[n_change - 1]->get_socre();
		pos.Y++; pos.X = pos_0.X;
		SetConsoleCursorPosition(hout, pos);
		cout << "换一换";
		pos.Y += 1;
	}
}

void menu_1::get_goodmovie()
{
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i]->get_socre() >= 8.0)//&&movies[i]->get_hour() > hour
		{
			n++;
			movies_1.push_back(movies[i]);
		}
	}
	n_change = n;//记录有多少好电影
}

void menu_1::get_button_infor()
{
	pos = pos_3;
	pos.Y+=2;
	if(mouse_infor==11)
	{
		SetConsoleCursorPosition(hout, pos);
		for (int i = 0; i < 30; i++)cout << ' ';
		SetConsoleCursorPosition(hout, pos);
		cout << "请输入时间段："; cin >> b_time >> e_time;
	}
	else if (mouse_infor == 12)
	{
		SetConsoleCursorPosition(hout, pos);
		for (int i = 0; i < 30; i++)cout << ' ';
		SetConsoleCursorPosition(hout, pos);
		cout << "请输入电影名："; cin >> name;
	}
}

void menu_1::get_movie_infor(int i)
{
	movie_infor_number = i;
}


void menu_1::mouse_choose()
{
	INPUT_RECORD MouseRecord;
	DWORD ret;
	COORD newhome, oldhome = pos_0;
	DWORD oldset, newset;
	GetConsoleMode(hin, &oldset);
	newset = oldset; 
	newset &= ~(ENABLE_QUICK_EDIT_MODE);  
	SetConsoleMode(hin, newset);
	oldhome.Y -= 3; oldhome.X -= 3;
	while (1)
	{
		ReadConsoleInput(hin, &MouseRecord, 1, &ret);
		SetConsoleCursorPosition(hout, oldhome);
		if (MouseRecord.EventType == MOUSE_EVENT)
		{
			newhome = MouseRecord.Event.MouseEvent.dwMousePosition;
			if (newhome.Y == pos_1.Y&&newhome.X >= (pos_0.X+22) && newhome.X <= (pos_0.X+25) && MouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				mouse_infor = 11;
				get_button_infor();
				return;
			}
			if (newhome.Y == (pos_1.Y + 1) && newhome.X >= (pos_0.X+22) && newhome.X <= (pos_0.X+25) && MouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				mouse_infor = 12;
				get_button_infor();
				return;
			}
			for (int i = 0; i < movies.size(); i++)
			{
				if (newhome.Y == (pos_2.Y + i) && MouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					mouse_infor = 13;
					get_movie_infor(i);//将选的那个电影的信息存起来
					return;
				}
			}
			if (newhome.Y == pos_3.Y&&MouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				mouse_infor = 14; return;
			}
			if (newhome.Y == (pos_3.Y + 1) && MouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				draw_goodmovie();
			}
		}
	}
}

void menu_2::menu_02()
{
	vector<movie*> tmp;
	movies_2.swap(tmp);//清空元素以防止后面的鼠标函数里面无法得到正确的返回值
	judge_return_2 = 1;
	judge_return = 1;
	draw(pos_0);
	if(mouse_infor==11||mouse_infor==12)mouse_choose();
}

void menu_2::draw(COORD pos)
{
	SetConsoleCursorPosition(hout, pos);
	for (int i = 0; i < 10000; i++)cout << ' ';
	if (mouse_infor == 11)draw_time();
	if (mouse_infor == 12)draw_name();
	if (mouse_infor == 13)draw_movie();
	if (mouse_infor == 14)draw_goodmovie();
	SetConsoleCursorPosition(hout, {0,1});
}

void menu_2::draw_time()
{
	pos = pos_0;
	SetConsoleCursorPosition(hout,pos);
	int j = 0;
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i]->get_hour() <= e_time && movies[i]->get_hour() >= b_time)
		{
			j++;
			pos.Y++;
			movies_2.push_back(movies[i]);
			cout << j << movies[i]->get_name() << "--" << movies[i]->get_hour() << ':';
			if (movies[i]->get_minute() < 10)cout << "0" << movies[i]->get_minute();
			else cout << movies[i]->get_minute();
			cout << "  " << movies[i]->get_movietime() << " 价格：" << movies[i]->get_price();
			SetConsoleCursorPosition(hout, pos);
		}
	}
	cout << "返回";
}

void menu_2::draw_name()
{
	pos = pos_0;
	SetConsoleCursorPosition(hout, pos);
	int j = 0;
	for (int i = 0; i < movies.size(); i++)
	{
		if (movies[i]->get_name() == name)
		{
			j++;
			pos.Y++;
			movies_2.push_back(movies[i]);
			cout << j << movies[i]->get_name() << "--" << movies[i]->get_hour() << ':';
			if (movies[i]->get_minute() < 10) cout << "0"<<movies[i]->get_minute();//防止出现8:0这种情况
			else cout << movies[i]->get_minute();
			cout << "  " << movies[i]->get_movietime() << " 价格：" << movies[i]->get_price();
			SetConsoleCursorPosition(hout, pos);
		}
	}
	cout << "返回";
}

void menu_2::draw_movie()
{
	judge_return_2 = 3;
	int i = movie_infor_number;
	e_movie = movies[i];
}

void menu_2::draw_goodmovie()
{
	judge_return_2 = 3;
	e_movie = movies_1[n_change - 1];
}

void menu_2::mouse_choose()
{
	INPUT_RECORD MouseRecord;
	DWORD ret;
	COORD newhome, oldhome = pos_0;
	DWORD oldset, newset;
	GetConsoleMode(hin, &oldset);
	newset = oldset;
	newset &= ~(ENABLE_QUICK_EDIT_MODE);
	SetConsoleMode(hin, newset);
	oldhome.Y -= 3; oldhome.X -= 3;
	while (1)
	{
		ReadConsoleInput(hin, &MouseRecord, 1, &ret);
		SetConsoleCursorPosition(hout, oldhome);
		if (MouseRecord.EventType == MOUSE_EVENT)
		{
			newhome = MouseRecord.Event.MouseEvent.dwMousePosition;
			if (mouse_infor == 11)
			{
				pos = pos_0;
				for (int i = 0; i <= movies_2.size(); i++)
				{
					if (newhome.Y == (pos.Y + i) && MouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						if (i == movies_2.size())
						{
							judge_return = 0; return;//给返回第一个菜单提示
						}
						get_movie_infor(i);
						e_movie = movies_2[i];
						judge_return_2 = 2;//给到底下一个菜单点击返回时是返回第一个还是第二个给提示
						return;
					}
				}
			}
			if (mouse_infor == 12)
			{
				pos = pos_0;
				for (int i = 0; i <= movies_2.size(); i++)
				{
					if (newhome.Y == (pos.Y + i) && MouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						if (i == movies_2.size())
						{
							judge_return = 0; return;
						}
						get_movie_infor(i);
						e_movie = movies_2[i];
						judge_return_2 = 2;//给到底下一个菜单点击返回时是返回第一个还是第二个给提示
						return;
					}
				}
			}
		}
	}
}

void menu_3::menu_03()
{
	draw(pos_0);
	mouse_choose();
}

void menu_3::draw(COORD pos)
{
	SetConsoleCursorPosition(hout, pos);
	for (int i = 0; i < 10000; i++)cout << ' ';
	draw_seat();
}

void menu_3::draw_seat()
{
	pos = pos_0;
	SetConsoleCursorPosition(hout, pos);
	cout << e_movie->get_name() << "--" << e_movie->get_hour() << ':';
	if (e_movie->get_minute() < 10)cout << "0" << e_movie->get_minute();//防止出现8:0这种情况
	else cout << e_movie->get_minute();
	cout << "  " << e_movie->get_movietime() << " 价格：" << e_movie->get_price();
	pos.Y++;
	SetConsoleCursorPosition(hout, pos);
	cout << "请选择座位：";
	pos.Y++; pos.X = pos_0.X;
	e_movie->get_Seat().draw_seat(pos, hout, pos_0.X);
}

void menu_3::mouse_choose()
{
	int judge = 0;//判断是否选了座位
	INPUT_RECORD MouseRecord;
	DWORD ret;
	COORD newhome, oldhome = pos_0;
	DWORD oldset, newset;
	GetConsoleMode(hin, &oldset);
	newset = oldset;
	newset &= ~(ENABLE_QUICK_EDIT_MODE);
	SetConsoleMode(hin, newset);
	oldhome.Y -= 3; oldhome.X -= 3;
	while (1)
	{
		ReadConsoleInput(hin, &MouseRecord, 1, &ret);
		SetConsoleCursorPosition(hout, oldhome);
		if (MouseRecord.EventType == MOUSE_EVENT)
		{
			newhome = MouseRecord.Event.MouseEvent.dwMousePosition;
			pos = pos_0;
			pos.Y += 2;
			for (int i = 0; i < 10; i++)
			{
				pos.Y += 2;pos.X = pos_0.X-6;
				for (int j = 0; j < 10; j++)
				{
					pos.X += 6;
					if (MouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED&&newhome.X <= (pos.X + 2) && newhome.X >= pos.X&&newhome.Y <= pos.Y&&newhome.Y >= (pos.Y - 1))
					{
						if (e_movie->get_Seat().get_seat(i,j) == 1)
						{
							judge--;
							SetConsoleCursorPosition(hout, pos);
							if (i >= 2 && i <= 5 && j <= 6 && j >= 3)SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							else SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
							cout << "|I|";
							e_movie->get_Seat().re_seat(i, j);
							seat_1.x[i][j] = 0;
						}
						else if(e_movie->get_Seat().get_seat(i, j) != 2&& e_movie->get_Seat().get_seat(i, j) == 0)
						{
							SetConsoleCursorPosition(hout, pos);
							SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED);
							cout << "|I|";
							SetConsoleTextAttribute(hout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							e_movie->get_Seat().set_seat(i + 1, j + 1);
							judge++;
							seat_1.x[i][j] = 1;
						}
					}
				}
			}
			pos.X = pos_0.X; pos.Y += 4;
			if (MouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED&&newhome.X <= (pos.X + 4) && newhome.X >= pos.X&&newhome.Y <= pos.Y&&newhome.Y >= (pos.Y - 1))
			{
				if (judge != 0)
				{
					e_movie->get_Seat().set_seat_clearly();
					return;
				}
				else
				{
					pos.X += 6;
					SetConsoleCursorPosition(hout, pos);
					SetConsoleTextAttribute(hout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "请选择座位";
					Sleep(1000);
					pos.X = pos_0.X + 6;
					SetConsoleCursorPosition(hout, pos);
					cout << "          ";
				}
			}
			pos.X = pos_0.X; pos.Y += 2;
			if (MouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED&&newhome.X <= (pos.X + 4) && newhome.X >= pos.X&&newhome.Y <= pos.Y&&newhome.Y >= (pos.Y - 1))
			{
				if (judge_return_2 == 2)judge_return_2 = 0;
				judge_return = 2;//排除第二个菜单的返回干扰，所以是2
				e_movie->get_Seat().re_all_seat();
				return;
			}
		}
	}
}

void menu_4::menu_04()
{
	draw(pos_0);
	change_movie_id();
}

void menu_4::draw(COORD pos)
{
	SetConsoleCursorPosition(hout, pos);
	for (int i = 0; i < 10000; i++)cout << ' ';
	pos.Y += 2;
	SetConsoleCursorPosition(hout, pos);
	cout << "正在确认中";
	srand((int)time(NULL));
	rand_inter = rand() % 10000 + 10000;
	SetConsoleCursorPosition(hout, { 0,2 });
	Sleep(3000);
	pos.Y -= 1;
	SetConsoleCursorPosition(hout, pos);
	cout << "你的进入凭证为：" << rand_inter;
	pos.Y -= 1;
	SetConsoleCursorPosition(hout, pos);
	cout << "欢迎下次光临";
}

void menu_4::change_movie_id()
{
	read_movie.close();
	read_movie.open("debug\\movieinfor.txt", ios::out | ios::trunc);
	if (!read_movie)cout << "失败";
	for (int i = 0; i < movies.size(); i++)
	{
		string content;
		char colon;
		double score;
		double o_price;
		content = movies[i]->get_name();
		score = movies[i]->get_socre();
		o_price = movies[i]->get_o_price();
		read_movie << content << endl << score << endl << o_price << endl << "5" << endl;
		read_movie << movies[i]->get_hour() << ' ' << movies[i]->get_minute() << ' ' << movies[i]->get_movietime() << ' ';
		seat Seat = movies[i]->get_Seat();
		for(int i=0;i<10;i++)
			for (int j = 0; j < 10; j++)
			{
				if (Seat.get_seat(i, j) == 2)
				{
					read_movie << (i + 1) << ' ' << (j + 1) << ' ';
				}
			}
		read_movie << "11" << endl << "5" << endl;
	}


	int i, j;
	int people = 0;
	log_system.open("debug\\manager_cus.txt", ios::app);
	log_system << endl <<"id："<< id << "   " <<"电影名："<< e_movie->get_name() << "   " <<"电影凭证："<< rand_inter << "   " <<"时间："<< e_movie->get_hour() << "." << e_movie->get_minute() << "   "<<"座位号：";
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			if (seat_1.x[i][j] == 1)
			{
				people++;
				log_system << i + 1 << "." << j + 1 << " ";
			}
		}
	log_system << 11;
	log_system.close();

	log_system.open("debug\\log.txt", ios::in);
	vector<string> tmp1;
	vector<string> tmp2;
	vector<double> tmp3;
	id_1.swap(tmp1);
	password_1.swap(tmp2);
	integral_1.swap(tmp3);
	string id_password_2;
	double integral_2;
	while (!log_system.eof())//把所有的数据收集
	{
		log_system >> id_password_2;
		id_1.push_back(id_password_2);
		log_system >> id_password_2;
		password_1.push_back(id_password_2);
		log_system >> integral_2;
		integral_1.push_back(integral_2);
	}
	log_system.close();
	for (i = 0; i < id_1.size(); i++)//修改数据
	{
		if (id == id_1[i] && password == password_1[i])
			break;
	}
	integral_1[i] = integral + e_movie->get_price()*people;
	log_system.open("debug\\log.txt", ios::out);
	for (i = 0; i < id_1.size()-1; i++)
	{
		log_system << id_1[i] << " " << password_1[i] << " " << integral_1[i] << endl;
	}
	log_system.close();


	man_money += people*e_movie->get_price();
	man_people += people;
	log_system.open("debug\\manageinfor.txt", ios::out);
	log_system << man_money << " ";
	log_system << man_people;
	log_system.close();
}

void menu_0::draw_log_register()
{
	pos_1 = pos_0;
	pos_1.X += 10;
	SetConsoleCursorPosition(hout, pos_1);
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	cout << "欢迎注册";
	pos_1.Y += 1; pos_1.X = pos_0.X;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "今天是" << year << "." << month << "." << day;
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	pos_1.Y += 1; 
	SetConsoleCursorPosition(hout, pos_1);
	cout << "请输入（账号6-15个英文或数字，密码6-15个英文或数字，中间无空格）";
	pos_1.Y += 1; pos_1.X = pos_0.X + 4;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "账号：";
	pos_1.Y += 1;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "密码：";
	pos_1.Y += 2; pos_1.X = pos_0.X;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "确认";
}

bool menu_0::log()
{
	log_system.open("debug\\log.txt", ios::in);
	string id_1;
	string password_1;
	if (id == special || password == special)
	{
		judge = 1;
		return true;
		log_system.close();
	}
	
	while (!log_system.eof())
	{
		log_system >> id_1;
		log_system >> password_1;
		log_system >> integral;
		if (id_1 == id&&password == password_1)break;
	}
	log_system.close();
	if (id_1 == id&&password == password_1&&!id.empty()&&!password.empty())return true;//防止出现空对空
	else return false;
}

bool menu_0::record()
{
	if (id.size() < 6 || password.size() < 6)
	{
		return false;
	}

	log_system.open("debug\\log.txt", ios::app);
	log_system << id << " " << password << " 0" << endl;
	log_system.close();
	return true;
}

void menu_0::draw_log()
{
	pos_1 = pos_0;
	pos_1.X += 10;
	SetConsoleCursorPosition(hout, pos_1);
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	cout << "欢迎光临浙江理工大学电影院";
	pos_1.Y += 1; pos_1.X = pos_0.X;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "今天是" << year << "." << month << "." << day;
	pos_1.Y += 1; pos_1.X = pos_0.X;
	SetConsoleCursorPosition(hout, pos_1);
	SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "请登录";
	pos_1.Y += 1; pos_1.X += 4;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "账号：";
	pos_1.Y += 1;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "密码：";
	pos_1.Y += 1; pos_1.X = pos_0.X;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "注册";
	pos_1.Y += 1;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "确认";
}

void menu_0::draw_clear()
{
	pos_1 = pos_0;
	for (; pos_1.Y <= pos_0.Y + 30; pos_1.Y++)
	{
		SetConsoleCursorPosition(hout, pos_1);
		for (int i = 0; i < 300; i++)
			cout << " ";
	}
}

void menu_0::draw_mouse()
{
	draw_clear();
	if (judge_log_re == 1)
	{
		draw_log();
		mouse_choose_log();
	}
	else if (judge_log_re == 2)
	{
		draw_log_register();
		mouse_choose_re();
	}
}

void menu_0::draw_manager()
{
	draw_clear();
	pos_1 = pos_0;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "---欢迎管理者---";
	pos_1.Y++;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "今天有顾客：" << man_people << "人";
	pos_1.Y++;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "今天收入：" << man_money << "元";
	pos_1.Y++;
	SetConsoleCursorPosition(hout, pos_1);
	cout << "有如下人员购买了票：";
	pos_1.Y++; pos_1.X += 10;
	SetConsoleCursorPosition(hout, pos_1);
	log_system.close();
	log_system.open("debug\\manager_cus.txt", ios::in);
	string content;
	log_system >> content;
	while (!log_system.eof())
	{
		log_system >> content;
		if (content == "11")
		{
			pos_1.Y++;
			SetConsoleCursorPosition(hout, pos_1);
		}
		else cout << content;
	}
	pos_1 = pos_0;
	pos_1.X -= 3; pos_1.Y -= 3;
	SetConsoleCursorPosition(hout, pos_1);
	Sleep(60000);
	log_system.close();
}

void menu_0::mouse_choose_log()
{
	INPUT_RECORD Record;
	DWORD ret;
	COORD newhome, oldhome = pos_0;
	COORD pos_Mouse_1, pos_Mouse_2;
	DWORD oldset, newset;
	int judge_VK_RETURN = 0;//判断是否按了返回按钮
	int judge_MOUSE = 0;//判断是按了哪一个鼠标按钮
	GetConsoleMode(hin, &oldset);
	newset = oldset;
	newset &= ~(ENABLE_QUICK_EDIT_MODE);
	SetConsoleMode(hin, newset);
	oldhome.Y -= 3; oldhome.X -= 3;
	pos_Mouse_1.X = pos_0.X + 10;//记录光标初始位置
	pos_Mouse_1.Y = pos_0.Y + 3;
	pos_Mouse_2.X = pos_0.X + 10;
	pos_Mouse_2.Y = pos_0.Y + 4;
	id.clear();
	password.clear();
	while (1)
	{
		ReadConsoleInput(hin, &Record, 1, &ret);
		SetConsoleCursorPosition(hout, oldhome);
		if (Record.EventType == MOUSE_EVENT)
		{
			newhome = Record.Event.MouseEvent.dwMousePosition;
			pos_1 = pos_0;
			

			pos_1.Y = pos_0.Y + 3;
			if (judge_MOUSE == 1 || (newhome.Y == pos_1.Y&&Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED))
			{
				CONSOLE_CURSOR_INFO cursor_info = { 1,1 };
				SetConsoleCursorInfo(hout, &cursor_info);
				if (judge_MOUSE != 0)judge_MOUSE = 0;
				pos_1 = pos_Mouse_1;
				while (1)
				{
					if (judge_VK_RETURN == 1 || judge_MOUSE != 0)
					{
						judge_VK_RETURN = 0;
						pos_Mouse_1 = pos_1;//记录光标位置
						break;
					}
					SetConsoleCursorPosition(hout, pos_1);
					ReadConsoleInput(hin, &Record, 1, &ret);
					if (Record.EventType == KEY_EVENT)
					{
						if (Record.Event.KeyEvent.bKeyDown)
						{
							if (Record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
							{
								judge_VK_RETURN = 1;
							}
							else if (Record.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
							{
								if (pos_1.X > pos_0.X + 10)pos_1.X -= 1;
								SetConsoleCursorPosition(hout, pos_1);
								cout << " ";
								id = id.substr(0, id.size()-1);
							}
							else
							{
								pos_1.X += 1;
								char c = Record.Event.KeyEvent.uChar.AsciiChar;
								cout << c;
								id += c;
							}
						}
					}
					if (Record.EventType == MOUSE_EVENT)
					{
						newhome = Record.Event.MouseEvent.dwMousePosition;

						SetConsoleCursorPosition(hout, oldhome);

						if (newhome.Y == (pos_0.Y + 4) && Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
						{
							judge_MOUSE = 2;
						}
						else if (newhome.Y == (pos_0.Y + 5) && Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
						{
							judge_MOUSE = 3;
						}
						else if (newhome.Y == (pos_0.Y + 6) && Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
						{
							judge_MOUSE = 4;
						}
					}
				}
				cursor_info = { 1,0 };
				SetConsoleCursorInfo(hout, &cursor_info);
			}

			pos_1.Y = pos_0.Y + 4;
			if (judge_MOUSE == 2 || (newhome.Y == pos_1.Y&&Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED))
			{
				CONSOLE_CURSOR_INFO cursor_info = { 1,1 };
				SetConsoleCursorInfo(hout, &cursor_info);
				if (judge_MOUSE != 0)judge_MOUSE = 0;
				pos_1 = pos_Mouse_2;
				while (1)
				{
					if (judge_VK_RETURN == 1 || judge_MOUSE != 0)
					{
						judge_VK_RETURN = 0;
						pos_Mouse_2 = pos_1;
						break;
					}
					SetConsoleCursorPosition(hout, pos_1);
					ReadConsoleInput(hin, &Record, 1, &ret);
					if (Record.EventType == KEY_EVENT)
					{
						if (Record.Event.KeyEvent.bKeyDown)
						{
							if (Record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
							{
								judge_VK_RETURN = 1;
							}
							else if (Record.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
							{
								if (pos_1.X > pos_0.X + 10)pos_1.X -= 1;
								SetConsoleCursorPosition(hout, pos_1);
								cout << " ";
								password = password.substr(0, password.length() - 1);
							}
							else
							{
								pos_1.X += 1;
								char c = Record.Event.KeyEvent.uChar.AsciiChar;
								cout << c;
								password += c;
							}
						}
					}
					if (Record.EventType == MOUSE_EVENT)
					{
						newhome = Record.Event.MouseEvent.dwMousePosition;

						SetConsoleCursorPosition(hout, oldhome);

						if (newhome.Y == (pos_0.Y + 3) && Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
						{
							judge_MOUSE = 1;
						}
						else if (newhome.Y == (pos_0.Y + 5) && Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
						{
							judge_MOUSE = 3;
						}
						else if (newhome.Y == (pos_0.Y + 6) && Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
						{
							judge_MOUSE = 4;
						}
					}
				}
				cursor_info = { 1,0 };
				SetConsoleCursorInfo(hout, &cursor_info);
			}

			pos_1.Y = pos_0.Y + 5;
			if (judge_MOUSE == 3 || (newhome.Y == pos_1.Y&&Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED))
			{
				judge_log_re = 2;
				return;
			}

			pos_1.Y = pos_0.Y + 6;
			if (judge_MOUSE == 4 || (newhome.Y == pos_1.Y&&Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED))
			{
				if (judge_MOUSE != 0)judge_MOUSE = 0;
				if (log())
				{
					judge_log_re = 0;
					return;
				}
				pos_1.X = pos_0.X + 10;
				SetConsoleCursorPosition(hout, pos_1);
				cout << "输入错误，请重新输入";
				Sleep(3000);
				SetConsoleCursorPosition(hout, pos_1);
				cout << "                    ";
			}
		}
	}
}

void menu_0::mouse_choose_re()
{
	INPUT_RECORD Record;
	DWORD ret;
	COORD newhome, oldhome = pos_0;
	COORD pos_Mouse_1, pos_Mouse_2;
	DWORD oldset, newset;
	int judge_VK_RETURN = 0;
	int judge_MOUSE = 0;
	GetConsoleMode(hin, &oldset);
	newset = oldset;
	newset &= ~(ENABLE_QUICK_EDIT_MODE);
	SetConsoleMode(hin, newset);
	oldhome.Y -= 3; oldhome.X -= 3;
	pos_Mouse_1.X = pos_0.X + 10;//记录输入时光标初始位置
	pos_Mouse_1.Y = pos_0.Y + 3;
	pos_Mouse_2.X = pos_0.X + 10;
	pos_Mouse_2.Y = pos_0.Y + 4;
	id.clear();
	password.clear();
	while (1)
	{
		ReadConsoleInput(hin, &Record, 1, &ret);
		SetConsoleCursorPosition(hout, oldhome);
		if (Record.EventType == MOUSE_EVENT)
		{
			newhome = Record.Event.MouseEvent.dwMousePosition;
			pos_1 = pos_0;

			pos_1.Y = pos_0.Y + 3;
			if (judge_MOUSE == 1 || (newhome.Y == pos_1.Y&&Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED))
			{
				CONSOLE_CURSOR_INFO cursor_info = { 1,1 };
				SetConsoleCursorInfo(hout, &cursor_info);
				if (judge_MOUSE != 0)judge_MOUSE = 0;
				pos_1 = pos_Mouse_1;
				while (1)
				{
					if (judge_VK_RETURN == 1 || judge_MOUSE != 0)
					{
						judge_VK_RETURN = 0;
						pos_Mouse_1 = pos_1;//记录光标位置
						break;
					}
					SetConsoleCursorPosition(hout, pos_1);
					ReadConsoleInput(hin, &Record, 1, &ret);
					if (Record.EventType == KEY_EVENT)
					{
						if (Record.Event.KeyEvent.bKeyDown)
						{
							if (Record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
							{
								judge_VK_RETURN = 1;
							}
							else if (Record.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
							{
								if (pos_1.X > pos_0.X + 10)pos_1.X -= 1;
								SetConsoleCursorPosition(hout, pos_1);
								cout << " ";
								id = id.substr(0, (id.length() - 1));
							}
							else
							{
								pos_1.X += 1;
								char c = (char)Record.Event.KeyEvent.uChar.UnicodeChar;
								cout << c;
								id += c;
							}
						}
					}
					if (Record.EventType == MOUSE_EVENT)
					{
						newhome = Record.Event.MouseEvent.dwMousePosition;

						SetConsoleCursorPosition(hout, oldhome);

						if (newhome.Y == (pos_0.Y + 4) && Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
						{
							judge_MOUSE = 2;
						}
						if (newhome.Y == (pos_0.Y + 6) && Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
						{
							judge_MOUSE = 3;
						}
					}
				}
				cursor_info = { 1,0 };
				SetConsoleCursorInfo(hout, &cursor_info);
			}

			pos_1.Y = pos_0.Y + 4;
			if (judge_MOUSE == 2 || (newhome.Y == pos_1.Y&&Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED))
			{
				CONSOLE_CURSOR_INFO cursor_info = { 1,1 };
				SetConsoleCursorInfo(hout, &cursor_info);
				if (judge_MOUSE != 0)judge_MOUSE = 0;
				pos_1 = pos_Mouse_2;
				while (1)
				{
					if (judge_VK_RETURN == 1 || judge_MOUSE != 0)
					{
						judge_VK_RETURN = 0;
						pos_Mouse_2 = pos_1;
						break;
					}
					SetConsoleCursorPosition(hout, pos_1);
					ReadConsoleInput(hin, &Record, 1, &ret);
					if (Record.EventType == KEY_EVENT)
					{
						if (Record.Event.KeyEvent.bKeyDown)
						{
							if (Record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
							{
								judge_VK_RETURN = 1;
							}
							else if (Record.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
							{
								if (pos_1.X > pos_0.X + 10)pos_1.X -= 1;
								SetConsoleCursorPosition(hout, pos_1);
								cout << " ";
								password = password.substr(0, (password.size() - 1));
							}
							else
							{
								pos_1.X += 1;
								char c = (char)Record.Event.KeyEvent.uChar.UnicodeChar;
								cout << c;
								password += c;
							}
						}
					}
					if (Record.EventType == MOUSE_EVENT)
					{
						newhome = Record.Event.MouseEvent.dwMousePosition;

						SetConsoleCursorPosition(hout, oldhome);

						if (newhome.Y == (pos_0.Y + 3) && Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
						{
							judge_MOUSE = 1;
						}
						if (newhome.Y == (pos_0.Y + 6) && Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
						{
							judge_MOUSE = 3;
						}
					}
				}
				cursor_info = { 1,0 };
				SetConsoleCursorInfo(hout, &cursor_info);
			}

			pos_1.Y = pos_0.Y + 6;
			if (judge_MOUSE == 3 || (newhome.Y == pos_1.Y&&Record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED))
			{
				if (record())
				{
					judge_log_re = 1;
					return;
				}
				pos_1.X = pos_0.X + 10;
				SetConsoleCursorPosition(hout, pos_1);
				cout << "输入有误";
				Sleep(3000);
				SetConsoleCursorPosition(hout, pos_1);
				cout << "        ";
			}

		}
	}
}

void menu_0::menu_00(int x, int y)
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(hout, &cursor_info);
	pos_0.X = x; pos_0.Y = y;
	while (judge_log_re != 0)
	{
		draw_mouse();
		if (judge == 1)
		{
			judge_log_re = 1;
			judge = 0;//使管理人员完成操作后可以返回去
			draw_manager();
		}
	}
}
