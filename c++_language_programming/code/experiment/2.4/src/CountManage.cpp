#include "CountManage.h"

void CountManage::countPrice() {
	Price = 0.0;
	if (!ItemList.empty()) {
		for (int i;i<ItemList.size();i++) {
			Price += ItemList[i]->getPrice();
		}
	}
	Price += ENum*EatinIndent::getRPrice()+TNum*TakeoutIndent::getTPrice();
}

CountManage::CountManage(string filename):FileName(filename),Num(0),ENum(0),TNum(0),Price(0.0),EPrice(0.0),TPrice(0.0) {
	if (""==FileName) {
		FileName = getFilename();
	}
}

CountManage::CountManage(string filename,int num,int Enum,int Tnum,double price,double Eprice,double Tprice,vector<DishItem*> itemlist) {
	FileName = filename;	
	Num = num;
	ENum = Enum;
	TNum = Tnum;
	Price = price;
	EPrice = Eprice;
	TPrice = Tprice;
	ItemList = itemlist;
}

CountManage::~CountManage() {
	clear();
}

string CountManage::getFilename() {
	time_t mytime = time(nullptr);
	tm* mytm = localtime(&mytime);
	char thetime[11];
	sprintf(thetime,"%04d-%02d-%02d\0",1900+(mytm->tm_year),1+(mytm->tm_mon),mytm->tm_mday);
	string theTime = thetime;
	return (theTime+".dat");
}

DishItem* CountManage::operator[](int id) {
	if (ItemList.empty()||id<0||id>=ItemList.size()) {
		return nullptr;
	} else {
		return ItemList[id];
	}
}


bool CountManage::DeleteItemWithNo(int id) {
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

int CountManage::SearchItemWithName(string name) {
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

bool CountManage::DeleteItemWithName(string name) {
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

bool CountManage::setItemList(vector<DishItem*> itemlist) {
	try {
		ItemList = itemlist;
		return true;
	} catch(...) {
		return false;
	}
} 

bool CountManage::setItem(DishItem* dishitem) {
	try {
		int i;
		if ((i=SearchItemWithName(dishitem->getDish()->getName()))!=-1) {
			ItemList[i]->setNum((ItemList[i]->getNum())+(dishitem->getNum()));
			delete dishitem;
			dishitem = nullptr;
		} else {
			ItemList.push_back(dishitem);
		}
		countPrice();
		return true;
	} catch(...) {
		return false;
	}
}

bool CountManage::setItem(Dish* dish,int num) {
	try {
		DishItem* pd = new DishItem(dish,num,num*dish->getGPrice());
		setItem(pd);
		return true;	
	} catch(...) {
		return false;
	}
}

bool CountManage::setNum(int num) {
	if (num<0) {
		return false;
	}
	Num += num;
	return true;
}

bool CountManage::setENum(int Enum) {
	if (Enum<0) {
		return false;
	}
	ENum += Enum;
	Num += Enum;
	int num = getMAXcommon(ENum,TNum);
	
	return true;	
}

bool CountManage::setTNum(int Tnum) {
	if (Tnum<0) {
		return false;
	}
	TNum += Tnum;
	Num += Tnum;
	return true;	
}

bool CountManage::setPrice(double price) {
	if (price<0.0) {
		return false;
	}
	Price += price;
	return true;
}

bool CountManage::setEPrice(double Eprice) {
	if (Eprice<0.0) {
		return false;
	}
	EPrice += Eprice;
	Price += Eprice;
	return true;
	
}

bool CountManage::setTPrice(double Tprice) {
	if (Tprice<0.0) {
		return false;
	}
	TPrice += Tprice;
	Price += Tprice;
	return true;
}

bool CountManage::countIndent(vector<Indent*>& indentlist) {
	for (int i=0;i<indentlist.size();i++) {
		countIndent(indentlist[i]);
	}
	return true;
}

bool CountManage::countIndent(Indent* indent) {
	try{
		if ('I'==indent->getType()) {
			setNum(1);
			setPrice(indent->getPrice());
		} else if ('E'==indent->getType()) {
			setENum(1);
			setEPrice(indent->getPrice()+EatinIndent::getRPrice());
		} else if ('T'==indent->getType()) {
			setTNum(1);
			setTPrice(indent->getPrice()+TakeoutIndent::getTPrice());
		}
		Dish* dish;
		for (int i=0;i<(indent->getItemList()).size();i++) {
			dish = ((indent->getItemList())[i])->getDish();
			setItem(dish,((indent->getItemList())[i])->getNum());
		}
		return true;
	} catch(...) {
		return false;
	}
	
}

void CountManage::clear() {
	FileName = getFilename();
	Num = 0;
	ENum = 0;
	TNum = 0;
	Price = 0;
	EPrice = 0;
	TPrice = 0;
	for (int i=0;i<ItemList.size();i++) {
		if (ItemList[i]) {
			delete ItemList[i];
			ItemList[i] = nullptr;
		}
	}
	ItemList.clear();
}

void CountManage::putBody() {
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

void CountManage::display() {
	cout<<"++++++++++++++++"<<FileName<<"订单统计++++++++++++++++"<<endl;
	cout<<"ANum："<<Num<<"\t"<<"APrice："<<Price<<endl;
	cout<<"ENum："<<ENum<<"\t"<<"EPrice："<<EPrice<<endl;
	cout<<"TNum："<<TNum<<"\t"<<"TPrice："<<TPrice<<endl;
	int num = getMAXcommon(ENum,TNum);
	if (0==ENum||0==TNum) cout<<"E_TScale："<<ENum<<":"<<TNum<<endl;
	else cout<<"E_TScale："<<ENum/num<<":"<<TNum/num<<endl;
	putBody();
}
