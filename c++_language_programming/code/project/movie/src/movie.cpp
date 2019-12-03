#include "movie.h"
#include<math.h>

void movie::insert_movies()
{
	int x, y;
	string judge;
	double money, money_1;
	for (int i = 1;; i++)
	{
		if (read_movie.eof())break;
		if (i % 2 == 0)
		{
			while (read_movie >> hour)
			{
				movie* movie_push=new movie;
				seat Seat;
				if (hour == 5)
				{
					getline(read_movie, name);
					break;
				}
				read_movie >> minute >> movietime;
				while (read_movie >> x)
				{
					if (x == 11)break;
					read_movie >> y;
					Seat.set_seat(x, y);
				}
				movie_push->set_Seat(Seat);
				movie_push->settime(hour, minute, movietime);
				movie_push->set_score(score);
				movie_push->setname(name);
				movie_push->seto_price(money);
				money = money_1;
				money = money+money*(sqrt(movie_push->get_hour() - 8)*0.3);
				movie_push->setprice(money);
				movie_push->get_Seat().set_seat_clearly();
				movies.push_back(movie_push);
			}
		}
		else
		{
			getline(read_movie, name);
			read_movie >> score;
			read_movie >> money;
			money_1 = money;
			read_movie >> judge;
		}
	}
}

void movie::settime(int hour, int minute, int movietime)
{
	this->hour = hour;
	this->minute = minute;
	this->movietime = movietime;
}

void movie::setname(string name)
{
	this->name = name;
}

void movie::setprice(double price)
{
	this->price = price;
}

void movie::seto_price(double o_price)
{
	this->o_price = o_price;
}

ostream & operator<<(ostream & os, movie movie1)
{
	os << movie1.get_name() << "--" << movie1.get_hour() << ';';
	if (movie1.get_minute() < 10)os << "0" << movie1.get_minute();
	else os << movie1.get_minute();
	os << "  " << movie1.get_movietime() << "价格：" << movie1.get_price();
	return os;
}
