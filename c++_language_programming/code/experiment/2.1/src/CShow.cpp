#include "CShow.h"

CShow::CShow() {
}

CShow::~CShow() {
}

void CShow::Menu() {
	while (true) {
		cout<<"++++++++++++++++++简易车辆管理系统++++++++++++++++++"<<endl;
		cout<<"                    1、车辆添加"<<endl;
		cout<<"                 2、显示所有车辆信息"<<endl; 
		cout<<"                3、根据车牌号查询车辆"<<endl;
		cout<<"                4、根据所有人查询车辆"<<endl;
		cout<<"                 5、统计当前车辆数目"<<endl;
		cout<<"                       6、退出"<<endl;
		cout<<"请输入选项前的标号："; 
		cin>>choose;
		switch(choose[0]) {
			case '1':system("cls");addCar();break;
			case '2':system("cls");Manager.putCarList();break;
			case '3':system("cls");SearchCarWithNo();break;
			case '4':system("cls");SearchCarWithOwner();break;
			case '5':system("cls");Manager.reportCarCount();break;
			case '6':system("cls");return;
			default:system("cls");cin.clear();cout<<"输入有误请重新输入！"<<endl;break;
		}
			
	}
}

void CShow::addCar() {
	string cid;
	string brand;
	string color;
	string vin;
	CCar* pc;
	cout<<"请输入车牌号：";
	cin>>cid;
	pc = Manager.SearchCarWithNo(cid);
	if (pc!=NULL) {
		CPerson* pp;
		cout<<"车牌为"<<cid<<"的车辆已经存在！"<<endl; 
		pc->putCar();
		pp = pc->getOwner();
		if (pp!=NULL) {
			pc->putOwner();
			return;
		}
		addOwner(*pc);
		return;
	}
	cout<<"请输入车辆品牌：";
	cin>>brand;
	cout<<"请输入车辆颜色：";
	cin>>color;
	cout<<"请输入车架号：";
	cin>>vin;
	pc = new CCar(cid,brand,color,vin);
	addOwner(*pc);
	Manager.addCar(*pc);
}

void CShow::addOwner(CCar& car) {
	string flag;
	cout<<"是否输入该车的所有人信息？(y/n)";
	cin>>flag;
	if (flag[0]=='y' || flag[0]=='Y') {
		string id;
		string name;
		string gender;
		int age;
		int year,month,day; 
		vector<CCar*> carlist;
		cout<<"请输入所有人ID：";
		cin>>id;
		if (Manager.SearchCarWithOwner(carlist,id,0)) {
			cout<<"123"<<endl;
			car.setOwner(*(carlist[0]->getOwner()));
			return;	
		}
		cout<<"请输入所有人姓名：";
		cin>>name;
		cout<<"请输入所有人性别：";
		cin>>gender;
		cout<<"请输入所有人年龄：";
		cin>>age;
		cin.clear(); 
		cout<<"请依次输入所有人获得驾照时间的年月日(以空格分隔)：";
		cin>>year>>month>>day;
		cin.clear();
		CPerson* pp;
		pp = new CPerson(id,name,age,gender);
		pp->setTime(year,month,day);
		car.setOwner(*pp);
	}
}


void CShow::SearchCarWithNo() {
	string cid;
	cout<<"请输入要查询的车辆车牌号：";
	cin>>cid;
	CCar* pb = Manager.SearchCarWithNo(cid);
	if (pb!=NULL) pb->putCar();
}
void CShow::SearchCarWithOwner() {
	string id;
	string name;
	string flag;
	cout<<"请选择查询方式(0 按ID查询，1 按Name查询)：";
	cin>>flag;
	vector<CCar*> carlist;
	if (flag[0]=='0') {
		cout<<"请输入所有人ID：";
		cin>>id;
		if (Manager.SearchCarWithOwner(carlist,id,0)) {
			for (int i=0;i<carlist.size();i++) {
				cout<<"No."<<i<<endl;
				carlist[i]->putCar();
			}	
		}
	} else if (flag[0]=='1') {
		cout<<"请输入所有人Name：";
		cin>>name;
		if (Manager.SearchCarWithOwner(carlist,name)) {
			for (int i=0;i<carlist.size();i++) {
				cout<<"No."<<i<<endl;
				carlist[i]->putCar();
			}	
		}
	}
}
