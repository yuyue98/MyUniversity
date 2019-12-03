#ifndef CCAR_H
#define CCAR_H

#include "CVehicle.h"

class CCar : public CVehicle {
	public:
		CCar(string cid="未知",string brand="未知",string color="未知",string vin="未知");
		CCar(CPerson& owner,string cid="未知",string brand="未知",string color="未知",string vin="未知");
		CCar(CPerson& owner,CPerson& driver,string cid="未知",string brand="未知",string color="未知",string vin="未知");
		~CCar();
		virtual void putAll() const;
	protected:
};

#endif
