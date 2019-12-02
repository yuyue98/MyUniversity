#ifndef HOTELMANAGE_H
#define HOTELMANAGE_H

void endry();
void init();
void menu1();
void menu21();
void ent();
int freefind();
void del();
void pri();
void menu22();
void list();
void numfind();
void typfind();
void prilist();
void menu23();
void numget();
void typget();
void priget();
void back();
void save();
void load();
void check();
void checkzero(); 
struct hotel
{
	int number;
	char type[1];
	int price[2];
	char black[1]; 	
}room[MAX];

#endif