#include "Indent.h"

void Indent::initItem() {
	SYSTEMTIME sys_time;
    GetLocalTime(&sys_time);
	sprintf(ID,"%04d%02d%02d%02d%02d%02d%03d",sys_time.wYear,sys_time.wMonth,sys_time.wDay,sys_time.wHour,sys_time.wMinute,sys_time.wSecond,sys_time.wMilliseconds);
	OrderTime=0;
	countPrice();
}

void Indent::countPrice() {
	Price = 0.0;
	if (!ItemList.empty()) {
		for (int i;i<ItemList.size();i++) {
			Price += ItemList[i]->getPrice();
		}
	}
}

Indent::Indent() {
	initItem();
}

Indent::Indent(vector<DishItem*>& itemlist):ItemList(itemlist) {
	initItem();
}

Indent::~Indent() {
	clear();
}

DishItem* Indent::operator[](int id) {
	if (ItemList.empty()||id<0||id>=ItemList.size()) {
		return nullptr;
	} else {
		return ItemList[id];
	}
}

bool Indent::DeleteItemWithNo(int id) {
	if (ItemList.empty()||id<0||id>=ItemList.size()) {
		return false;
	}
	vector<DishItem*>::iterator pd = ItemList.begin()+id;
	if (ItemList[id]) {
		delete ItemList[id];
		ItemList[id] = nullptr;
	}
	ItemList.erase(pd);
	return true;
}

int Indent::SearchItemWithName(string name) {
	if (ItemList.empty()) {
		return -1;
	}
	for (int i=0;i<ItemList.size();i++) {
		if (name==ItemList[i]->getDish()->getName()) {
			return i;
		}
	}
	return -1;
}

bool Indent::DeleteItemWithName(string name) {
	int i = SearchItemWithName(name);
	if (-1==i) {
		return false;
	}
	vector<DishItem*>::iterator pd = ItemList.begin()+i;
	if (ItemList[i]) {
		delete ItemList[i];
		ItemList[i] = nullptr;
	}
	ItemList.erase(pd);
	return true;
}

void Indent::addDish(int id) {
	ItemList[id]->addNum();
	countPrice(); 
}

void Indent::subDish(int id) {
	bool flag = ItemList[id]->subNum();
	if (!flag) {
		DeleteItemWithNo(id);
	}
	countPrice();
}

bool Indent::setPrice(double price) {
	if (price<0.0) {
		return false;
	} else {
		Price = 1.0*price;
		return true;
	}
	
}

bool Indent::setItemList(vector<DishItem*>& itemlist) {
	try {
		ItemList = itemlist;
		return true;
	} catch(...) {
		return false;
	}
}

bool Indent::setItem(DishItem* dishitem) {
	try {
		int i;
		if ((i=SearchItemWithName(dishitem->getDish()->getName()))!=-1) {
			ItemList[i]->setNum((ItemList[i]->getNum())+(dishitem->getNum()));
		} else {
			ItemList.push_back(dishitem);
		}
		countPrice();
		return true;
	} catch(...) {
		return false;
	}
}

bool Indent::setItem(Dish* dish,int num) {
	try {
		DishItem* pd = new DishItem(dish,num,num*dish->getGPrice());
		setItem(pd);
		return true;	
	} catch(...) {
		return false;
	}
}

void Indent::clear() {
	for (int i=0;i<ItemList.size();i++) {
		if (ItemList[i]) {
			delete ItemList[i];
			ItemList[i] = nullptr;
		}
	}
	ItemList.clear();
}

void Indent::putIndent() {
	putStr(ID,INDENTIDLEN-1);
	putStr(toString(Price),7);
	putStr("未知",5);
	cout<<endl;
}

void Indent::putBody() {
	cout<<"订单条目："<<endl; 
	putStr("No",3);
	putStr("Name",DISHNAMELEN-1);
	putStr("Price",6);
	putStr("DCT",4);
	putStr("Num",4);
	putStr("APrice",7);
	cout<<endl;
	for (int i=0;i<ItemList.size();i++) {
		putStr(toString(i),3);
		ItemList[i]->display();
	}
	cout<<endl;
} 

void Indent::display() {
	cout<<"+++++++++++++++++++++++订单内容+++++++++++++++++++++++"<<endl;
	cout<<"订单编号："<<ID;
	if (0==OrderTime) {
		cout<<"(未下单)"<<endl<<endl;;
	} else {
		cout<<"(已下单)"<<endl;
		cout<<"下单时间："<<ctime(&OrderTime)<<endl;
	}
	putBody();
	cout<<"总价："<<Price<<endl;
}

