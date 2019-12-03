#include "DivLicTime.h" 

int DivLicTime::ryear_month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int DivLicTime::pyear_month_day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

DivLicTime::DivLicTime(int year,int month,int day):Year(year),Month(month),Day(day) {
	cout<<this<<": "<<"time begin!"<<endl;
	if (Year<0) Year=0;
	if (Year==0 || Month<0 || Month>12) Month=0;
	if (Month==0 || Year%400==0 || (Year%4==0 && Year%100!=0)) {
		if (Day<0 || Day>DivLicTime::ryear_month_day[Month-1]) Day=0;
	} else {
		if (Day<0 || Day>DivLicTime::pyear_month_day[Month-1]) Day=0;
	}
}

DivLicTime::DivLicTime(DivLicTime& other) {
	cout<<this<<": "<<"time copy begin!"<<endl;
	Year = other.Year;
	Month = other.Month;
	Day = other.Day;
}

DivLicTime::~DivLicTime() {
	cout<<this<<": "<<"time end!"<<endl;
}

DivLicTime& DivLicTime::operator=(DivLicTime& other) {
	cout<<this<<": "<<"time = heavy load begin!"<<endl;
	if (this==&other) return *this;
	Year = other.Year;
	Month = other.Month;
	Day = other.Day;
	return *this;
}

bool DivLicTime::setDLTime(int year,int month,int day) {
	if (year<0) return false;
	if (year==0 || month<0 || month>12) return false;
	if (month==0 || year%400==0 || (year%4==0 && year%100!=0)) {
		if (day<0 || day>DivLicTime::ryear_month_day[month-1]) return false;
	} else {
		if (day<0 || day>DivLicTime::pyear_month_day[month-1]) return false;
	}
	Year = year;
	Month = month;
	Day = day;
	return true;
}

void DivLicTime::putDLTime() const{
	if (Year!=0) cout<<Year;
	else cout<<"未知";
	if (Month!=0) cout<<"-"<<Month;
	if (Day!=0) cout<<"-"<<Day;
	cout<<"\t"<<"Driver"<<endl;
}

