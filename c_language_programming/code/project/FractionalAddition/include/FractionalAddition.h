#ifndef FRACTIONALADDITION_H
#define FRACTIONALADDITION_H

typedef struct lnode
{
	int fenzi;
	int fenmu;
	struct lnode *next;
}list, *fenshu;

fenshu initlist(fenshu L);
int getlist(fenshu L);
int destroylist(fenshu L);
int fracadd(fenshu L,int n);
int gongyue(int m,int n);
int gongbei(int m,int n);

#endif