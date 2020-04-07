#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <math.h>
#define MAX 11//结点个数 

typedef struct arcnode
{
	int name;//当前结点名字 
	int size;//连到该结点权值 
	struct arcnode *nextarc;//指向下个结点指针 
}arcnode;//结点数据结构 

typedef struct vnode
{
	int name;//起始结点名字 
	arcnode *firstarc;//指向下个结点的指针	
}vnode, adjlist[MAX];//图数据结构 

int main()
{
	int i, j, k;//循环用变量 
	adjlist tu;//图 
	//图的初始化 
	for (i = 0;i < MAX;i++)
	{
		tu[i].name = i;
		tu[i].firstarc = NULL; 
	}
	arcnode *p, *q;
	int x, y, w;//临时变量，依次放起始结点名，终止结点名，权值 
	//构造该图的邻接表 
	printf("请起点终点权值的格式依次输入边间关系（中间以空格隔开,-1结束输入）：\n");
	while (1)
	{
		scanf("%d", &x);
		getchar();
		//退出循环条件 
		if (x == -1)
			break;
		scanf("%d", &y);
		getchar();
		scanf("%d", &w);
		getchar();
		//动态申请结点空间并赋值
		p = (arcnode*)malloc(sizeof(arcnode)); 
		(*p).name = y;
		(*p).size = w;
		(*p).nextarc = NULL;
		q = tu[x].firstarc;
		tu[x].firstarc = p;	
		if (q != NULL)
			(*p).nextarc = q;	
	}
	//输出图的邻接表形式 
	printf("图的邻接表形式如下：\n");
	for (i = 0;i < MAX;i++)
	{
		printf("%d", tu[i].name);
		q = tu[i].firstarc;
		while (1)
		{
			if (q != NULL)
			{
				printf("->%d:%d", (*q).name, (*q).size);
				q = (*q).nextarc;
			}
			else
				break;	
		}
		printf("\n");
	}
	char zifu[MAX] = {'S','A','B','C','D','E','F','G','H','I','T'};//结点映射标尺 
	int minnum[2][MAX];//第零行记录到达该结点最小权值，第一行记录到达该结点的前驱结点名
	int duilie_x[MAX],duilie_y[MAX];//队列，前者存放结点名，后者存放从S到达该点权值和 
	int tou = 0,wei = 1;//tou为队头指针，wei为队尾指针 
	//变量初始化 
	minnum[0][0] = 0;
	for (i = 1;i < MAX;i++)
		minnum[0][i] = 100;
	for (i = 0;i < MAX;i++)
	{
		duilie_x[i] = 0;
		duilie_y[i] = 0;
	}
	//int timenum0 = 0, timenum1 = 0, timenum2 = 0; 
	//求解最短路径 
	while (tou != wei)
	{
		//timenum0++;
		q = tu[duilie_x[tou]].firstarc;//q指向当前起始点下一个结点或为NULL 
		while (1)
		{
			//timenum1++;
			if (q != NULL)
			{
				if (minnum[0][(*q).name] > duilie_y[tou] + (*q).size)
				{
					minnum[0][(*q).name] = duilie_y[tou] + (*q).size;
					minnum[1][(*q).name] = duilie_x[tou];
					int t = -1;//用于标记在队列中是否有该点
					for (i = tou;i < wei;i++) 
					{
 						//timenum2++;
						if ((*q).name == duilie_x[i])
			 			{
			 				t = i;
			 				break;
			 			}
					}
					if (t != -1)
					{
						duilie_y[t] = minnum[0][(*q).name];
						
					}
					else
					{
						duilie_x[wei] = (*q).name;
						duilie_y[wei] = minnum[0][(*q).name];
						wei++;
					}
				}
				q = (*q).nextarc;
			}
			//第二层循环退出条件 
			else
				break;
		}
		tou++;
		//printf("该算法时间复杂度为：%d %d %d\n", timenum0, timenum1, timenum2);
	} 
	for (i = 0;i < MAX;i++)
	{
		if (minnum[1][i] > 10 || minnum[1][i] < 0)
			printf("\n起始点%c:%d ", zifu[i], minnum[0][i]);
		else
			printf("%c->%c:%d ", zifu[minnum[1][i]], zifu[i], minnum[0][i]);
			//printf("%d->%c:%d ", minnum[1][i], zifu[i], minnum[0][i]);
		
	}
	int lujing[MAX];
	for (i = 1;i < MAX;i++)
		lujing[i] = 0; 
	lujing[0] = 10;
	int m = 0;//指向路径头
	while (minnum[1][lujing[m]] != 0)
	{
		lujing[m+1] = minnum[1][lujing[m]];
		m++;
	}
	printf("\n单源最短路径为：%c", zifu[minnum[1][lujing[m]]]);
	for (i = m;i >=0;i--)
		printf("->%c", zifu[lujing[i]]);
	printf("\n");
	return 0;
} 
