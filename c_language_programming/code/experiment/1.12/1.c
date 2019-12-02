#include <stdio.h>

typedef struct listnode
{
	int data;
	struct listnode *nextnode;
}listnode;

listnode* jclist(listnode *list1,listnode *list2);
void freelist(listnode *list);

int main(int argc, char *argv[])
{
	int data;
	printf("请输入若干个正整数（输入-1为结束标志）：\n");
	while(scanf("%d", &data) != EOF)
	{
		listnode *list1, *list2, *list;
		listnode *p, *q;
		list = (listnode*)malloc(sizeof(listnode));
		list1 = (listnode*)malloc(sizeof(listnode));
		list2 = (listnode*)malloc(sizeof(listnode));
		if(!list || !list1 || !list2)
		{
			printf("内存申请失败！\n");
			exit(0);
		}
		list1->nextnode = list2->nextnode = NULL;
		q = list1;
		while(data != -1)
		{	
			p = (listnode*)malloc(sizeof(listnode));
			if(!p)
			{
				printf("内存申请失败！\n");
				exit(0);
			}
			q->nextnode = p;
			p->data = data;
			q = p;
			scanf("%d", &data);
		}
		q->nextnode = NULL;
		scanf("%d", &data);
		q = list2;
		while(data != -1)
		{	
			p = (listnode*)malloc(sizeof(listnode));
			if(!p)
			{
				printf("内存申请失败！\n");
				exit(0);
			}
			q->nextnode = p;
			p->data = data;
			q = p;
			scanf("%d", &data);
		}
		q->nextnode = NULL;
		list->nextnode = jclist(list1->nextnode,list2->nextnode);
		q = list;
		do
		{
			q = q->nextnode;
			printf("%d ", q->data);
		}while(q->nextnode != NULL);
		printf("\n请输入若干个正整数（输入-1为结束标志）：\n");	
		//freelist(list);
		//freelist(list1);
		//freelist(list2);
	}
	return 0;
}

listnode* jclist(listnode *list1,listnode *list2)
{
	listnode *q, *p, *t;
	q = list1;
	t = list1;
	p = list2;
	while(q->nextnode != NULL && p->nextnode != NULL)
	{
		q = q->nextnode;
		t->nextnode = p;
		t = p;
		p = p->nextnode;
		t->nextnode = q;
		t = q;
	}
	q = q->nextnode;
	t->nextnode = p;
	if(q != NULL && p->nextnode == NULL)
	p->nextnode = q;
	return list1;
}

void freelist(listnode *list)
{
	listnode *p, *q;
	p = list;
	while(p->nextnode != NULL)
	{
		q = p;
		p = p->nextnode;
		free(q);
	}
	free(p); 
}
