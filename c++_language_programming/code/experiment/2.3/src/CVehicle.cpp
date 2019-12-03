#include "CVehicle.h"

int CVehicle::VehicleNum = 0;

CVehicle::CVehicle(string vid,string brand,string color,string vin):Owner(nullptr),Driver(nullptr),VID(vid),Brand(brand),Color(color),VIN(vin) {
	cout<<this<<": "<<"vehicle begin!"<<endl;
	VehicleNum++;
}

CVehicle::CVehicle(CPerson& owner,string vid,string brand,string color,string vin):Owner(&owner),Driver(nullptr),VID(vid),Brand(brand),Color(color),VIN(vin) {
	cout<<this<<": "<<"vehicle begin!"<<endl;
	VehicleNum++;
}

CVehicle::CVehicle(CPerson& owner,CPerson& driver,string vid,string brand,string color,string vin):Owner(&owner),Driver(&driver),VID(vid),Brand(brand),Color(color),VIN(vin) {
	cout<<this<<": "<<"vehicle begin!"<<endl;
	VehicleNum++;
}

CVehicle::~CVehicle() {
	cout<<this<<": "<<"vehicle end!"<<endl;
	VehicleNum--;
}

void CVehicle::putVehicle() const {
	cout<<VID<<"\t"<<Brand<<"\t"<<Color<<"\t"<<VIN<<"\t";
	putOwner();
	putDriver();
}

void CVehicle::putOwner() const {
	if (Owner==nullptr)
		cout<<"无";
	else
		cout<<Owner->getName();
	cout<<"\t";
}

void CVehicle::putDriver() const {
	if (Driver==nullptr)
		cout<<"无";
	else
		cout<<Driver->getName();
	cout<<"\t";
	
}

void CVehicle::putAll() const {
	putVehicle();
	cout<<"Vehicle"<<endl;
}
