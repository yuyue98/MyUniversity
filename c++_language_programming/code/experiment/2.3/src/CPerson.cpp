#include "CPerson.h"

CPerson::CPerson(string id,string name,int age,string gender):ID(id),Name(name),Age(age),Gender(gender) {
	cout<<this<<": "<<"persion begin!"<<endl;
}

CPerson::~CPerson() {
	cout<<this<<": "<<"persion end!"<<endl;
}

void CPerson::putPerson() const {
	cout<<ID<<"\t"<<Name<<"\t";
	if (Age!=-1)
		cout<<Age<<"\t";
	else
		cout<<"未知"<<"\t"; 
	cout<<Gender<<"\t";
} 

void CPerson::putAll() const {
//	cout<<"This person's information is as follows: "<<endl;
	putPerson(); 
	cout<<"无"<<"\t"<<"Person"<<endl;
}
