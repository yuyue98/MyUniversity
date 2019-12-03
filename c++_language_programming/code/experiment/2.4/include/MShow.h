#ifndef MSHOW_H
#define MSHOW_H

#include "MenuManage.h"
#include "IndentManage.h"
#include "CountManage.h"
#include "EatinIndent.h"
#include "TakeoutIndent.h"

class MShow
{
	private:
		string choose;         // 选项内容 
		ifstream in;           // 写文件对象 
		ofstream out;          // 写文件对象 
		MenuManage MManage;    // 菜单管理对象 
		string FileName;       // 当天订单文件名 
		IndentManage IManage;  // 当天订单管理对象 
		CountManage CManage;   // 当天统计管理对象 
		string OFileName;      // 其他订单文件名 
		IndentManage OIManage; // 其他订单管理对象 
		CountManage OCManage;  // 其他统计管理对象
		void admininit();      // 餐厅管理员菜单 
		void menuinit();       // 菜单管理界面 
		void addDish();        // 增加菜品 
		int searchDish();      // 查询菜品 
		void changeDish();     // 修改菜品 
		void deleteDish();     // 删除菜品 
		// 保存菜单 
		void saveDish(vector<Dish*>& dishlist,int id=0);
		int loadDish();        // 读取菜单
		int indentinit();      // 订单管理初始化
		void indentMenu();     // 订单管理界面 
		int searchIndent();    // 查询订单 
		void changeIndent();   // 修改订单 
		void deleteIndent();   // 删除订单
		// 保存订单 
		void saveIndent(vector<Indent*>& indentlist,string filename="");
		// 读取订单 
		int loadIndent(IndentManage& IM,CountManage& CM,string filename=""); 
		void countinit();      // 统计管理界面 
		void custinit();       // 顾客菜单
		// 获取相应类型的订单 
		Indent* getIndentType();
		// 点菜 
		void orderDish(Indent* indent);
		// 下单 
		void placeOrder(Indent* indent);
		// 退出 
		void systemquit();
	public:
		MShow();
		~MShow();
		void init();          // 初始化 
		string getFilename(); // 获取当天订单文件名 
		void Menu();          // 主菜单 
		
	protected:
};

#endif
