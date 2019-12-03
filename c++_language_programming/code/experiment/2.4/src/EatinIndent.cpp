#include "EatinIndent.h"

double EatinIndent::RPrice = 20.0;

EatinIndent::EatinIndent(string tid,bool isroom):Indent(),isRoom(isroom) {
	setTID(tid);
}

EatinIndent::EatinIndent(vector<DishItem*>& itemlist,string tid,bool isroom):Indent(itemlist),isRoom(isroom) {
	setTID(tid);
}


EatinIndent::~EatinIndent() {
}

bool EatinIndent::setRPrice(double price) {
	if (price<0.0) {
		return false;
	} 
	RPrice =1.0*price;
	return true;
} 

void EatinIndent::putIndent() {
	putStr(getID(),INDENTIDLEN-1);
	putStr(toString(getPrice()+RPrice),7);
	putStr("堂食",5);
	cout<<endl;
}

void EatinIndent::display() {
	cout<<"+++++++++++++++++++++堂食订单内容+++++++++++++++++++++"<<endl;
	cout<<"订单编号："<<getID();
	if (0==getOrderTime()) {
		cout<<"(未下单)"<<endl;
	} else {
		cout<<"(已下单)"<<endl;
		time_t t = getOrderTime();
		cout<<"下单时间："<<ctime(&t);
	}
	if (isRoom) {
		cout<<"房间号："<<TID<<endl<<endl;
	} else {
		cout<<"桌号："<<TID<<endl<<endl;
	}
	Indent::putBody();
	if (isRoom) {
		cout<<"房费："<<RPrice<<endl;
		cout<<"总价："<<getPrice()+RPrice<<endl;
	} else {
		cout<<"总价："<<getPrice()<<endl;
	} 
} 
