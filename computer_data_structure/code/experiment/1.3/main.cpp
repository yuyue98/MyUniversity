#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW 3
#define MAX 8

typedef struct arcnode
{
    int adjvex;
    arcnode *nextart;
    int weight;
}arcnode;

typedef struct vnode
{
    int degree;
    char data;
    arcnode *firstarc;
}vnode, *adjlist;

typedef struct
{
    adjlist vertices;
    int dinnum, biannum;
}algraph;

int initgraph(algraph *G);
int initadjlist(adjlist V);
int buildbian(adjlist V, int dinnum);
int outputljlist(algraph *G);
int dfstraverse(algraph *G);
int bfstraverse(algraph *G);

int main()
{
    algraph *G;
    G = (algraph*)malloc(sizeof(algraph));
    if(!G)
    {
        printf("内存申请失败！\n");
        exit(OVERFLOW);
    }
    initgraph(G);
    printf("生成的邻接表如下：\n");
	outputljlist(G);
	printf("深度优先遍历结果为：");
	dfstraverse(G);
	printf("广度优先遍历结果为：");
	bfstraverse(G); 
    return OK;
}

int initgraph(algraph *G)
{
    int dinnum, biannum;
    printf("请分别输入图的实际顶点数和边数：");
    scanf("%d", &dinnum);
    getchar();
    scanf("%d", &biannum);
    getchar();
    G->dinnum = dinnum;
    G->biannum = biannum;
    G->vertices = (adjlist)malloc(G->dinnum*sizeof(vnode));
    if(!(G->vertices))
    {
        printf("内存申请失败！\n");
        exit(OVERFLOW);
    }
    initadjlist(G->vertices);
    buildbian(G->vertices,G->dinnum);
    return OK;
}

int initadjlist(adjlist V)
{
	int data;
	int i = 0;
	printf("请依次输入所有顶点信息：");
    while((data = getchar()) != '\n')
    {
        V[i].data = data;
        V[i].firstarc = NULL;
        i++;
    }
    return OK;
}

int buildbian(adjlist V, int dinnum)
{
	arcnode *p;
	int i, j;
	char a, b;
	int degree;
	for(i = 0;i < dinnum;i++)
	{
		degree = 0;
		printf("请依次输入第%d顶点边连顶点信息：", i+1);
		while((b = getchar()) != '\n')
		{
			for(j = 0;j < dinnum;j++)
			{
				if(V[j].data == b)
				break;
			}
			if(j == dinnum)
			{
				printf("不存在拥有信息为%c的顶点！\n", b);
				continue;
			}
			else
			{
				degree++;
				p = (arcnode*)malloc(sizeof(arcnode));
				if(!p)
				{
					printf("内存申请失败！\n");
					exit(OVERFLOW);
				}
				p->adjvex = j;
				p->nextart = NULL;
				p->weight = 1;
				if(V[i].firstarc != NULL)
				p->nextart = V[i].firstarc;
				V[i].firstarc = p;
			}//连边 
		}//连边结束	
		V[i].degree = degree; 
	}//建表结束 
	return OK;
}

int outputljlist(algraph *G)
{
	int i, j;
	arcnode *a;
	printf("该邻接表顶点有%d个，边有%d条\n", G->dinnum, G->biannum);
    for(i = 0;i < G->dinnum;i++)
    {
        printf("%d %c ->", (G->vertices)[i].degree, (G->vertices)[i].data);
    	a = G->vertices[i].firstarc;
    	for(j = 0;j < ((G->vertices)[i].degree) - 1;j++)
    	{
	    	printf("adjvex=%d ->", a->adjvex);
	    	a = a->nextart;
	    }
	    if(a == NULL)
	    printf("NULL\n");
	    else
	    printf("adjvex=%d\n", a->adjvex);
    }
	return OK;
}

int dfstraverse(algraph *G)
{
	int i;
	int *flag;
	adjlist v;
	arcnode *p, *q; 
	v = G->vertices;
	flag = (int*)malloc((G->dinnum)*sizeof(int));
	if(!flag)
	{
		printf("内存申请失败！\n");
		exit(OVERFLOW);
	}
	for(i= 0;i < G->dinnum;i++)
	flag[i] = 0;
	/*for(i= 0;i < G->dinnum;i++)
	printf("%d ", flag[i]);
	printf("\n");*/
	for(i= 0;i < G->dinnum;i++)
	{
		if(flag[i] != 0)
		continue;
		else
		{
			printf("->%c", v[i].data);
			flag[i] = 1;
			p = v[i].firstarc;
			while(p != NULL)
			{
				q = p;
				//printf("\nq->adjvex1 = %d\n", q->adjvex);
				while(flag[q->adjvex] == 0)
				{
					//printf("\nq->adjvex2 = %d\n", q->adjvex);
					printf("->%c", v[q->adjvex].data);
					flag[q->adjvex] = 1;
					q = v[q->adjvex].firstarc;
				}
				if(p->nextart == NULL)
				break;
				p = p->nextart;	
			}
		}	
	}
	printf("\n");
	free(flag);
	return OK;
}

int bfstraverse(algraph *G)
{
	int i, m, n;
	int *flag;
	int *cixu;
	adjlist v;
	arcnode *p, *q;
	m = 0;
	n = 0; 
	v = G->vertices;
	flag = (int*)malloc((G->dinnum)*sizeof(int));
	if(!flag)
	{
		printf("内存申请失败！\n");
		exit(OVERFLOW);
	}
	cixu = (int*)malloc((G->dinnum)*sizeof(int));
	if(!cixu)
	{
		printf("内存申请失败！\n");
		exit(OVERFLOW);
	}
	for(i= 0;i < G->dinnum;i++)
	flag[i] = 0;
	/*for(i= 0;i < G->dinnum;i++)
	printf("%d ", flag[i]);
	printf("\n");*/
	for(i= 0;i < G->dinnum;i++)
	{
		if(flag[i] != 0)
		continue;
		else
		{
			flag[i] = 1;
			cixu[n] = i;
			n++;
			while(m != n)
			{
				p = v[cixu[m]].firstarc;
				while(p != NULL)
				{
					if(flag[p->adjvex] == 0)
					{
						cixu[n] = p->adjvex;
						flag[p->adjvex] = 1;
						n++;
					}
					p = p->nextart;
				}
				m++;
			}
		}
	}
	for(i = 0;i < G->dinnum;i++)
	printf("->%c", v[cixu[i]].data);	
	printf("\n");
	free(flag);
	free(cixu);
	return OK;
}
