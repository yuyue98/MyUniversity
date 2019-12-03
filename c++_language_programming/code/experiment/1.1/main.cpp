#include <iostream>
#include "CStudent.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void getAge(CStudent stua,CStudent stub);

int main(int argc, char** argv) {
	cout<<"helloworld"<<endl;
	CStudent stu1 = CStudent("2016326603039","郭大大",21);
	CStudent stu2 = CStudent();
	stu2.setStuID("2016326603046");
	stu2.setName("余泓锷");
	stu2.setAge(22);
	getAge(stu1,stu2);
	system("pause");
	return 0;
}

void getAge(CStudent stua,CStudent stub){
	CStudent stu = stua.getAge()>stub.getAge()?stua:stub;
	cout<<"The name of an older student is "<<stu.getName()<<endl;
	cout<<"His sid is "<<stu.getStuID()<<endl;
}
