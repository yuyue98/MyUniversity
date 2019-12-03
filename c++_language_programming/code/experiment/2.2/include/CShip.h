#ifndef CSHIP_H
#define CSHIP_H

#include "CVehicle.h"

class CShip : public CVehicle {
	public:
		CShip(string shid="未知",string brand="未知",string color="未知",string vin="未知");
		CShip(CPerson& owner,string shid="未知",string brand="未知",string color="未知",string vin="未知");
		CShip(CPerson& owner,CPerson& driver,string shid="未知",string brand="未知",string color="未知",string vin="未知");
		~CShip();
		virtual void putAll() const;
	protected:
};

#endif
