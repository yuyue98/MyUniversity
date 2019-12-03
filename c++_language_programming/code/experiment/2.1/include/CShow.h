#ifndef CSHOW_H
#define CSHOW_H

#include <iostream>
#include <string>

#include "CCarManager.h"

using namespace std; 

class CShow
{
	private:
		string choose;
		CCarManager Manager; 
		void addCar();
		void addOwner(CCar& car);
		void SearchCarWithNo();
		void SearchCarWithOwner();
	public:
		CShow();
		~CShow();
		void Menu();
	protected:
};

#endif
