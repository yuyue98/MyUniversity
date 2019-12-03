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
	cout<<"This vehicle's information is as follows: "<<endl;
	cout<<"VID: "<<VID<<endl;
	cout<<"Brand: "<<Brand<<endl;
	cout<<"Color: "<<Color<<endl;
	cout<<"VIN: "<<VIN<<endl;
}

void CVehicle::putOwner() const {
	cout<<"[Owner]: ";
	if (Owner==nullptr)
		cout<<"无";
	else
		Owner->putAll();
	cout<<endl;
}

void CVehicle::putDriver() const {
	cout<<"[Driver]: ";
	if (Driver==nullptr)
		cout<<"无";
	else
		Driver->putAll();
	cout<<endl;
	
}

void CVehicle::putAll() const {
	putVehicle();
	putOwner();
	putDriver();
}
