#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include"seat.h"
using namespace std;


class movie
{
private:
	string name;
	int minute, hour;
	int movietime;
	double score;
	double price;
	double o_price;
	seat Seat;
protected:
	vector<movie*> movies;
	fstream read_movie;
public:
	movie()
	{
		read_movie.open("debug\\movieinfor.txt", ios::in);
		if (!read_movie)cout << "打开失败" << endl;
	}
	~movie()
	{
		read_movie.close();
	}
	void insert_movies();

	string get_name() { return name; }
	int get_hour() { return hour; }
	//void set_hour(int hour) { this->hour = hour; }
	int get_minute() { return minute; }
	//void set_minute(int minute) { this->minute = minute; }
	int get_movietime() { return movietime; }
	//void set_movietime() { this->movietime = movietime; }
	double get_socre() { return score; }
	double get_price() { return price; }
	double get_o_price() { return o_price; }
	void set_score(double score) { this->score = score; }
	void settime(int hour,int minute,int movietime);
	void setname(string name);
	void setprice(double price);
	void seto_price(double o_price);
	seat& get_Seat() { return Seat; };
	void set_Seat(seat Seat) { this->Seat = Seat; }
	friend ostream& operator<<(ostream& os,movie movie1);
};
