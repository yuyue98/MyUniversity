#include "CStudent.h"

CStudent::CStudent(){
}

CStudent::CStudent(string sid,string name,int age){
	this->m_age = age;
	this->m_name = name;
	this->stuID = sid; 
}


void CStudent::setStuID(string sid){
	this->stuID = sid;
}

void CStudent::setName(string name){
	this->m_name = name;
}

void CStudent::setAge(int age){
	this->m_age = age;
}

string CStudent::getStuID(){
	return this->stuID;
}

string CStudent::getName(){
	return this->m_name; 
}

int CStudent::getAge(){
	return this->m_age;
}
