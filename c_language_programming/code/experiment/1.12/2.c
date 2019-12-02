#include <stdio.h>

typedef struct listnode
{
	char xuehao[8];
	char xingming[20];
	int chengji;
	struct listnode *nextnode; 
}listnode;

void scnode(listnode *list);
void freelist(listnode *list);

int main(int argc, char *argv[])
{
	char ch;
	listnode *list, *p, *q;
	int i;
	list = (listnode*)malloc(sizeof(listnode));
	if(!list)
	{
		printf("内存申请失败！\n");
		exit(0);
	}
	p = list;
	printf("请输入若干个学生的学号（共7位，其中2、3位为专业编号），姓名，成绩，以‘#’作为结束标志。\n");
	while((ch = getchar()) != '#')
	{
		p->nextnode = (listnode*)malloc(sizeof(listnode));
		if(!(p->nextnode))
		{
			printf("内存申请失败！\n");
			exit(0);
		}
		p = p->nextnode;
		p->xuehao[0] = ch;
		for(i = 1;i < 7;i++)
		{
			ch = getchar();
			p->xuehao[i] = ch;
		}
		p->xuehao[i] = '\0';
		getchar();
		ch = getchar();
		i = 0;
		while(ch != ' ')
		{
			p->xingming[i] = ch;
			i++;
			ch = getchar();
		}
		p->xingming[i] = '\0';
		scanf("%d", &p->chengji);
		getchar();
	}
	p->nextnode = NULL;
	scnode(list);
	p = list->nextnode;
	while(p)
	{
		printf("%s %s %d\n", p->xuehao, p->xingming, p->chengji);
		p = p->nextnode;
	}
	free(list);
	return 0;
}

void scnode(listnode *list)
{
	listnode *p, *q, *t;
	q = list;
	p = list->nextnode;
	while(p)
	{
		if(p->xuehao[1] == '0' && p->xuehao[2] == '2')
		{
			t = p;
			p = p->nextnode;
			q->nextnode = p;
			free(t);
			
		}
		else
		{
			q = p;
			p = p->nextnode;	
		}
	}
}

void freelist(listnode *list)
{
	listnode *p, *q;
	p = list->nextnode;
	while(p)
	{
		q = p;
		p = p->nextnode;
		free(q);
	}
	free(list);
	list = NULL;
}
