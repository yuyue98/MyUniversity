#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class student
{
	public:
		student(string name);
		void putname();
	protected:
		string name; 
};

#endif
