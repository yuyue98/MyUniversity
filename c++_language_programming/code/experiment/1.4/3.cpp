#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

class Person {
	private:
		char name[20];
		char id[18];
		int age;
		char addr[20];
	public:
		Person() {}
		Person(char* n,char* PerId, int Age, char* Address) {
			strcpy(name,n);
			strcpy(id,PerId);
			strcpy(addr,Address);
			age = Age;
		}
		void display() {
			cout<<name<<"\t"<<id<<"\t"<<age<<"\t"<<addr<<endl;
		}
};

int main() {
	vector<Person> p;
	vector<Person>::iterator pos;
	char ch;
	ofstream out("person.dat",ios::out|ios::app|ios::binary);
	char Name[20], ID[18], Addr[20];
	int Age;
	cout<<"--------输入个人档案--------"<<endl<<endl;
	do {
		cout<<"姓名：    "; cin>>Name;
		cout<<"身份证号："; cin>>ID;
		cout<<"年龄：    "; cin>>Age;
		cout<<"地址：    "; cin>>Addr;
		Person s1(Name,ID,Age,Addr);
		out.write((char*)&s1,sizeof(s1));
		cout<<"Enter another Person(y/n)?";
		cin>>ch;
	} while(ch=='y'||ch=='Y');
	out.close();
	ifstream in("person.dat",ios::in|ios::binary);
	Person s1;
	in.read((char*)&s1,sizeof(s1));
	while (!in.eof()) {
		p.push_back(s1);
		in.read((char*)&s1,sizeof(s1));
	}
	cout<<"\n--------从文件中读出的数据--------"<<endl<<endl;
	pos = p.begin();
	for (pos=p.begin();pos!=p.end();pos++) {
		(*pos).display();
	}
	in.close();
	return 0;
}
