#include "MenuManage.h"

MenuManage::MenuManage() {
}

MenuManage::MenuManage(vector<Dish*>& dishlist):DishList(dishlist) {
}

MenuManage::~MenuManage() {
	clear();
}

Dish* MenuManage::operator[](int id) {
	if (DishList.empty()||id<0||id>=DishList.size()) {
		return nullptr;
	} else {
		return DishList[id];
	}
}

bool MenuManage::DeleteDishWithNo(int id) {
	if (DishList.empty()||id<0||id>=DishList.size()) {
		return false;
	}
	vector<Dish*>::iterator pd = DishList.begin()+id;
	if (DishList[id]) {
		delete DishList[id];
		DishList[id] = nullptr;
	}
	DishList.erase(pd);
	return true;
}

int MenuManage::SearchDishWithName(string name) {
	if (DishList.empty()) {
		return -1;
	}
	for (int i=0;i<DishList.size();i++) {
		if (name==DishList[i]->getName()) {
			return i;
		}
	}
	return -1;
}

bool MenuManage::DeleteDishWithName(string name) {
	int i = SearchDishWithName(name);
	if (-1==i) {
		return false;
	}
	vector<Dish*>::iterator pd = DishList.begin()+i;
	if (DishList[i]) {
		delete DishList[i];
		DishList[i] = nullptr;
	}
	DishList.erase(pd);
	return true;
}

bool MenuManage::setDishList(vector<Dish*>& dishlist) {
	try {
		DishList = dishlist;
		return true;
	} catch(...) {
		return false;
	}
}

bool MenuManage::setDish(Dish* dish) {
	try {
		int i;
		if ((i=SearchDishWithName(dish->getName()))!=-1) {
			Dish* pd = DishList[i];
			DishList[i] = dish;
			if (nullptr!=pd) {
				delete pd;
			}
		} else {
			DishList.push_back(dish);
		}
		return true;
	} catch(...) {
		return false;
	}
}

bool MenuManage::setDish(string name,double num,double price) {
	try {
		Dish* pd = new Dish(name,num,price);
		setDish(pd);
		return true;	
	} catch(...) {
		return false;
	}
	
}

void MenuManage::clear() {
	for (int i=0;i<DishList.size();i++) {
		if (DishList[i]) {
			delete DishList[i];
			DishList[i] = nullptr;
		}
	}
	DishList.clear();
}

void MenuManage::display() {
	if (DishList.empty()) {
		cout<<"当前菜单没有内容！"<<endl;
		return;
	}
	cout<<"++++++++++++++++菜单内容++++++++++++++++"<<endl;
	putStr("No",3);
	putStr("Name",DISHNAMELEN-1);
	putStr("Price",6);
	putStr("Discount",9);
	cout<<endl;
	for (int i=0;i<DishList.size();i++) {
		putStr(toString(i),3);
		DishList[i]->display();
	}
}
