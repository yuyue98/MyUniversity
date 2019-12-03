#include "CBus.h"

CBus::CBus(string bid,string brand,string color,string vin):CVehicle(bid,brand,color,vin) {
	cout<<this<<": "<<"bus begin!"<<endl;
}

CBus::CBus(CPerson& owner,string bid,string brand,string color,string vin):CVehicle(owner,bid,brand,color,vin) {
	cout<<this<<": "<<"bus begin!"<<endl;
}

CBus::CBus(CPerson& owner,CPerson& driver,string bid,string brand,string color,string vin):CVehicle(owner,driver,bid,brand,color,vin) {
	cout<<this<<": "<<"bus begin!"<<endl;
}

CBus::~CBus() {
	cout<<this<<": "<<"bus end!"<<endl;
}

void CBus::putAll() const {
	cout<<"This is a bus!"<<endl;
	CVehicle::putAll();
}
