#include "CShip.h"

CShip::CShip(string shid,string brand,string color,string vin):CVehicle(shid,brand,color,vin) {
	cout<<this<<": "<<"ship begin!"<<endl;
}

CShip::CShip(CPerson& owner,string shid,string brand,string color,string vin):CVehicle(owner,shid,brand,color,vin) {
	cout<<this<<": "<<"ship begin!"<<endl;
}

CShip::CShip(CPerson& owner,CPerson& driver,string shid,string brand,string color,string vin):CVehicle(owner,driver,shid,brand,color,vin) {
	cout<<this<<": "<<"ship begin!"<<endl;
}

CShip::~CShip() {
	cout<<this<<": "<<"ship end!"<<endl;
}

void CShip::putAll() const {
//	cout<<"This is a ship!"<<endl;
	CVehicle::putVehicle();
	cout<<"Ship"<<endl;
}
