#include "myheader.h"
#include "FractionalAddition.h"

fenshu initlist(fenshu L)
{
	L = (fenshu)malloc(sizeof(struct lnode));
    L->fenmu = 1;
    L->fenzi = 0;
    L->next = NULL;
	if(!L)
	{
		printf("内存申请失败！\n");
		exit(OVERFLOW);
	}
	return L;
}

int getlist(fenshu L)
{
	int a;
	int i;
	int num = 0;
	fenshu p, q;
	printf("请输入需要相加的分数个数：");
	scanf("%d", &a);
    getchar();
	q = L;
	for(i = 1;i <= a;i++)
	{
		p = (fenshu)malloc(sizeof(struct lnode));
		p->fenmu=1;
		p->fenzi=0;
		p->next=NULL;
		if(!p)
		{
			printf("内存分配失败！\n");
			exit(OVERFLOW);
		}
		printf("请输入第%d个分数的分子：", i);
		scanf("%d",&num);
		p->fenzi = num;
		// scanf("%d", &(p->fenzi));
        getchar();
		printf("请输入第%d个分数的分母：", i);
		scanf("%d",&num);
		p->fenmu = num;
		// scanf("%d", &(p->fenmu));
		getchar();
		q->next = p;
		q = p;
	}
	q = L->next;
	printf("此时链表为：\n");
	printf("头结点");
	while(q)
	{
		printf("->%d/%d", q->fenzi, q->fenmu);
		q = q->next;
	} 
	printf("->NULL\n");
	return a;
}

int destroylist(fenshu L)
{
    fenshu p;
    while(L)
    {
        p = L->next;
        free(L);
        L = p;
    }
    return OK;
}

int fracadd(fenshu L,int n)
{
	fenshu p, q;
	q = L->next;
	int y, b;
	int d = 0;
	char a;
	int c; 
	p = (fenshu)malloc(sizeof(struct lnode));
	if(!p)
	{
		printf("内存分配失败！\n");
		exit(OVERFLOW);
	}
	p->fenzi = q->fenzi;
    p->fenmu = q->fenmu;
	while(q)
	{
	    if(n > 1)
	    {
		    if(q->next == NULL)
    	    break;
    		b = gongbei(p->fenmu,q->next->fenmu);
    		p->fenzi = (b/p->fenmu*p->fenzi)+(b/q->next->fenmu*q->next->fenzi);
    		p->fenmu = b;
		    
	    }
   		y = gongyue(p->fenzi,p->fenmu);
	    p->fenzi = p->fenzi / y;
	    p->fenmu = p->fenmu / y;
	    q = q->next;
	}
	if(p->fenzi < p->fenmu)
	{ 
	    printf("这%d个分数相加和为：%d/%d\n", n, p->fenzi, p->fenmu);
        printf("其和为真分数！\n");
	} 
	else if((p->fenzi % p->fenmu) == 0)
	{
	    printf("这%d个分数相加和为：%d\n", n, (p->fenzi / p->fenmu));
	    printf("其和为整数！\n");
    } 
	else
	{
		d = p->fenzi / p->fenmu;
		p->fenzi = p->fenzi % p->fenmu;
		printf("这%d个分数相加和为：%d+%d/%d\n", n, d, p->fenzi ,p->fenmu);
		printf("其和为带分数！\n");
	}
	free(p);
	destroylist(L);
	printf("是否重新建立链表(y/n):");
    scanf("%c", &a);
	getchar();
	printf("%c", a);
	if(a =='y' || a == 'Y')
	{
		system("cls");
		initlist(L);
		c = getlist(L);
		printf("相加分数个数为：%d\n", c);
		fracadd(L,c);
	}
	else
	exit(OVERFLOW);
	return OK;
}

int gongyue(int m,int n)
{
	int t;
	while(n != 0)
	{
	   t = m % n;
	   m = n;
	   n = t; 
	}
	return m;
}

int gongbei(int m,int n)
{
	int t;
	t = gongyue(m,n);
	t = m * n / t;
	return t;
}