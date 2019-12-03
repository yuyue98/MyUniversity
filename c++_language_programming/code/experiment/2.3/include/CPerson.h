#ifndef CPERSON_H
#define CPERSON_H

#include <iostream>
#include <string>

using namespace std;

class CPerson {
	private:
		string ID;      // 身份证号码 
		string Name;    // 姓名 
		int Age;        // 年龄 
		string Gender;  // 性别 
	public:
		CPerson(string id="未知",string name="未知",int age=-1,string gender="未知");
		virtual ~CPerson();
		inline bool setID(string id="") { if (id=="") return false; else { ID=id;return true; } };
		inline bool setName(string name="") { if (name=="") return false; else { Name=name;return true; } };
		inline bool setAge(int age=-1) { if (age>=0) { Age=age;return true; } else { return false; } };
		inline bool setGender(string gender="") { if (gender=="") return false; else{ Gender=gender;return true; } };
		inline string getID() const { return ID; };
		inline string getName() const { return Name; };
		inline int getAge() const { return Age; };
		inline string getGender() const { return Gender; };
		void putPerson() const;
		virtual void putAll() const;
	protected:
};

#endif
