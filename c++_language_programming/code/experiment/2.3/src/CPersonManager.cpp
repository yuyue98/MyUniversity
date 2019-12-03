#include "CPersonManager.h"

CPersonManager::CPersonManager():PersonNum(0) {
	cout<<this<<": "<<"personmanager begin!"<<endl;
}

CPersonManager::CPersonManager(vector<CPerson*> personlist,int personnum):PersonList(personlist),PersonNum(personnum<=0?personlist.size():personnum) {
	cout<<this<<": "<<"personmanager begin!"<<endl;
}

CPersonManager::~CPersonManager() {
	cout<<this<<": "<<"personmanager end!"<<endl;
	for (int i=0;i<PersonNum;i++) {
		delete PersonList[i];
	}
}

bool CPersonManager::addPerson(CPerson& newperson) {
	PersonList.push_back(&newperson);
	PersonNum++;
	return true;
}

CPerson* CPersonManager::SearchPersonWithNo(string id) const {
	for (int i=0;i<PersonNum;i++) {
		if (PersonList[i]->getID()==id) return PersonList[i];
		if (i==PersonNum-1) {
			cout<<"The "<<id<<" person is inexistence!"<<endl;
			return nullptr;
		}
	}
	return nullptr;
}

bool CPersonManager::SearchPersonWithName(vector<CPerson*>& personlist,string option,int flag) const {
	for (int i=0;i<PersonNum;i++) {
		if (PersonList[i]->getName()==option) personlist.push_back(PersonList[i]);
	}
	if (personlist.size()==0) return false;
	else return true;
}

void CPersonManager::reportPersonCount() {
	if (PersonList.size()!=PersonNum) PersonNum=PersonList.size();
	cout<<"PersonNum: "<<PersonNum<<endl;
}

void CPersonManager::putPersonList() const {
	cout<<"This personlist's information is as follows: "<<endl;
	cout<<"Size: "<<PersonNum<<endl;
	cout<<"No\tID\tName\tAge\tGender\tDLTime\tText"<<endl;
	for (int i=0;i<PersonNum;i++) {
		cout<<i<<"\t";
		PersonList[i]->putAll();
	}
}
