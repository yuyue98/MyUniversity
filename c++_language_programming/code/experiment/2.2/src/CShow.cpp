#include "CShow.h"

CShow::CShow() {
}

CShow::~CShow() {
}

void CShow::Menu() {
	while (true) {
		cout<<"++++++++++++++++++简易交通工具管理系统++++++++++++++++++"<<endl;
		cout<<"                   1、交通工具添加"<<endl;
		cout<<"               2、显示所有交通工具信息"<<endl; 
		cout<<"              3、根据车牌号查询交通工具"<<endl;
		cout<<"              4、根据所有人查询交通工具"<<endl;
		cout<<"                       5、统计"<<endl;
		cout<<"                       6、退出"<<endl;
		cout<<"请输入选项前的标号："; 
		cin>>choose;
		trim(choose);
		switch(choose[0]) {
			case '1':system("cls");addVehicle();break;
			case '2':system("cls");Manager.putVehicleList();break;
			case '3':system("cls");SearchVehicleWithNo();break;
			case '4':system("cls");SearchVehicleWithOwner();break;
			case '5':system("cls");ReportCount();break;
			case '6':system("cls");return;
			default:system("cls");cin.clear();cout<<"输入有误请重新输入！"<<endl;break;
		}
			
	}
}

void CShow::trim(string &s) {
	if (!s.empty()) {
		s.erase(0,s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	} 
}

void CShow::addVehicle() {
	string vid;
	string brand;
	string color;
	string vin;
	string flag;
	CVehicle* pv;
	
	cout<<"请输入车牌号：";
	cin>>vid;
	pv = Manager.SearchVehicleWithNo(vid);
	if (pv!=nullptr) {
		CPerson* po;
		CPerson* pd;
		cout<<"车牌为"<<vid<<"的交通工具已经存在！"<<endl; 
		pv->putVehicle();
		po = pv->getOwner();
		pd = pv->getDriver();
		if (po!=nullptr) {
			pv->putOwner();
			if (pd!=nullptr) {
				pv->putDriver();
				return;
			}
			addDriver(*pv);
			return;
		}
		addOwner(*pv);
		addDriver(*pv);
		return;
	}
	cout<<"请输入车辆品牌：";
	cin>>brand;
	cout<<"请输入车辆颜色：";
	cin>>color;
	cout<<"请输入车架号：";
	cin>>vin;
	
	cout<<"请输入交通工具类型(0 其他，1 汽车，2 公交车，3 船)：";
	while (true) {
		cin>>flag;
		trim(flag);
		if (flag[0]=='0') {
			pv = new CVehicle(vid,brand,color,vin);
			break;
		} else if (flag[0]=='1') {
			pv = new CCar(vid,brand,color,vin);
			break;
		} else if (flag[0]=='2') {
			pv = new CBus(vid,brand,color,vin);
			break;
		} else if (flag[0]=='3') {
			pv = new CShip(vid,brand,color,vin);
			break;
		} else {
			cout<<"输入有误请重新输入: ";
		}	
	}
	addOwner(*pv);
	addDriver(*pv);
	pv->putAll();
	Manager.addVehicle(*pv);
}

void CShow::addOwner(CVehicle& vehicle) {
	string id;
	string name;
	string gender;
	int age;
	int year,month,day; 
	string flag,flag1;
	cout<<"是否输入该车的所有人信息？(y/n)";
	while (true) {
		cin>>flag;
		trim(flag);
		if (flag[0]=='y' || flag[0]=='Y') {
			CPerson* po;
			cout<<"请输入所有人ID：";
			cin>>id;
			po = PManager.SearchPersonWithNo(id);
			if (po!=nullptr) {
				vehicle.setOwner(*po);
				return;	
			}
			cout<<"请输入所有人姓名：";
			cin>>name;
			cout<<"请输入所有人性别：";
			cin>>gender;
			cout<<"请输入所有人年龄：";
			cin>>age;
			cin.clear(); 
			
			cout<<"该所有人是否有驾照？(y/n)";
			while (true) {
				cin>>flag1;
				trim(flag1);
				if (flag1[0]=='y' || flag1[0]=='Y') {
					CDriver* pod = new CDriver(id,name,age,gender);
					cout<<"请依次输入所有人获得驾照时间的年月日(以空格分隔)：";
					cin>>year>>month>>day;
					cin.clear();
					pod->setTime(year,month,day);
					po = pod;
					break;
				} else if (flag1[0]=='n' || flag1[0]=='N') {
					po = new CDriver(id,name,age,gender);
					break;
				} else {
					cout<<"输入有误请重新输入: ";
				}
			}
			
			vehicle.setOwner(*po);
			PManager.addPerson(*po);
			return;
		} else if (flag[0]=='n' || flag[0]=='N') {
			return;
		} else {
			cout<<"输入有误请重新输入: ";
		}	
	} 
}

void CShow::addDriver(CVehicle& vehicle) {
	string id;
	string name;
	string gender;
	int age;
	int year,month,day; 
	string flag;
	cout<<"是否输入该车的驾驶人信息？(y/n)";
	while (true) {
		cin>>flag;
		trim(flag);
		if (flag[0]=='y' || flag[0]=='Y') {
			CPerson* pd;
			cout<<"请输入驾驶人ID：";
			cin>>id;
			pd = PManager.SearchPersonWithNo(id);
			if (pd!=nullptr) {
				CDriver* pdd = (CDriver*)pd;
				if (pdd->getTime()==nullptr) {
					cout<<"该驾驶人获取驾照的时间未知，请录入(年月日以空格分隔): ";
					cin>>year>>month>>day;
					cin.clear();
					pdd->setTime(year,month,day);
					pd = pdd;
				}
				vehicle.setDriver(*pd);
				return;	
			}
			cout<<"请输入驾驶人姓名：";
			cin>>name;
			cout<<"请输入驾驶人性别：";
			cin>>gender;
			cout<<"请输入驾驶人年龄：";
			cin>>age;
			cin.clear(); 
			
			CDriver* pdd = new CDriver(id,name,age,gender);
			cout<<"请依次输入所有人获得驾照时间的年月日(以空格分隔)：";
			cin>>year>>month>>day;
			cin.clear();
			pdd->setTime(year,month,day);
			pd = pdd;
			
			vehicle.setDriver(*pd);
			PManager.addPerson(*pd);
			return;
		} else if (flag[0]=='n' || flag[0]=='N') {
			return;
		} else {
			cout<<"输入有误请重新输入: ";
		}	
	} 
}

void CShow::SearchVehicleWithNo() {
	string cid;
	cout<<"请输入要查询的车辆车牌号：";
	cin>>cid;
	CVehicle* pb = Manager.SearchVehicleWithNo(cid);
	if (pb!=nullptr) pb->putAll();
}

void CShow::SearchVehicleWithOwner() {
	string id;
	string name;
	string flag;
	cout<<"请选择查询方式(0 按ID查询，1 按Name查询)：";
	cin>>flag;
	trim(flag);
	vector<CVehicle*> vehiclelist;
	if (flag[0]=='0') {
		cout<<"请输入所有人ID：";
		cin>>id;
		if (Manager.SearchVehicleWithOwner(vehiclelist,id,0)) {
			for (int i=0;i<vehiclelist.size();i++) {
				cout<<"No."<<i<<endl;
				vehiclelist[i]->putAll();
			}	
		}
	} else if (flag[0]=='1') {
		cout<<"请输入所有人Name：";
		cin>>name;
		if (Manager.SearchVehicleWithOwner(vehiclelist,name)) {
			for (int i=0;i<vehiclelist.size();i++) {
				cout<<"No."<<i<<endl;
				vehiclelist[i]->putAll();
			}	
		}
	}
}

void CShow::ReportCount() {
	cout<<"CVehicle::VehicleNum: "<<CVehicle::getVehicleNum()<<endl;
	PManager.reportPersonCount();
	Manager.reportVehicleCount();
}
