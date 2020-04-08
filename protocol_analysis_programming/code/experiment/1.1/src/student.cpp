#include "student.h"

student::student(string name){
	this->name = name;
}

void student::putname(){
	cout<<"The student's name is "<<this->name<<endl;
}
