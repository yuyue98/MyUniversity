#ifndef CVEHICLEMANAGER_H
#define CVEHICLEMANAGER_H

#include <vector>

#include "CVehicle.h"
#include "CCar.h"
#include "CBus.h"
#include "CShip.h"

using namespace std;

class CVehicleManager {
	private:
		int VehicleNum;
		vector<CVehicle*> VehicleList;
	public:
		CVehicleManager();
		CVehicleManager(vector<CVehicle*> vehiclelist,int vehiclenum=0);
		~CVehicleManager();
		inline int getVehicleNum() const { return VehicleNum; };
		bool addVehicle(CVehicle& newvehicle);
		CVehicle* SearchVehicleWithNo(string vid) const;
		bool SearchVehicleWithOwner(vector<CVehicle*>& vehiclelist,string option,int flag=1) const;
		void reportVehicleCount();
		void putVehicleList() const;
	protected:
};

#endif
