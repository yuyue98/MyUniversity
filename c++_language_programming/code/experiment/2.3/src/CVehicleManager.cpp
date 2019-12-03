#include "CVehicleManager.h"

CVehicleManager::CVehicleManager():VehicleNum(0) {
	cout<<this<<": "<<"vehiclemanager begin!"<<endl;
}

CVehicleManager::CVehicleManager(vector<CVehicle*> vehiclelist,int vehiclenum):VehicleList(vehiclelist),VehicleNum(vehiclenum<=0?vehiclelist.size():vehiclenum) {
	cout<<this<<": "<<"vehiclemanager begin!"<<endl;
}

CVehicleManager::~CVehicleManager() {
	cout<<this<<": "<<"vehiclemanager end!"<<endl;
	for (int i=0;i<VehicleNum;i++) {
		delete VehicleList[i];
	}
}

bool CVehicleManager::addVehicle(CVehicle& newvehicle) {
	VehicleList.push_back(&newvehicle);
	VehicleNum++;
	return true;
}

CVehicle* CVehicleManager::SearchVehicleWithNo(string vid) const {
	for (int i=0;i<VehicleNum;i++) {
		if (VehicleList[i]->getVID()==vid) return VehicleList[i];
		if (i==VehicleNum-1) {
			cout<<"The "<<vid<<" vehicle is inexistence!"<<endl;
			return nullptr;
		}
	}
	return nullptr;
}

bool CVehicleManager::SearchVehicleWithOwner(vector<CVehicle*>& vehiclelist,string option,int flag) const {
	for (int i=0;i<VehicleNum;i++) {
		if (!VehicleList[i]->getOwner()) continue;
		if (flag==0) {
			if (VehicleList[i]->getOwner()->getID()==option) vehiclelist.push_back(VehicleList[i]);
		} else if (flag==1) {
			if (VehicleList[i]->getOwner()->getName()==option) vehiclelist.push_back(VehicleList[i]);
		}
	}
	if (vehiclelist.size()==0) return false;
	else return true;
}

void CVehicleManager::reportVehicleCount() {
	if (VehicleList.size()!=VehicleNum) VehicleNum=VehicleList.size();
	cout<<"VehicleNum: "<<VehicleNum<<endl;
}

void CVehicleManager::putVehicleList() const {
	cout<<"This vehiclelist's information is as follows: "<<endl;
	cout<<"Size: "<<VehicleNum<<endl;
	cout<<"No\tVID\tBrand\tColor\tVIN\tOName\tDName\tText"<<endl;
	for (int i=0;i<VehicleNum;i++) {
		cout<<i<<"\t";
		VehicleList[i]->putAll();
	}
}
