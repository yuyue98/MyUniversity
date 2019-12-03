#ifndef COUNTMANAGE_H
#define COUNTMANAGE_H

#include "DishItem.h"
#include "EatinIndent.h"
#include "TakeoutIndent.h"

class CountManage
{
	private:
		string FileName;             // 当前统计订单文件名 
		int Num;                     // 订单总数 
		int ENum;                    // 堂食订单数 
		int TNum;                    // 外卖订单数 
		double Price;                // 总销售额 
		double EPrice;               // 堂食订单销售额
		double TPrice;               // 外卖订单销售额
		vector<DishItem*> ItemList;  // 订单条目列表 
		void countPrice();
		bool setItem(DishItem* dishitem);
	public:
		CountManage(string filename="");
		CountManage(string filename,int num,int Enum,int Tnum,double price,double Eprice,double Tprice,vector<DishItem*> itemlist);
		~CountManage();
		// 获取获取当天订单文件名
		string getFilename();
		// 通过No获取订单条目 
		DishItem* operator[](int id);
		// 通过No删除订单条目 
		bool DeleteItemWithNo(int id);
		// 通过菜品名称获取订单条目No 
		int SearchItemWithName(string name);
		// 通过菜品名称删除订单条目 
		bool DeleteItemWithName(string name);
		// 修改订单条目列表 
		bool setItemList(vector<DishItem*> itemlist);
		// 修改订单条目 
		bool setItem(Dish* dish,int num=1);
		// 修改订单总数 
		bool setNum(int num);
		// 修改堂食订单数 
		bool setENum(int Enum);
		// 修改外卖订单数 
		bool setTNum(int Tnum);
		// 修改总销售额 
		bool setPrice(double price);
		// 修改堂食订单销售额 
		bool setEPrice(double Eprice);
		// 修改外卖订单销售额 
		bool setTPrice(double Tprice);
		// 修改当前统计订单的时间
		inline bool setFileName(string filename) { FileName = filename; return true; };
		// 通过订单列表统计 
		bool countIndent(vector<Indent*>& indentlist);
		// 通过订单指针统计 
		bool countIndent(Indent* indent);
		// 获取订单条目列表 
		inline vector<DishItem*>& getItemList();
		// 获取订单总数 
		inline double getNum() { return Num; };
		// 获取堂食订单数 
		inline double getENum() { return ENum; };
		// 获取外卖订单数 
		inline double getTNum() { return TNum; };
		// 获取总销售额 
		inline double getPrice() { return Price; };
		// 获取堂食订单销售额 
		inline double getEPrice() { return EPrice; };
		// 获取外卖订单销售额 
		inline double getTPrice() { return TPrice; };
		// 初始化统计数据 
		void clear();
		// 展示所有订单条目信息 
		void putBody();
		// 展示统计信息
		void display();
	protected:
};

#endif
