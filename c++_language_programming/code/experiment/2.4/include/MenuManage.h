#ifndef MENUMANAGE_H
#define MENUMANAGE_H

#include "Dish.h"

class MenuManage
{
	private:
		vector<Dish*> DishList;   // 菜品列表 
	public:
		MenuManage();
		MenuManage(vector<Dish*>& dishlist);
		~MenuManage();
		// 根据No获取菜品 
		Dish* operator[](int id);
		// 根据No删除菜品 
		bool DeleteDishWithNo(int id);
		// 根据Name获取菜品No 
		int SearchDishWithName(string name);
		// 根据Name删除菜品 
		bool DeleteDishWithName(string name);
		// 修改菜品列表 
		bool setDishList(vector<Dish*>& dishlist);
		// 通过Dish指针修改菜品 
		bool setDish(Dish* dish);
		// 通过菜品信息修改菜品 
		bool setDish(string name,double num,double price);
		// 获取菜品列表 
		inline vector<Dish*>& getDishList() { return DishList; };
		// 清空菜品列表 
		void clear();
		// 展示菜单信息 
		void display();
	protected:
};

#endif
