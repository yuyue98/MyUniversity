#ifndef DIVLICTIME_H_
#define DIVLICTIME_H_

#include <iostream>
#include <string>

using namespace std;

class DivLicTime{
	private:
		int Year;
		int Month;
		int Day;
		static int pyear_month_day[];
		static int ryear_month_day[];
	public:
		DivLicTime(int year=0,int month=0,int day=0);
		~DivLicTime();
		bool setDLTime(int year=0,int month=0,int day=0);
		void putDLTime() const;
	protected:
		
}; 

#endif
