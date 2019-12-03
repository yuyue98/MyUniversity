#include "TakeoutIndent.h"

double TakeoutIndent::TPrice = 20.0;

TakeoutIndent::TakeoutIndent(double dropofftime,string dropoffplace,string phonenum):Indent(),DropoffTime(0) {
	setDropoffTime(dropofftime);
	setDropoffPlace(dropoffplace);
	setPhoneNum(phonenum);
}

TakeoutIndent::TakeoutIndent(vector<DishItem*>& itemlist,double dropofftime,string dropoffplace,string phonenum):Indent(itemlist),DropoffTime(0) {
	setDropoffTime(dropofftime);
	setDropoffPlace(dropoffplace);
	setPhoneNum(phonenum);
}

TakeoutIndent::~TakeoutIndent() {
}

bool TakeoutIndent::setTPrice(double price) {
	if (price<0.0) {
		return false;
	} 
	TPrice =1.0*price;
	return true;
}

bool TakeoutIndent::setDropoffTime(double dropofftime) {
	if (dropofftime<0) {
		return false;
	}
	DropoffTime = dropofftime;
	return true;
}

void TakeoutIndent::putIndent() {
	putStr(getID(),INDENTIDLEN-1);
	putStr(toString(getPrice()+TPrice),7);
	putStr("外卖",5);
	cout<<endl;
}

void TakeoutIndent::display() {
	cout<<"+++++++++++++++++++++外卖订单内容+++++++++++++++++++++"<<endl;
	cout<<"订单编号："<<getID();
	if (0==getOrderTime()) {
		cout<<"(未下单)"<<endl;
	} else {
		cout<<"(已下单)"<<endl;
		time_t t = getOrderTime();
		cout<<"下单时间："<<ctime(&t);
	}
	cout<<"送货时间："<<DropoffTime<<"min"<<endl;
	cout<<"送货地点："<<DropoffPlace<<endl;
	cout<<"手机号："<<PhoneNum<<endl<<endl;; 
	Indent::putBody();
	if (0==DropoffTime) {
		cout<<"总价："<<getPrice()<<endl;
	} else {
		cout<<"外卖服务费："<<TPrice<<endl; 
		cout<<"总价："<<getPrice()+TPrice<<endl;
	}
}
