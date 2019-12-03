#include "CCar.h"

CCar::CCar(string cid,string brand,string color,string vin):CID(cid),Owner(NULL),Brand(brand),Color(color),VIN(vin) {
	cout<<this<<": "<<"car begin!"<<endl;
}

CCar::CCar(string cid,CPerson& owner,string brand,string color,string vin):CID(cid),Owner(&owner),Brand(brand),Color(color),VIN(vin) {
	cout<<this<<": "<<"car begin!"<<endl;
}

CCar::~CCar() {
	cout<<this<<": "<<"car end!"<<endl;
}

void CCar::putCar() const {
	cout<<"This car's information is as follows: "<<endl;
	cout<<"CID: "<<CID<<endl;
	cout<<"Brand: "<<Brand<<endl;
	cout<<"Color: "<<Color<<endl;
	cout<<"VIN: "<<VIN<<endl;
}

void CCar::putOwner() const {
	cout<<"Owner: ";
	if (Owner==NULL)
		cout<<"无";
	else
		Owner->putPerson();
	cout<<endl;
}

void CCar::putAll() const {
	putCar();
	putOwner();
}
