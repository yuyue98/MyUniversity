#ifndef CPERSON_H
#define CPERSON_H

#include <iostream>
#include <string>

#include "DivLicTime.h"

using namespace std;

class CPerson {
	private:
		DivLicTime* Time;
		string ID;
		string Name;
		int Age;
		string Gender;
	public:
		CPerson(string id="未知",string name="未知",int age=-1,string gender="未知");
		CPerson(DivLicTime& time,string id="未知",string name="未知",int age=-1,string gender="未知");
		~CPerson();
		inline bool setName(string name="") { if (name=="") return false; else { Name=name;return true; } };
		inline bool setAge(int age=-1) { if (age>=0) { Age=age;return true; } else { return false; } };
		inline bool setGender(string gender="") { if (gender=="") return false; else{ Gender=gender;return true; } };
		bool setTime(DivLicTime& time);
		bool setTime(int year=0,int month=0,int day=0);
		inline string getID() const { return ID; };
		inline string getName() const { return Name; };
		inline int getAge() const { return Age; };
		inline string getGender() const { return Gender; };
		inline DivLicTime* getTime() const { return Time; };
		void putPerson() const;
	protected:
};

#endif
