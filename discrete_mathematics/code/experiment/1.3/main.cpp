#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define false 0
#define true 1
#define MAX 6
#define BLANK 9999
#define bag_w 10
#define goods_n 4 

void txqmintree();
void hsqbagprogram();

int main()
{
	txqmintree();
	hsqbagprogram();
	return 0;
} 

void txqmintree()
{
	printf("*******************贪心算法求解最小生成树********************\n"); 
	int i, j, k;
	int array[MAX][MAX] = {{BLANK,6,1,5,BLANK,BLANK},
						   {6,BLANK,5,BLANK,3,BLANK},
						   {1,5,BLANK,5,6,2},
						   {5,BLANK,5,BLANK,BLANK,4},
						   {BLANK,3,6,BLANK,BLANK,6},
						   {BLANK,BLANK,2,4,6,BLANK}};
	printf("连通图邻接矩阵形式如下：\n");
 	for (i = 0;i< MAX;i++)
 	{
 		for (j = 0;j < MAX;j++)
 		{
 			if (array[i][j] == BLANK)
 			printf("a[%d][%d] = 0 ", i, j);
 			else
		 	printf("a[%d][%d] = %d ", i, j, array[i][j]);
	 	}
	 	printf("\n");
 	}
 	int mincost[MAX] = {BLANK,BLANK,BLANK,BLANK,BLANK,BLANK};
	int vis[MAX] = {1,0,0,0,0,0};
	int start[MAX-1] = {0,0,0,0,0};
	int end[MAX-1] = {0,0,0,0,0};
 	int t,flag = 0;
 	for (i = 0;i < MAX-1;i++)
 	{
	 	for (j = 0;j < MAX;j++)
	 	{
	 		if (mincost[j] > array[flag][j])
	 		{
				mincost[j] = array[flag][j];
		 	}
	 	}
	 	for (j = 0;j < MAX;j++)
	 	printf("%d:%d\t", j+1, mincost[j]);
	 	printf("\n");
	 	for (j = 0;j < MAX;j++)
	 	printf("%d:%d\t", j+1, vis[j]);
	 	printf("\n");
	 	for (j = 0;j < MAX;j++)
	 	if (vis[j] == 0)
	 	t = j;
	 	for (j = 1;j < MAX;j++)
	 	{
	 		if (vis[j] == 0 && mincost[t] > mincost[j])
	 		{
		 		t = j;
		 	}
	 	}
	 	printf("t = %d\n", t+1);
	 	vis[t] = 1;
	 	end[i] = t+1;
	 	for (j = 0;j < MAX;j++)
	 	{
	 		if (array[j][t] == mincost[t])
	 		{
		 		start[i] = j+1;
		 	}
	 	}
	 	flag = t;
	}
	printf("该连通图的最小生成树如下：\n");
	for (i = 0;i < MAX-1;i++)
	printf("第%d条边:顶点%d-->顶点%d||权值 = %d\n", i+1, start[i], end[i], mincost[end[i]-1]);
}

void hsqbagprogram()
{
	printf("*******************回溯法求解0-1背包问题********************\n");
	int i, j, k;
	int w[goods_n] = {1,2,3,5};
	int v[goods_n] = {5,7,9,7};
	int bestx[goods_n] = {0,0,0,0};
	int endx[50][goods_n+1];
	int bag = bag_w;
	int cp = 0, bestp = 0;
	int max = 0;
	printf("start: bag = %d, cp = %d\n", bag, cp);
	printf("w[%d] = {", goods_n);
	for (i = 0;i < goods_n;i++)
	printf("%d,", w[i]);
	printf("\b}\n");
	printf("v[%d] = {", goods_n);
	for (i = 0;i < goods_n;i++)
	printf("%d,", v[i]);
	printf("\b}\n");
	i = 0;
	k = 0;
	int m = 0;
	while(i < goods_n)
	{
		if (cp > bestp)
		{
			bestp = cp;
		}
		if (bag - w[i] >= 0)
		{
			bestx[i] = 1;
			bag -= w[i];
			cp += v[i];
			k++;
			for (j = 0;j < goods_n;j++)
			printf("1%d:bestx[%d] = %d ", k, j+1, bestx[j]);
			//printf("cp = %d p = %d", cp, bestp);
			printf("\n");
			endx[m][0] = cp;
			for (j = 1;j <= goods_n;j++)
			endx[m][j] = bestx[j-1];
			m++;
		}
		else
		{
			while (max < bestp)
			{
				i--;
				bag += w[i];
				cp -= v[i];
				bestx[i] = 0;
				max = 0;
				for (j = i+1;j < goods_n;j++)
				max += v[j];
				k++;
				for (j = 0;j < goods_n;j++)
				printf("2%d:bestx[%d] = %d ", k, j+1, bestx[j]);
				//printf("cp = %d p = %d", cp,bestp);
				printf("\n");
				endx[m][0] = cp;
				for (j = 1;j <= goods_n;j++)
				endx[m][j] = bestx[j-1];
				m++;
			}
		}
		i++;
	}
	if (cp > bestp)
		bestp = cp;
	printf("最终结果如下：\n");
	for (j = 0;j < m;j++)
	{
		if (endx[j][0] == bestp)
		{
			bag = 10;
			for (i = 1;i <= goods_n;i++)
			{
				if (endx[j][i] == 1)
				bag -= w[i-1];
			}
			for (i = 1;i <= goods_n;i++)
			printf("bestx[%d] = %d ", i, endx[j][i]);
			printf("\n");	
		}	
	}
	/*for (i = 0;i < goods_n;i++)
	printf("bestx[%d] = %d ", i+1, bestx[i]);
	printf("\n");*/
	printf("end: bag = %d, cp = %d\n", bag, bestp);
} 
