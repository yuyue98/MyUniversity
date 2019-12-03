#include "CCar.h"

CCar::CCar(string cid,string brand,string color,string vin):CVehicle(cid,brand,color,vin) {
	cout<<this<<": "<<"car begin!"<<endl;
}

CCar::CCar(CPerson& owner,string cid,string brand,string color,string vin):CVehicle(owner,cid,brand,color,vin) {
	cout<<this<<": "<<"car begin!"<<endl;
}

CCar::CCar(CPerson& owner,CPerson& driver,string cid,string brand,string color,string vin):CVehicle(owner,driver,cid,brand,color,vin) {
	cout<<this<<": "<<"car begin!"<<endl;
}

CCar::~CCar() {
	cout<<this<<": "<<"car end!"<<endl;
}

void CCar::putAll() const {
	cout<<"This is a car!"<<endl;
	CVehicle::putAll();
}
