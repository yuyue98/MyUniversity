#include "Dish.h"

Dish::Dish(string name,double price,double discount):Price(0.0),Discount(1.0) {
	setName(name);
	setPrice(price);
	setDiscount(discount);
}

Dish::~Dish() {
}

bool Dish::setPrice(double price) {
	if (price<0.0) {
		return false;
	} else {
		Price = 1.0*price;
		return true;
	}
}

bool Dish::setDiscount(double discount) {
	if(discount<0.0||discount>100.0) {
		return false;
	} else if (discount>1.0) {
		Discount = 1.0*discount*0.01;
	} else {
		Discount = 1.0*discount;
	}
	return true;
}

void Dish::display() {
	putStr(Name,DISHNAMELEN-1);
	putStr(toString(Price),6);
	putStr(toString(Discount),9);
	cout<<endl; 
};
