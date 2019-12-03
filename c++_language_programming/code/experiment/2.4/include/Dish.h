#ifndef DISH_H
#define DISH_H

#include "MyTool.h"

// 菜品名称最大字符长度
// 注意该值改变会导致之前存储的菜单文件失效 
#define DISHNAMELEN 16

class Dish
{
	private:
		char Name[DISHNAMELEN];  // 菜品名称 
		double Price;            // 菜品价格 
		double Discount;         // 菜品折扣 
	public:
		Dish(string name="未知",double price=0.0,double discount=1.0);
		~Dish();
		// 修改菜品名称 
		inline void setName(string name) { memcpy(Name,name.c_str(),DISHNAMELEN); };
		// 修改菜品价格 
		bool setPrice(double price);
		// 修改菜品折扣 
		bool setDiscount(double discount);
		// 获取菜品名称 
		inline string getName() { return Name; };
		// 获取菜品价格 
		inline double getPrice() { return Price; };
		// 获取菜品打折后的价格 
		inline double getGPrice() { return Price*Discount; };
		// 获取菜品折扣 
		inline double getDiscount() { return Discount; };
		// 展示菜品信息 
		void display();
	protected:
};

#endif
