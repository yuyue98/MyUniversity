#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#define MAX 50

int main()
{
	int i, j, k;
	int n, m;
	//int dx[8] = {1,1,2,2,-1,-1,-2,-2};
	//int dy[8] = {-2,-1}
	while (1)
	{
		printf("请分别输入棋盘边长n,m：");
		scanf("%d", &n);
		getchar();
		scanf("%d", &m);
		getchar();
		int **r;
		r = (int**)malloc(n*sizeof(int*));
		for (i = 0;i < n;i++)
		r[i] = (int*)malloc(m*sizeof(int));
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < m;j++)
			{
				r[i][j] = 0;
			}
		}
		int num = n * m;
		int p[MAX], q[MAX];
		for (i = 0;i <MAX;i++)
		p[i] = q[i] = 0;
		int t = 1, v = 0;
		while (t != v)
		{
			t--;
			i = p[t];
			j = q[t];
			if (i+2<n&&j+1<m)
			{
				if(r[i+2][j+1]==0)
				{
					p[t] = i+2;
					q[t] = j+1;
					r[i+2][j+1]=1;
					t++;	
				}
			}
			if (i+2<n&&j-1>-1)
			{
				if(r[i+2][j-1]==0)
				{
					p[t] = i+2;
					q[t] = j-1;
					r[i+2][j-1]=1;
					t++;	
				}
			}
			if (i-2>-1&&j+1<m)
			{
				if(r[i-2][j+1]==0)
				{
					p[t] = i-2;
					q[t] = j+1;
					r[i-2][j+1]=1;
					t++;	
				}
			}
			if (i-2>-1&&j-1>-1)
			{
				if(r[i-2][j-1]==0)
				{
					p[t] = i-2;
					q[t] = j-1;
					r[i-2][j-1]=1;
					t++;	
				}
			}
			if (i+1<n&&j+2<m)
			{
				if(r[i+1][j+2]==0)
				{
					p[t] = i+1;
					q[t] = j+2;
					r[i+1][j+2]=1;
					t++;	
				}
			}
			if (i+1<n&&j-2>-1)
			{
				if(r[i+1][j-2]==0)
				{
					p[t] = i+1;
					q[t] = j-2;
					r[i+1][j-2]=1;
					t++;	
				}
			}
			if (i-1>-1&&j+2<m)
			{
				if(r[i-1][j+2]==0)
				{
					p[t] = i-1;
					q[t] = j+2;
					r[i-1][j+2]=1;
					t++;	
				}
			}
			if (i-1>-1&&j-2>-1)
			{
				if(r[i-1][j-2]==0)
				{
					p[t] = i-1;
					q[t] = j-2;
					r[i-1][j-2]=1;
					t++;	
				}
			}
		}
		printf("遍历后，邻接矩阵r如下：\n");
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < m;j++)
			{
				printf("%2d ",r[i][j]);
			}
			printf("\n");
		}
		int flag = 1;
		for (i = 0;i < n&&flag;i++)
		{
			for (j = 0;j < m&&flag;j++)
			{
				if(r[i][j]!=1)
				{
					flag = 0;
				}
			}
		}
		if (flag)
		{
			printf("马可以走遍棋盘所有格子!\n");
		}
		else
		{
			printf("马不可以走遍棋盘所有格子!\n");
		}
		for (i = 0;i < n;i++)
		free(r[i]);
		free(r);	
	} 
	system("pause");
	return 0;
} 
