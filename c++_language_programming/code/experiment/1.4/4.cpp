#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

class Employee {
	private:
		int number, age;
		char name[20];
		double sal;
	public:
		Employee() {}
		Employee(int num, char* Name, int Age, double Salary) {
			number = num;
			strcpy(name,Name);
			age = Age;
			sal = Salary;
		}
		void display() {
			cout<<number<<"\t"<<name<<"\t"<<age<<"\t"<<sal<<endl;
		}
		
};

int main() {
	ofstream out("employee.dat",ios::out|ios::binary);
	Employee e1(1,(char*)"张三",23,2320);
	Employee e2(2,(char*)"李四",32,3210);
	Employee e3(3,(char*)"王五",34,2220);
	Employee e4(4,(char*)"对六",27,1220);
	out.write((char*)&e1,sizeof(e1));
	out.write((char*)&e2,sizeof(e2));
	out.write((char*)&e3,sizeof(e3));
	out.write((char*)&e4,sizeof(e4));
	Employee e5(3,(char*)"王五",40,2220);
	out.seekp(2*sizeof(e1));
	out.write((char*)&e5,sizeof(e5));
	out.close();
	ifstream in("employee.dat",ios::in|ios::binary);
	Employee s1;
	cout<<"\n--------从文件中读出第三个人的数据--------"<<endl<<endl;
	in.seekg(2*sizeof(s1),ios::beg);
	in.read((char*)&s1,sizeof(s1));
	s1.display();
	cout<<"\n----------从文件中读出全部的数据----------"<<endl<<endl;
	in.seekg(0,ios::beg);
	in.read((char*)&s1,sizeof(s1));
	while (!in.eof()) {
		s1.display();
		in.read((char*)&s1,sizeof(s1));
	}
	in.close();
	return 0;
}
