#include "CPerson.h"

CPerson::CPerson(string id,string name,int age,string gender):ID(id),Name(name),Age(age),Gender(gender) {
	cout<<this<<": "<<"persion begin!"<<endl;
}

CPerson::~CPerson() {
	cout<<this<<": "<<"persion end!"<<endl;
}

void CPerson::putAll() const {
	cout<<"This person's information is as follows: "<<endl;
	cout<<"ID: "<<ID<<endl;
	cout<<"Name: "<<Name<<endl;
	cout<<"Age: ";
	if (Age!=-1)
		cout<<Age<<endl;
	else
		cout<<"未知"<<endl; 
	cout<<"Gender: "<<Gender<<endl;
}
