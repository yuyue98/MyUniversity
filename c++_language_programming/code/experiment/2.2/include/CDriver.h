#ifndef CDRIVER_H
#define CDRIVER_H

#include "CPerson.h"
#include "DivLicTime.h"

class CDriver : public CPerson {
	private:
		DivLicTime* Time;  // 取得驾照时间 
	public:
		CDriver(string id="未知",string name="未知",int age=-1,string gender="未知");
		CDriver(DivLicTime& time,string id="未知",string name="未知",int age=-1,string gender="未知");
		~CDriver();
		inline bool setTime(DivLicTime& time){ if (Time==nullptr) Time = new DivLicTime(); *Time = time; return true; };
		inline bool setTime(int year=0,int month=0,int day=0){ DivLicTime* time=new DivLicTime(year,month,day); bool flag = setTime(*time); delete time; return flag; };
		inline DivLicTime* getTime() const { return Time; };
		virtual void putAll() const;
	protected:
};

#endif
