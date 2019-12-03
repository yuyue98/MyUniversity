#ifndef CBUS_H
#define CBUS_H

#include "CVehicle.h"

class CBus : public CVehicle {
	public:
		CBus(string bid="未知",string brand="未知",string color="未知",string vin="未知");
		CBus(CPerson& owner,string bid="未知",string brand="未知",string color="未知",string vin="未知");
		CBus(CPerson& owner,CPerson& driver,string bid="未知",string brand="未知",string color="未知",string vin="未知");
		~CBus();
		virtual void putAll() const;
	protected:
};

#endif
