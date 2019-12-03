#include "CCarManager.h"

CCarManager::CCarManager():CarNum(0) {
	cout<<this<<": "<<"carmanager begin!"<<endl;
}

CCarManager::CCarManager(vector<CCar*> carlist,int carnum):CarList(carlist),CarNum(carnum<=0?carlist.size():carnum) {
	cout<<this<<": "<<"carmanager begin!"<<endl;
}

CCarManager::~CCarManager() {
	cout<<this<<": "<<"carmanager end!"<<endl;
}

bool CCarManager::addCar(CCar& newcar) {
	CarList.push_back(&newcar);
	CarNum++;
	return true;
}

CCar* CCarManager::SearchCarWithNo(string cid) const {
//	cout<<"The "<<cid<<" car it is: "<<endl;
	for (int i=0;i<CarNum;i++) {
		if (CarList[i]->getCID()==cid) return CarList[i];
		if (i==CarNum-1) {
			cout<<"The "<<cid<<" car is inexistence!"<<endl;
			return NULL;
		}
	}
	return NULL;
}

bool CCarManager::SearchCarWithOwner(vector<CCar*>& carlist,string option,int flag) const {
	for (int i=0;i<CarNum;i++) {
		if (!CarList[i]->getOwner()) continue;
		if (flag==0) {
			if (CarList[i]->getOwner()->getID()==option) carlist.push_back(CarList[i]);
		} else if (flag==1) {
			if (CarList[i]->getOwner()->getName()==option) carlist.push_back(CarList[i]);
		}
	}
	if (carlist.size()==0) return false;//cout<<"The "<<option<<" owner not have car!"<<endl;
	else return true; //cout<<"The "<<option<<" owner's car it is: "<<endl;
}

void CCarManager::reportCarCount() {
	if (CarList.size()!=CarNum) CarNum=CarList.size();
	cout<<"CarNum: "<<CarNum<<endl;
}

void CCarManager::putCarList() const {
	cout<<"This carlist's information is as follows: "<<endl;
	cout<<"Size: "<<CarNum<<endl;
	for (int i=0;i<CarNum;i++) {
		cout<<"No."<<i<<endl;
		CarList[i]->putAll();
	}
}
