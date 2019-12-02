#include "myheader.h"
#include "ectree.h"

extern int number;

int inittree(ectree T)
{
	printf("init state!\n");
	printf("please put a root data:");
	scanf("%c", &T->data);
	getchar();
	T->lchild = NULL;
	T->rchild = NULL;
	printf("init end!\n");
	return OK;
}

int inputtree(ectree T)
{
	ectree ltemp, rtemp;
	char l, r, n[4];
	int i;
	printf("put a ltree and a rtree(y/n)?");
	scanf("%c", &l);
	getchar();
	scanf("%c", &r);
	getchar();
	number++;
	if((l == 'n' || l == 'N') && (r == 'n'  || r == 'N'))
	{
		T->lchild = NULL;
		T->rchild = NULL;
		return ERROR;
	}
	else if((l == 'y' || l == 'Y') && (r == 'n'  || r == 'N'))
	{
		ltemp = (ectree)malloc(sizeof(struct ecnode));
		if(!ltemp)
		{
			printf("Malloc memery failed!\n");
			exit(OVERFLOW);
		}
		printf("please put a ldata:");
		scanf("%c", &ltemp->data);
		getchar();
		T->lchild = ltemp;
		T->rchild = NULL;
		inputtree(ltemp);
	}
	else if((l == 'n' || l == 'N') && (r == 'y'  || r == 'Y'))
	{
		rtemp = (ectree)malloc(sizeof(struct ecnode));
		if(!rtemp)
		{
			printf("Malloc memery failed!\n");
			exit(OVERFLOW);
		}
		printf("please put a rdata:");
		scanf("%c", &rtemp->data);
		getchar();
		T->lchild = NULL;
		T->rchild = rtemp;
		inputtree(rtemp);
	}
	else if((l == 'y' || l == 'Y') && (r == 'y'  || r == 'Y'))
	{
		ltemp = (ectree)malloc(sizeof(struct ecnode));
		if(!ltemp)
		{
			printf("Malloc memery failed!\n");
			exit(OVERFLOW);
		}
		rtemp = (ectree)malloc(sizeof(struct ecnode));
		if(!rtemp)
		{
			printf("Malloc memery failed!\n");
			exit(OVERFLOW);
		}
		printf("please put a ldata and a rdata:");
		scanf("%c", &ltemp->data);
		getchar();
		scanf("%c", &rtemp->data);
		getchar();
		T->lchild = ltemp;
		T->rchild = rtemp;
		inputtree(ltemp);
		inputtree(rtemp);
	}
	return OK;
}

int heighttree(ectree T)
{
	int ld,rd;
	if(T == NULL) 
	return 0;
	else 
	{
		ld = heighttree(T->lchild);
		rd = heighttree(T->rchild);
		return 1 + (ld>rd?ld:rd);
	}
}

int blqianxu(ectree T)
{
	if(T)
	{ 
		printf("%c ", T->data);
		blqianxu(T->lchild);
		blqianxu(T->rchild);
	}
	return OK;
} 

int blzhongxu(ectree T)
{
	if(T)
	{ 
		blzhongxu(T->lchild);
		printf("%c ", T->data);
		blzhongxu(T->rchild);
	}
	return OK;
}

int blhouxu(ectree T)
{
	if(T)
	{ 
		blhouxu(T->lchild);
		blhouxu(T->rchild);
		printf("%c ", T->data);
	}
	return OK;
}

squeue initqueue()
{
	squeue Q;
	Q = (squeue)malloc(sizeof(lqnode));
	if(Q)
	{
		Q->front = 0;
		Q->rear = 0;
	}
	return Q; 
}

int emptyqueue(squeue Q)
{
	if(Q && Q->front == Q->rear)
	return 1;
	else 
	return 0;
}

int enqueue(squeue Q,ectree T)
{
	if(Q && (Q->rear + 1) % MAX == Q->front)
	{
		return -1;
	}
	else
	{
		Q->rear = (Q->rear + 1) % MAX;
		Q->base[Q->rear] = T;
		return 1;
	}
	printf("23\n");
}

int outqueue(squeue Q,ectree *T)
{
	if(emptyqueue(Q))
	{
		exit(0);
		return -1;
	}
	else
	{
		Q->front = (Q->front + 1) % MAX;
		*T = Q->base[Q->front];
		return 1;
	}
}

ectree gethead(squeue Q)
{
	if(emptyqueue(Q))
	return NULL;
	else 
	{
		return Q->base[(Q->front + 1) % MAX];
	}
} 

int blqueue(ectree T)
{
	squeue Q;
	ectree p = T;
	Q = initqueue();
	if(p)
	{
		enqueue(Q,p);
		while(!emptyqueue(Q))
		{
			outqueue(Q,&p);
			printf("%c ", p->data);
			if(p->lchild)  
			enqueue(Q,p->lchild);
			if(p->rchild)  
			enqueue(Q,p->rchild);
		}
	}
	return OK;
} 

int destroytree(ectree T)
{
	if(T)
	{
		destroytree(T->lchild);
		destroytree(T->rchild);
		free(T);
	}
	return OK;
}