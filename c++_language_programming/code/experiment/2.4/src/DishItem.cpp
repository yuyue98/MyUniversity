#include "DishItem.h"

DishItem::DishItem(Dish* dish,int num,double price):theDish(dish),Num(1),Price(dish->getGPrice()) {
	setNum(num);
	setPrice(price);
}

DishItem::~DishItem() {
}

bool DishItem::setDish(Dish* dish) {
	try {
		theDish = dish;
		setPrice(1.0*Num*(theDish->getGPrice()));
		return true;
	} catch(...) {
		return false;
	}
}

bool DishItem::setNum(int num) {
	if (num<0) {
		return false;
	}
	Num = num;
	setPrice(1.0*Num*(theDish->getGPrice()));
	return true;
}

bool DishItem::setPrice(double price) {
	if (price<0.0) {
		return false;
	}
	Price = price;
	return true;
}

void DishItem::addNum() {
	Num++;
	setPrice(Price+(theDish->getGPrice()));
}

bool DishItem::subNum() {
	Num--;
	if (Num<=0) {
		Num = 0;
		Price = 0;
		return false;
	}
	setPrice(Price-(theDish->getGPrice()));
	return true;
}

void DishItem::display() {
	putStr(theDish->getName(),DISHNAMELEN-1);
	putStr(toString(theDish->getPrice()),6);
	putStr(toString(theDish->getDiscount()),4);
	putStr(toString(Num),4);
	putStr(toString(Price),7);
	cout<<endl;
}
