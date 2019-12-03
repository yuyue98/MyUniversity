#ifndef EATININDENT_H
#define EATININDENT_H

#include "Indent.h"

// 桌号/房间号最大字符长度
// 注意该值改变会导致之前存储的订单文件失效 
#define TIDLEN 10

class EatinIndent : public Indent
{
	private:
		static double RPrice;   // 包间费用 
		char TID[TIDLEN];       // 桌号/房间号 
		bool isRoom;            // 是否包间 
	public:
		EatinIndent(string tid="未知",bool isroom=false);
		EatinIndent(vector<DishItem*>& itemlist,string tid="未知",bool isroom=false);
		virtual ~EatinIndent();
		// 修改包间费用 
		static bool setRPrice(double price);
		// 修改桌号 
		inline void setTID(string tid) { memcpy(TID,tid.c_str(),TIDLEN); };
		// 修改是否包间 
		inline void setisRoom(bool isroom) { isRoom = isroom; };
		// 获取包间费用 
		static inline double getRPrice() { return RPrice; };
		// 获取桌号/房间号 
		inline string getTID() { return TID; };
		// 获取是否包间 
		inline bool getisRoom() { return isRoom; };
		// 获取订单类型 
		virtual inline char getType() { return 'E'; };
		// 展示订单简要信息 
		virtual void putIndent();
		// 展示订单详细信息 
		virtual void display();
	protected:
};

#endif
