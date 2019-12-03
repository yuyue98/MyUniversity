#include "MShow.h"

MShow::MShow() {
}

MShow::~MShow() {
}

void MShow::init() {
	choose = "";
	in.clear();
	out.clear();
	MManage.clear();
	IManage.clear();
	CManage.clear();
	OFileName = "";
	OIManage.clear();
	OCManage.clear();
	loadDish();
	cout<<"订单文件文件夹创建中。。。"<<endl;
	bool flag = createFolder("Indent");
	if (flag) {
		cout<<"订单文件夹创建成功！"<<endl;
	} else {
		cout<<"订单文件夹已存在！"<<endl;
	}
	FileName = getFilename();
	loadIndent(IManage,CManage); 
}


string MShow::getFilename() {
	time_t mytime = time(nullptr);
	tm* mytm = localtime(&mytime);
	char thetime[11];
	sprintf(thetime,"%04d-%02d-%02d\0",1900+(mytm->tm_year),1+(mytm->tm_mon),mytm->tm_mday);
	string theTime = thetime;
	return (theTime+".dat");
}

void MShow::Menu() {
	init();
	while (true) {
		cout<<"++++++++用户登录界面++++++++"<<endl;
		cout<<"       1、餐厅管理员"<<endl;
		cout<<"       2、顾客"<<endl;
		cout<<"       3、退出"<<endl;
		cout<<"请输入所选项前的序号：";
		cin>>choose;
		trim(choose);
		system("cls");
		cin.clear();
		switch(choose[0]) {
			case '1':admininit();break;
			case '2':custinit();break;
			case '3':systemquit();break;
			default:cout<<"输入有误请重新输入！"<<endl;break;
		}
	}
}

void MShow::admininit() {
	string password;
	do {
		system("cls");
		cout<<"请输入密码：";
		cin>>password;
		trim(password);
		if ("quit"==password) {
			return;
		}
	} while ("123456"!=password);
	cout<<"登录成功！"<<endl; 
	while (true) {
		cout<<"++++++++餐厅管理员界面++++++++"<<endl;
		cout<<"        1、菜单管理"<<endl;
		cout<<"        2、订单管理"<<endl;
		cout<<"        3、统计管理"<<endl;
		cout<<"        4、返回上一层"<<endl;
		cout<<"        5、退出"<<endl;
		cout<<"请输入所选项前的序号：";
		cin>>choose;
		trim(choose);
		system("cls");
		cin.clear();
		switch(choose[0]) {
			case '1':menuinit();break;
			case '2':if(indentinit())indentMenu();break;
			case '3':countinit();break;
			case '4':return;
			case '5':systemquit();break;
			default:cout<<"输入有误请重新输入！"<<endl;break;
		}
	}
	
}

void MShow::menuinit() {
	while (true) {
		cout<<"++++++++菜单管理界面++++++++"<<endl;
		cout<<"        1、显示菜单"<<endl;
		cout<<"        2、增加菜品"<<endl;
		cout<<"        3、修改菜品"<<endl;
		cout<<"        4、删除菜品"<<endl;
		cout<<"        5、保存菜单"<<endl; 
		cout<<"        6、读取菜单"<<endl; 
		cout<<"        7、返回上一层"<<endl;
		cout<<"        8、退出"<<endl;
		cout<<"请输入所选项前的序号：";
		cin>>choose;
		trim(choose);
		system("cls");
		cin.clear();
		switch(choose[0]) {
			case '1':MManage.display();break;
			case '2':addDish();break;
			case '3':changeDish();break;
			case '4':deleteDish();break;
			case '5':saveDish(MManage.getDishList());break;
			case '6':loadDish();break;
			case '7':return;
			case '8':systemquit();break;
			default:cout<<"输入有误请重新输入！"<<endl;break;
		}
	}
}

void MShow::addDish() {
	string name;
	double price;
	double discount;
	while (true) {
		system("cls");
		cout<<"请输入菜品名称(len<=7)：";
		cin>>name;
		trim(name);
		if (-1==MManage.SearchDishWithName(name)) {
			break;
		} else {
			cout<<"该"<<name<<"已存在,请重新输入！"<<endl;
		}
	} 
	cout<<"请输入菜品价格：";
	cin>>price;
	cin.clear();
	cout<<"请输入菜品折扣：";
	cin>>discount;
	cin.clear();
	Dish* dish = new Dish(name,price,discount);
	MManage.setDish(dish);
} 

int MShow::searchDish() {
	while (true) {
		cout<<"++++++++获取菜品方式++++++++"<<endl;
		cout<<"       1、显示菜单"<<endl;
		cout<<"       2、按序号查询"<<endl;
		cout<<"       3、按名称查询"<<endl;
		cout<<"       4、返回上一层"<<endl;
		cout<<"请输入所选项前的序号：";
		cin>>choose;
		trim(choose);
		system("cls");
		cin.clear();
		if ('1'==choose[0]) {
			MManage.display();
		} else if ('2'==choose[0]) {
			int no;
			cout<<"请输入需要查询的菜单No：";
			cin>>no;
			cin.clear();
			Dish* dish = MManage[no];
			if (dish) {
				return no;
			} else {
				cout<<"所选菜品No不存在，请检查！"<<endl;
			}
		} else if ('3'==choose[0]) {
			string name;
			cout<<"请输入需要查询的菜单Name：";
			cin>>name;
			trim(name);
			cin.clear();
			int i = MManage.SearchDishWithName(name);
			if (-1!=i) {
				return i;
			} else {
				cout<<"所选菜品Name不存在，请检查！"<<endl;
			}
		} else if ('4'==choose[0]) {
			return -1;
		} else {
			cout<<"输入有误请重新输入！"<<endl;
			continue;
		}
	}
} 

void MShow::changeDish() {
	int i = searchDish();
	if (-1==i) return;
	Dish* dish = MManage[i];
	putStr("Name",DISHNAMELEN);
	putStr("Price");
	putStr("Discount");
	cout<<endl;
	dish->display();
	cout<<"选择菜品信息如上，是否修改(y/n)：";
	cin>>choose;
	trim(choose);
	cin.clear();
	if ('y'==choose[0]||'Y'==choose[0]) {
		MManage.DeleteDishWithNo(i);
		addDish(); 
		cout<<"修改成功！"<<endl;
	}
}

void MShow::deleteDish() {
	int i = searchDish();
	if (-1==i) return;
	Dish* dish = MManage[i];
	putStr("Name",DISHNAMELEN);
	putStr("Price");
	putStr("Discount");
	cout<<endl;
	dish->display();
	cout<<"选择菜品信息如上，是否删除(y/n)：";
	cin>>choose;
	trim(choose);
	cin.clear();
	if ('y'==choose[0]||'Y'==choose[0]) {
		MManage.DeleteDishWithNo(i);
		cout<<"删除成功！"<<endl;
	}
}


void MShow::saveDish(vector<Dish*>& dishlist,int id) {
	if (dishlist.empty()) {
		return;
	}
	in.open("MyMenu.dat",ios::in|ios::binary);
	if (in.is_open()) {
		cout<<"菜单文件存在，保存备份中。。。"<<endl;
		in.close();
		in.clear();
		cpfile("MyMenu.dat","MyMenu.dat.bak");
		cout<<"保存备份成功！"<<endl;
	} else {
		in.clear();
	}
	out.open("MyMenu.dat",ios::out|ios::binary);
	if (out.is_open()) {
		cout<<"菜单文件打开成功！"<<endl;
		Dish* dish; 
		out.seekp(id*sizeof(*dish));
		for (int i=0;i<dishlist.size();i++) {
			out.write((char*)dishlist[i],sizeof(*(dishlist[i])));
		}
		out.close();
		cout<<"保存成功！"<<endl;
	} else {
		cerr<<"菜单文件打开失败！"<<endl;
	}
	out.clear();
}

int MShow::loadDish() {
	if (!(MManage.getDishList().empty())) {
		cout<<"当前内存中已存在菜单，是否继续读取(y/n)：";
		cin>>choose;
		trim(choose);
		cin.clear();
		if ('y'!=choose[0]&&'Y'!=choose[0]) {
			return 1;
		}
	} else {
		cout<<"当前菜单无内容，正在读取文件。。。"<<endl;
	}
	in.open("MyMenu.dat",ios::in|ios::binary);
	if (!(in.is_open())) {
		cerr<<"菜单文件不存在！"<<endl;
		in.clear();
		in.open("MyMenu.dat.bak",ios::in|ios::binary);
		if (in.is_open()) {
			cout<<"备份文件存在，是否继续读取(y/n)：";
			cin>>choose;
			trim(choose);
			cin.clear();
			in.close();
			in.clear();
			if ('y'==choose[0]||'Y'==choose[0]) {
				cpfile("MyMenu.dat.bak","MyMenu.dat");
				in.open("MyMenu.dat",ios::in|ios::binary);
			} else {
				return 0;
			}
		} else {
			cerr<<"备份文件不存在！"<<endl;
			in.clear();
			return 0;
		}	
	}
	cout<<"菜单文件打开成功！"<<endl;
	Dish dish;
	Dish* pd;
	in.read((char*)&dish,sizeof(dish));
	while (!in.eof()) {
		pd = new Dish(dish.getName(),dish.getPrice(),dish.getDiscount());
		MManage.setDish(pd);
		in.read((char*)&dish,sizeof(dish));
	}
	in.close(); 
	in.clear();
	cout<<"读取成功！"<<endl;
	return 2;
}

int MShow::indentinit() {
	cout<<"订单文件列表获取中。。。"<<endl;
	vector<_finddata_t*> stats;
	getFileStats("./Indent",stats);
	if (stats.empty()) {
		cout<<"订单文件不存在！"<<endl;
		return 0;
	}
	cout<<"获取成功，文件列表如下："<<endl;
	int num;
	while (true) {
		cout<<"++++++++++订单列表++++++++++"<<endl;;
		putStr("No");
		putStr("FName",16);
		putStr("Size"); 
		cout<<endl;
		for (int i=0;i<stats.size();i++) {
			putStr(toString(i));
			putStr(stats[i]->name,16);
			putStr(toString(stats[i]->size));
			cout<<endl;
		}
		cout<<"请输入所需查看订单文件前的序号：";
		cin>>choose;
		trim(choose);
		if ("quit"==choose) {
			return 0;
		}
		system("cls");
		cin.clear();
		num = stringToNum<int>(choose);
		if (num<stats.size()&&num>=0) {
			cout<<"输入序号正确！"<<endl;
			break;
		} else {
			cout<<"输入序号有误，请重新输入！"<<endl;
		}
	}
	OFileName = stats[num]->name;
	return loadIndent(OIManage,OCManage,OFileName);
} 

void MShow::indentMenu() {
	while (true) {
		cout<<"++++++++订单管理界面++++++++"<<endl;
		cout<<"        1、显示订单"<<endl;
		cout<<"        2、修改订单"<<endl;
		cout<<"        3、删除订单"<<endl;
		cout<<"        4、保存订单"<<endl; 
		cout<<"        5、读取订单"<<endl; 
		cout<<"        6、返回上一层"<<endl;
		cout<<"        7、退出"<<endl;
		cout<<"请输入所选项前的序号：";
		cin>>choose;
		trim(choose);
		system("cls");
		cin.clear();
		switch(choose[0]) {
			case '1':OIManage.display();break;
			case '2':changeIndent();break;
			case '3':deleteIndent();break;
			case '4':saveIndent(OIManage.getIndentList(),OFileName);break;
			case '5':indentinit();break;
			case '6':return;
			case '7':systemquit();break;
			default:cout<<"输入有误请重新输入！"<<endl;break;
		}
	}
}

int MShow::searchIndent() {
	while (true) {
		cout<<"++++++++获取订单方式++++++++"<<endl;
		cout<<"       1、显示订单"<<endl;
		cout<<"       2、按序号查询"<<endl;
		cout<<"       3、按ID查询"<<endl;
		cout<<"       4、返回上一层"<<endl;
		cout<<"请输入所选项前的序号：";
		cin>>choose;
		trim(choose);
		system("cls");
		cin.clear();
		if ('1'==choose[0]) {
			OIManage.display();
		} else if ('2'==choose[0]) {
			int no;
			cout<<"请输入需要查询的订单No：";
			cin>>no;
			cin.clear();
			Indent* indent = OIManage[no];
			if (indent) {
				return no;
			} else {
				cout<<"所选订单No不存在，请检查！"<<endl;
			}
		} else if ('3'==choose[0]) {
			string id;
			cout<<"请输入需要查询的订单ID：";
			cin>>id;
			trim(id);
			cin.clear();
			int i = OIManage.SearchIndentWithID(id);
			if (-1!=i) {
				return i;
			} else {
				cout<<"所选订单ID不存在，请检查！"<<endl;
			}
		} else if ('4'==choose[0]) {
			return -1;
		} else {
			cout<<"输入有误请重新输入！"<<endl;
			continue;
		}
	}
}

void MShow::changeIndent() {
	int i = searchIndent();
	if (-1==i) return;
	Indent* indent = OIManage[i];
	DishItem* dishitem;
	Dish* dish;
	int id;
	string dishname;
	while (true) {
		indent->display();
		cout<<"请输入需要修改的字段名称(输入back返回,help帮助)：";
		cin>>choose;
		trim(choose);
		system("cls");
		cin.clear();
		int num; 
		if ('T'==indent->getType()&&"送货时间"==choose) {
			double dropofftime;
			cout<<"请输入送货时间(min)：";
			cin>>dropofftime;
			cin.clear();
			((TakeoutIndent*)indent)->setDropoffTime(dropofftime);
		} else if ('T'==indent->getType()&&"送货地点"==choose) {
			string dropoffplace;
			cout<<"请输入送货地点(LEN<=64)：";
			cin>>dropoffplace;
			cin.clear();
			((TakeoutIndent*)indent)->setDropoffPlace(dropoffplace);
		} else if ('E'==indent->getType()&&"手机号"==choose) {
			string phone;
			cout<<"请输入手机号(LEN<=32)：";
			cin>>phone;
			cin.clear();
			((TakeoutIndent*)indent)->setPhoneNum(phone);
		} else if ('E'==indent->getType()&&"桌号"==choose) {
			string tid;
			cout<<"请输入桌号(<=1000)：";
			cin>>tid;
			cin.clear();
			((EatinIndent*)indent)->setTID(tid);
		} else if ('E'==indent->getType()&&"房间号"==choose) {
			string tid;
			cout<<"请输入房间号(<=1000)：";
			cin>>tid;
			cin.clear();
			((EatinIndent*)indent)->setTID(tid);
		} else if ('E'==indent->getType()&&"包间"==choose) {
			((EatinIndent*)indent)->setisRoom(true);
		} else if ('E'==indent->getType()&&"不包间"==choose) {
			((EatinIndent*)indent)->setisRoom(false);
		} else if ("订单条目"==choose) {
			cout<<"请输入需要修改的订单条目序号：";
			cin>>num;
			cin.clear();
			dishitem = (*indent)[num];
			if (dishitem) {
				cout<<"请输入菜品名称：";
				cin>>dishname;
				trim(dishname);
				cin.clear();
				id = MManage.SearchDishWithName(dishname);
				cout<<"请输入菜品数量："; 
				cin>>num;
				cin.clear();
				if (-1!=id) {
					dishitem->setDish(MManage[id]);
				}
				dishitem->setNum(num);
			} else {
				cout<<"输入订单序号有误！"<<endl;
			}
		} else if ("帮助"==choose||"help"==choose) {
			cout<<"可使用命令如下："<<endl;
			cout<<"送货时间  送货地点  手机号"<<endl;
			cout<<"桌号      房间号    不包间    包间"<<endl;
			cout<<"订单条目  帮助      返回"<<endl;
		} else if ("返回"==choose||"back"==choose) {
			break;
		} else {
			cout<<"输入有误请重新输入！"<<endl;
		} 
	}
	cout<<"修改完成！"<<endl;
}

void MShow::deleteIndent() {
	int i = searchIndent();
	if (-1==i) return;
	Indent* indent = OIManage[i];
	indent->display();
	cout<<"选择订单信息如上，是否删除(y/n)：";
	cin>>choose;
	trim(choose);
	cin.clear();
	if ('y'==choose[0]||'Y'==choose[0]) {
		OIManage.DeleteIndentWithNo(i);
		cout<<"删除成功！"<<endl;
	}
}

void MShow::saveIndent(vector<Indent*>& indentlist,string filename) {
	if (indentlist.empty()) {
		return;
	}
	if (""==filename) {
		filename = getFilename();
	}
	string path = "./Indent/"+filename;
	out.open(path,ios::out|ios::binary);
	if (!out.is_open()) {
		cerr<<"订单文件打开失败！"<<endl;
		out.clear();
		return;
	}
	cout<<"订单文件打开成功！"<<endl;
	/* 订单类指针 */ 
	Indent* ii;
	EatinIndent* ei;
	TakeoutIndent* ti;
	/* 订单基本信息 */ 
	char type;
	string id;
	time_t ordertime;
	double price;
	/* 堂食订单额外信息 */ 
	string tid;
	bool isroom; 
	/* 外卖订单额外信息 */ 
	double dropofftime;
	string dropoffplace;
	string phone;
	/* 订单条目属性 */
	int num;
	string dishname;
	int dishnum;
	double dishprice;
	/* 循环写入文件 */ 
	for (int i=0;i<indentlist.size();i++) {
		ii = (Indent*)(indentlist[i]);
		type = ii->getType();
		out.write((char*)&type,1);
		if ('E'==type) {
			ei = (EatinIndent*)(ii);
			tid = ei->getTID();
			isroom = ei->getisRoom();
			out.write((char*)tid.c_str(),TIDLEN);
			out.write((char*)&isroom,sizeof(isroom));
		} else if ('T'==type) {
			TakeoutIndent* ti = (TakeoutIndent*)(ii);
			dropofftime = ti->getDropoffTime();
			dropoffplace = ti->getDropoffPlace();
			phone = ti->getPhoneNum();
			out.write((char*)&dropofftime,sizeof(dropofftime));
			out.write((char*)dropoffplace.c_str(),PLACELEN);
			out.write((char*)phone.c_str(),PHONELEN);
		}
		id = ii->getID();
		ordertime = ii->getOrderTime();
		price = ii->getPrice();
		out.write((char*)id.c_str(),INDENTIDLEN);
		out.write((char*)&ordertime,sizeof(ordertime));
		out.write((char*)&price,sizeof(price));
		vector<DishItem*>& dishlist = ii->getItemList();
		num = dishlist.size();
		out.write((char*)&num,sizeof(num));
		for (int j=0;j<num;j++) {
			dishname = dishlist[j]->getDish()->getName();
			dishnum = dishlist[j]->getNum();
			dishprice = dishlist[j]->getPrice();
			out.write((char*)dishname.c_str(),DISHNAMELEN);
			out.write((char*)&dishnum,sizeof(dishnum));
			out.write((char*)&dishprice,sizeof(dishprice));
		}
	}
	out.close();
	out.clear();
	cout<<"保存成功！"<<endl;
}

int MShow::loadIndent(IndentManage& IM,CountManage& CM,string filename) {
	if (!(IM.getIndentList().empty())) {
		cout<<"当前内存中已存在订单列表，是否继续读取(y/n)：";
		cin>>choose;
		trim(choose);
		cin.clear();
		if ('y'!=choose[0]&&'Y'!=choose[0]) {
			return 1;
		}
	} else {
		cout<<"当前订单列表无内容，正在读取文件。。。"<<endl;
	}
	if (""==filename) {
		filename = getFilename();
	}
	string path = "./Indent/"+filename; 
	in.open(path,ios::in|ios::binary);
	if (!in.is_open()) {
		cerr<<filename<<"订单文件不存在！"<<endl;
		in.clear();
		return 0;
	}
	cout<<"订单文件打开成功！"<<endl;
	IM.clear();
	CM.clear();
	/* 菜品指针 */ 
	Dish* dish;
	/* 订单类指针 */ 
	Indent* ii;
	/* 订单基本信息 */ 
	char type;
	string id;
	time_t ordertime;
	double price;
	/* 堂食订单额外信息 */ 
	string tid;
	bool isroom; 
	/* 外卖订单额外信息 */ 
	double dropofftime;
	string dropoffplace;
	string phone;
	/* 订单条目属性 */
	int num;
	string dishname;
	int dishnum;
	double dishprice;
	in.read((char*)&type,1);
	while (!in.eof()) {
		if ('I'==type) {
			ii = new Indent();
		} else if ('E'==type) {
			char abuf[TIDLEN];
			in.read((char*)abuf,TIDLEN);
			tid = abuf;
			in.read((char*)&isroom,sizeof(isroom));
			ii = new EatinIndent(tid,isroom);
		} else if ('T'==type) {
			in.read((char*)&dropofftime,sizeof(dropofftime));
			char abuf[PLACELEN];
			in.read((char*)abuf,PLACELEN);
			dropoffplace = abuf;
			char bbuf[PHONELEN];
			in.read((char*)bbuf,PHONELEN);
			phone = bbuf;
			ii = new TakeoutIndent(dropofftime,dropoffplace,phone);
		} else {
			continue;
		}
		char abuf[INDENTIDLEN];
		in.read((char*)abuf,INDENTIDLEN);
		id = abuf;
		ii->setID(id);
		in.read((char*)&ordertime,sizeof(ordertime));
		ii->setOrderTime(ordertime);
		in.read((char*)&price,sizeof(price));
		in.read((char*)&num,sizeof(num));
		for (int j=0;j<num;j++) {
			char abuf[DISHNAMELEN];
			in.read((char*)abuf,DISHNAMELEN);
			dishname = abuf;
			in.read((char*)&dishnum,sizeof(dishnum));
			in.read((char*)&dishprice,sizeof(dishprice));
			int k = MManage.SearchDishWithName(dishname);
			if (-1!=k) {
				dish = MManage[k];
				ii->setItem(dish,dishnum);
			} else {
				continue;
			}
		}
		IM.setIndent(ii);
		CM.countIndent(ii);
		CM.setFileName(filename);
		in.read((char*)&type,1);
	}
	in.close(); 
	in.clear();
	cout<<"读取成功！"<<endl;
	return 2;
}

void MShow::countinit() {
	while (true) {
		cout<<"++++++++统计管理界面++++++++"<<endl;
		cout<<"       1、查看当天统计内容"<<endl;
		cout<<"       2、查看其他统计内容"<<endl;
		cout<<"       3、返回上层"<<endl;
		cout<<"       4、退出"<<endl;
		cout<<"请输入所选项前的序号：";
		cin>>choose;
		trim(choose);
		system("cls");
		cin.clear();
		if ('1'==choose[0]) {
			CManage.display();
		} else if ('2'==choose[0]) {
			if (!indentinit()) continue;
			OCManage.display();
		} else if ('3'==choose[0]) {
			break;
		} else if ('4'==choose[0]) {
			systemquit();
		} else {
			cout<<"输入有误请重新输入！"<<endl;
			continue;
		}
	}
}

void MShow::custinit() {
	if (MManage.getDishList().empty()) {
		cout<<"系统错误，请让管理员修复！"<<endl;
		return;
	}
	Indent* indent = getIndentType();
	if (!indent) return;
	while (true) {
		cout<<"++++++++顾客界面++++++++"<<endl;
		cout<<"      1、显示菜单"<<endl;
		cout<<"      2、显示订单"<<endl;
		cout<<"      3、点菜"<<endl;
		cout<<"      4、下单"<<endl;
		cout<<"      5、返回上一层"<<endl;
		cout<<"      6、退出"<<endl;
		cout<<"请输入所选项前的序号：";
		cin>>choose;
		trim(choose);
		system("cls");
		cin.clear();
		switch(choose[0]) {
			case '1':MManage.display();break;
			case '2':indent->display();break;
			case '3':orderDish(indent);break;
			case '4':placeOrder(indent);return;
			case '5':return;
			case '6':systemquit();break;
			default:cout<<"输入有误请重新输入！"<<endl;break;
		}
	}
}

Indent* MShow::getIndentType() {
	while (true) {
		cout<<"++++++++选择订单类型++++++++"<<endl;
		cout<<"        1、堂食"<<endl;
		cout<<"        2、外卖"<<endl;
		cout<<"        3、其他"<<endl;
		cout<<"        4、返回上一层"<<endl;
		cout<<"请输入所选项前的序号：";
		cin>>choose;
		trim(choose);
		system("cls");
		cin.clear();
		if ('1'==choose[0]) {
			bool flag = false;
			string tid;
			cout<<"是否需要包间(y/n)：";
			cin>>choose;
			trim(choose);
			cin.clear();
			if ('y'==choose[0]||'Y'==choose[0]) flag = true;
			if (flag) cout<<"请输入选择房间号(<1000)：";
			else cout<<"请输入选择的桌号(<1000)：";
			cin>>tid;
			trim(tid);
			cin.clear();
			return new EatinIndent(tid,flag); 
		} else if ('2'==choose[0]) {
			double time;
			string place;
			string phone;
			cout<<"请输入最大送货时间(min)：";
			cin>>time;
			cin.clear(); 
			cout<<"请输入取单地点(LEN<=64)：";
			cin>>place;
			trim(place);
			cin.clear(); 
			cout<<"请输入取单电话(LEN<=32)：";
			cin>>phone;
			trim(phone);
			cin.clear(); 
			return new TakeoutIndent(time,place,phone);
		} else if ('3'==choose[0]) {
			return new Indent();
		} else if ('4'==choose[0]) {
			return nullptr;
		} else {
			cout<<"输入有误请重新输入！"<<endl;
		}
	}
}

void MShow::orderDish(Indent* indent) {
	int i = searchDish();
	int num;
	cout<<"请输入菜品数目：";
	cin>>num;
	cin.clear();
	DishItem* dishitem = new DishItem(MManage[i],num);
	indent->setItem(dishitem);
}

void MShow::placeOrder(Indent* indent) {
	indent->setOrderTime(time(nullptr));
	cout<<"当前订单内容如下："<<endl;
	indent->display(); 
	IManage.setIndent(indent); 
	CManage.countIndent(indent);
	saveIndent(IManage.getIndentList(),FileName);
	cout<<"下单成功，是否退出(y/n)：";
	cin>>choose;
	trim(choose);
	cin.clear();
	if ('y'==choose[0]||'Y'==choose[0]) systemquit();
	else return;
}

void MShow::systemquit() {
	saveDish(MManage.getDishList());
	saveIndent(IManage.getIndentList(),FileName);
	saveIndent(OIManage.getIndentList(),OFileName);
	exit(0);
}

