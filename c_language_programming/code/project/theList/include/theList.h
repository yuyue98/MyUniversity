#ifndef THELIST_H
#define THELIST_H

typedef struct lnode
{
	char data;
	struct lnode *next;
}lnode,*stulist;

stulist initlist(stulist L);//初始化链表
int inputlist(stulist L);//建立链表
int blanklist(stulist L);//判断为空链表 
int reverlist(stulist L);//反转数据 

#endif