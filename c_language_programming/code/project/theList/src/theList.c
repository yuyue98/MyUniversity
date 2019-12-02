#include "myheader.h"
#include "theList.h"

stulist initlist(stulist L)
{
	L = (stulist)malloc(sizeof(struct lnode));
	if (!L)
	{
		printf("申请地址失败！");
		exit(OVERFLOW);
	}
	L->next = NULL;
	return L;
} 

int inputlist(stulist L)
{
	stulist p, q;
	int i;
	q = L;
	for (i = 1;i <= MAX;i++)
	{
		p = (struct lnode*)malloc(sizeof(struct lnode));
		if (!p)
		{
			printf("申请内存失败！");
			exit(OVERFLOW);
		}
		printf("请输入第%d个数据：", i);
        scanf("%c", &p->data);
	    getchar();//用于吸收空格 
		q->next = p;
		p->next = NULL;
		q = p;
	}
	p = L->next;
	printf("链表序列为：\n");
	printf("头结点");
	while(p)
	{
		printf("->%c",p -> data);
		p = p->next;
	}
	printf("->NULL\n"); 
	return OK;
}

int blanklist(stulist L)
{
	if (!(L->next))
	{
		printf("此链表为空！\n");
		exit(OVERFLOW); 
	}
}
int reverlist(stulist L)
{
	stulist p, q, a;
	int i;
	if (MAX == 1)
	    {
		    printf("此链表只有一个元素无需反转！\n");
		    exit(OVERFLOW);
	    }
	a = L->next;
	p = a->next;
    q = p->next; 
	for(i = 2;i < MAX;i++)
	{
        p->next = L->next;
		L->next = p;
		p = q;
		q = q->next;
	}
	p->next = L->next;
	L->next = p; 
	a->next = NULL;
	p = L->next;
	printf("链表反转后序列为:\n");
	printf("头结点");
	while(p)
	{
		printf("->%c", p -> data);
		p = p -> next; 
	}
	printf("->NULL\n"); 
	return OK; 
}