#ifndef INDENTMANAGE_H
#define INDENTMANAGE_H

#include "Indent.h"

class IndentManage
{
	private:
		vector<Indent*> IndentList;  // 订单列表 
	public:
		IndentManage();
		IndentManage(vector<Indent*>& indentlist);
		~IndentManage();
		// 通过No获取订单 
		Indent* operator[](int id);
		// 通过No删除订单 
		bool DeleteIndentWithNo(int id);
		// 通过ID获取订单No 
		int SearchIndentWithID(string id);
		// 通过ID删除订单 
		bool DeleteIndentWithID(string id);
		// 修改订单列表 
		bool setIndentList(vector<Indent*>& indentlist);
		// 修改订单 
		bool setIndent(Indent* indent);
		// 获取订单列表 
		inline vector<Indent*>& getIndentList() { return IndentList; };
		// 清空订单列表 
		void clear();
		// 展示订单列表 
		void display();
	protected:
};

#endif
