#ifndef CSHOW_H
#define CSHOW_H

#include <typeinfo>

#include "CPersonManager.h"
#include "CVehicleManager.h"

using namespace std; 

class CShow {
	private:
		string choose;
		CVehicleManager Manager; 
		CPersonManager PManager; 
		void addVehicle();
		void addOwner(CVehicle& vehicle);
		void addDriver(CVehicle& vehicle);
		void SearchVehicleWithNo();
		void SearchVehicleWithOwner();
		void ReportCount(); 
	public:
		CShow();
		~CShow();
		void Menu();
		void trim(string &s);
	protected:
};

#endif
