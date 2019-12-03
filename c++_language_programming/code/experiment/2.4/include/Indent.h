#ifndef INDENT_H
#define INDENT_H

#include "DishItem.h"

// 订单ID最大字符长度
// 注意该值改变会导致之前存储的订单文件失效 
#define INDENTIDLEN 20

class Indent
{
	private:
		char ID[INDENTIDLEN];        // 订单ID 
		time_t OrderTime;            // 下单时间 
		double Price;                // 订单价格 
		vector<DishItem*> ItemList;  // 订单条目列表 
		void initItem();             // 初始化订单 
		void countPrice();           // 统计订单价格 
	public:
		Indent();
		Indent(vector<DishItem*>& itemlist);
		virtual ~Indent();
		// 通过No获取订单条目 
		DishItem* operator[](int id);
		// 通过No删除订单条目 
		bool DeleteItemWithNo(int id);
		// 通过菜品名称查找订单条目No 
		int SearchItemWithName(string name);
		// 通过菜品名称删除订单条目 
		bool DeleteItemWithName(string name);
		// 通过No让对应订单条目的菜品数量自增一 
		void addDish(int id);
		// 通过No让对应订单条目的菜品数量自减一 
		void subDish(int id);
		// 修改订单ID 
		inline void setID(string id) { memcpy(ID,id.c_str(),INDENTIDLEN); }; 
		// 修改下单时间 
		inline void setOrderTime(time_t time) { OrderTime = time; };
		// 修改订单价格 
		bool setPrice(double price);
		// 修改订单条目列表 
		bool setItemList(vector<DishItem*>& itemlist);
		// 通过订单条目指针修改或增加订单条目 
		bool setItem(DishItem* dishitem);
		// 通过菜品指针修改或增加订单条目 
		bool setItem(Dish* dish,int num=1);
		// 获取订单ID 
		inline string getID() { return ID; };
		// 获取下单时间 
		inline time_t getOrderTime() { return OrderTime; };
		// 获取订单价格 
		inline double getPrice() { return Price; };
		// 获取订单条目 
		inline vector<DishItem*>& getItemList() { return ItemList; };
		// 获取订单类型 
		virtual inline char getType() { return 'I'; };
		// 初始化该订单对象 
		void clear();
		// 展示订单简要信息 
		virtual void putIndent();
		// 展示所有订单条目信息 
		void putBody(); 
		// 展示订单详细信息 
		virtual void display();
	protected:
};

#endif
