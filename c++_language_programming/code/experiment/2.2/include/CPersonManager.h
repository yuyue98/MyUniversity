#ifndef CPERSONMANAGER_H
#define CPERSONMANAGER_H

#include <vector>

#include "CPerson.h" 
#include "CDriver.h"

class CPersonManager {
	private:
		int PersonNum;
		vector<CPerson*> PersonList;
	public:
		CPersonManager();
		CPersonManager(vector<CPerson*> personlist,int personnum=0);
		~CPersonManager();
		inline int getPersonNum() const { return PersonNum; };
		bool addPerson(CPerson& newperson);
		CPerson* SearchPersonWithNo(string id) const;
		bool SearchPersonWithName(vector<CPerson*>& personlist,string option,int flag=1) const;
		void reportPersonCount();
		void putPersonList() const;
	protected:
};

#endif
