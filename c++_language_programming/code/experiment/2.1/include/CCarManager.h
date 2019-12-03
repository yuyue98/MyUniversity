#ifndef CCARMANAGER_H
#define CCARMANAGER_H

#include <iostream>
#include <string>
#include <vector>

#include <CCar.h>

using namespace std;

class CCarManager
{
	private:
		int CarNum; 
		vector<CCar*> CarList;
	public:
		CCarManager();
		CCarManager(vector<CCar*> carlist,int carnum=0);
		~CCarManager();
		inline int getCarNum() const { return CarNum; };
		bool addCar(CCar& newcar);
		CCar* SearchCarWithNo(string cid) const;
		bool SearchCarWithOwner(vector<CCar*>& carlist,string option,int flag=1) const;
		void reportCarCount();
		void putCarList() const;
	protected:
};

#endif
