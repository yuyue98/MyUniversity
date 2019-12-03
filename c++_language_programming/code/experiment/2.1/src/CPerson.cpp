#include "CPerson.h"

CPerson::CPerson(string id,string name,int age,string gender):Time(NULL),ID(id),Name(name),Age(age),Gender(gender) {
	cout<<this<<": "<<"persion begin!"<<endl;
}

CPerson::CPerson(DivLicTime& time,string id,string name,int age,string gender):Time(&time),ID(id),Name(name),Age(age),Gender(gender) {
	cout<<this<<": "<<"persion begin!"<<endl;
}

CPerson::~CPerson() {
	cout<<this<<": "<<"persion end!"<<endl;
}

bool CPerson::setTime(DivLicTime& time) {
	if (Time==NULL)
		Time = new DivLicTime();
	*Time = time;
	return true; 
}
bool CPerson::setTime(int year,int month,int day) { 
	DivLicTime* time=new DivLicTime(year,month,day); 
	bool flag = setTime(*time);
	delete time; 
	return flag; 
};
		

void CPerson::putPerson() const {
	cout<<"This person's information is as follows: "<<endl;
	cout<<"ID: "<<ID<<endl;
	cout<<"Name: "<<Name<<endl;
	cout<<"Age: ";
	if (Age!=-1)
		cout<<Age<<endl;
	else
		cout<<"未知"<<endl; 
	cout<<"Gender: "<<Gender<<endl;
	if (Time==NULL) cout<<"Time: "<<"未知"<<endl; 
	else Time->putDLTime();
}
