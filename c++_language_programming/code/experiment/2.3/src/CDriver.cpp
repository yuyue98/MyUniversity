#include "CDriver.h"

CDriver::CDriver(string id,string name,int age,string gender):Time(nullptr),CPerson(id,name,age,gender) {
	cout<<this<<": "<<"driver begin!"<<endl;
}

CDriver::CDriver(DivLicTime& time,string id,string name,int age,string gender):Time(&time),CPerson(id,name,age,gender) {
	cout<<this<<": "<<"driver begin!"<<endl;
}

CDriver::~CDriver() {
	cout<<this<<": "<<"driver end!"<<endl;
	if (Time!=nullptr) {
		delete Time;
	}
}

void CDriver::putAll() const {
	CPerson::putPerson();
//	cout<<"This driver's information is as follows: "<<endl;
	if (Time==nullptr) cout<<"无"<<"\t"<<"Person"<<endl; 
	else Time->putDLTime();
}
