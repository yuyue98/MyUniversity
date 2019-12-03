#ifndef DISHITEM_H
#define DISHITEM_H

#include "Dish.h"

class DishItem
{
	private:
		Dish* theDish;  // 菜品指针 
		int Num;        // 菜品数量 
		double Price;   // 合计价格 
	public:
		DishItem(Dish* dish=nullptr,int num=-1,double price=-1.0);
		~DishItem();
		// 修改菜品指针 
		bool setDish(Dish* dish);
		// 修改菜品数量 
		bool setNum(int num);
		// 修改合计价格 
		bool setPrice(double price);
		// 获取菜品指针 
		inline Dish* getDish() { return theDish; };
		// 获取菜品数量 
		inline int getNum() { return Num; };
		// 获取合计价格 
		inline double getPrice() { return Price; };
		// 菜品数量自增一 
		void addNum();
		// 菜品数量自减一 
		bool subNum();
		// 展示订单条目信息 
		void display();
	protected:
};

#endif
