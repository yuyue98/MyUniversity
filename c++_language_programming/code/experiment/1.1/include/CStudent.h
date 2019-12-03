#ifndef CSTUDENT_H
#define CSTUDENT_H

#include <string>

using namespace std;

class CStudent{
	string stuID;
	string m_name;
	int m_age;
	public:
		CStudent(); 
		CStudent(string sid,string name,int age);
		void setStuID(string sid);
		void setName(string name);
		void setAge(int age);
		string getStuID();
		string getName();
		int getAge();
	protected:
};

#endif
