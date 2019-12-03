#ifndef TAKEOUTINDENT_H
#define TAKEOUTINDENT_H

#include "Indent.h"

// 送货地址最大字符长度
// 注意该值改变会导致之前存储的订单文件失效
#define PLACELEN 128
// 手机号最大字符长度
// 注意该值改变会导致之前存储的订单文件失效
#define PHONELEN 32

class TakeoutIndent : public Indent
{
	private:
		static double TPrice;            // 外卖费用 
		double DropoffTime;              // 送货时间 
		char DropoffPlace[PLACELEN];     // 送货地点 
		char PhoneNum[PHONELEN];         // 手机号 
	public:
		TakeoutIndent(double dropofftime=0,string dropoffplace="未知",string phonenum="未知");
		TakeoutIndent(vector<DishItem*>& itemlist,double dropofftime=0,string dropoffplace="未知",string phonenum="未知");
		virtual ~TakeoutIndent();
		// 修改外卖费用 
		static bool setTPrice(double price);
		// 修改送货时间 
		bool setDropoffTime(double dropofftime);
		// 修改送货地点 
		inline void setDropoffPlace(string dropoffplace) { memcpy(DropoffPlace,dropoffplace.c_str(),PLACELEN); };
		// 修改手机号 
		inline void setPhoneNum(string phonenum) { memcpy(PhoneNum,phonenum.c_str(),PHONELEN); };
		// 获取外卖费用 
		static inline double getTPrice() { return TPrice; };
		// 获取送货时间 
		inline double getDropoffTime() { return DropoffTime; };
		// 获取送货地点 
		inline string getDropoffPlace() { return DropoffPlace; };
		// 获取手机号 
		inline string getPhoneNum() { return PhoneNum; };
		// 获取订单类型 
		virtual inline char getType() { return 'T'; };
		// 展示订单简要信息 
		virtual void putIndent();
		// 展示订单详细信息 
		virtual void display();
	protected:
};

#endif
