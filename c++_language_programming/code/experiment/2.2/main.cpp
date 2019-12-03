#include <iostream>
#include <string>

//#include "CPerson.h"
//#include "CCar.h"
//#include "CCarManager.h" 
#include "CShow.h"
#include "CDriver.h"
#include "CVehicle.h"
#include "CBus.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	CShow s;
//	DivLicTime b;
//	CDriver a(b);
//	a.setTime(1222,3,4);
//	a.putDriver();
//	CBus c;
//	((CVehicle)c).putAll();
	s.Menu();
//	/* Test class CPerson */
//	CPerson a("123");
//	a.setAge(12);
//	a.setGender("男");
//	a.setName("Herry");
//	DivLicTime* t=a.getTime();
//	if (t==nullptr) {
//		t = new DivLicTime(1000,2,3);
//	}
//	a.setTime(1999,3,4);
//	a.putPerson();
//	CPerson aa("122");
//	aa.setAge(15);
//	aa.setGender("女");
//	aa.setName("LiLy");
//	aa.setTime(2000,2,5);
//	aa.putPerson();
//	/* Test class CCar */
//	CCar b("222");
//	b.setBrand("GOOD");
//	b.setColor("RED");
//	b.setVIN("333");
//	b.setOwner(a);
//	b.putCar();
//	a.setAge(34);
//	a.putPerson();
//	b.putCar();
//	CPerson* c = b.getOwner();
//	c->putPerson();
//	c->setAge(234);
//	c->putPerson();
//	a.putPerson();
//	CCar bb("444");
//	bb.setBrand("BAD");
//	bb.setColor("GREEN");
//	bb.setVIN("666");
//	bb.setOwner(aa);
//	CCar bbb("666");
//	bbb.setBrand("BAD1");
//	bbb.setColor("BLACK");
//	bbb.setVIN("888");
//	bbb.setOwner(aa);
//	/* Test class CCarManager */
//	CCarManager m;
//	m.addCar(b);
//	m.addCar(bb);
//	m.addCar(bbb);
//	m.putCarList();
//	CCar* pb = m.SearchCarWithNo("2223");
//	if (pb!=nullptr) pb->putCar(); 
//	vector<CCar*> casrlit;
//	if (m.SearchCarWithOwner(carlist,"777",0)) {
//		for (int i=0;i<carlist.size();i++) {
//			cout<<"No."<<i<<endl;
//			carlist[i]->putCar();
//		}	
//	}
//	m.reportCarCount();
	return 0;
}
