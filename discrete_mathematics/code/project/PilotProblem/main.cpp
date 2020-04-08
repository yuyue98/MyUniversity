#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <malloc.h>

void swap(int *a, int *b);
int sxppnum(int **array, int n, int m); 
int xylppnum(int **array, int n, int m);

int main ()
{
	int i, j, k;
	int n, m;
	int **array;
	while(1) 
	{
		printf("请分别输入n, m(n需大于m):");
		scanf("%d", &n);
		getchar();
		scanf("%d", &m);
		getchar();
		//交换两数
		if (n > m)
		swap(&m,&n);
		//地址申请 
		array = (int**)malloc((n+1)*sizeof(int*));
		for (i = 0;i <= n;i++)
		{
			array[i] = (int*)malloc((m+1)*sizeof(int));
		}
		for (i = 0;i <= n;i++)
		{
			for (j = 0;j <= m;j++)
			{
				array[i][j] = 0;
			}
		} 
		int x, y;
		printf("请依次输入匹配关系（以-1结束）：\n");
		while(1)
		{
			scanf("%d", &x);
			getchar();
			if (x == -1)
			break;
			scanf("%d", &y);
			getchar();
			array[x-1][y-1] = 1;
			array[x-1][m]++;
			array[n][y-1]++;
		}
		printf("(匹配前)飞行员之间匹配关系如下：\n");
		for (i = 0;i <= n;i++)
		{
			for (j = 0;j <= m;j++)
			{
				printf("%d ", array[i][j]);
			}
			printf("\n");
		}
		int plane_num =  sxppnum(array,n,m);
		printf("最多起飞飞机数：plane_num = %d\n", plane_num);
		printf("(匹配后)飞行员之间匹配关系如下：\n");
		for (i = 0;i <= n;i++)
		{
			for (j = 0;j <= m;j++)
			{
				printf("%d ", array[i][j]);
			}
			printf("\n");
		}
		plane_num = xylppnum(array,n,m);
		printf("最多起飞飞机数：plane_num = %d\n", plane_num);
		printf("(匹配后)飞行员之间匹配关系如下：\n");
		for (i = 0;i <= n;i++)
		{
			for (j = 0;j <= m;j++)
			{
				printf("%d ", array[i][j]);
			}
			printf("\n");
		}
		for (i = 0;i < n;i++)
		{
			free(array[i]);
		}
		free(array);
	}
	system("pause");
	return 0;
} 

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int sxppnum(int **array, int n, int m)
{
	int i, j, k;
	int plane_num = 0;
	int p, q;
	printf("自定义算法求解：\n");
	for (i = 0;i < n;i++)
	{
		p = 0;
		for (j = 0;j < n;j++)
		{
			if (array[j][m] == 0)
			{
				continue;
			}
			if (array[p][m] == 0 || array[p][m] > array[j][m])
			{
				p = j;
			}
		}
		q = 0;
		for (j = 0;j < m;j++)
		{
			if (array[p][j] == 0)
			{
				continue;
			}
			else
			{
				if (array[p][q] == 0 || array[n][q] < array[n][j])
				q = j;
			}
		}
		if (p == 0 && q == 0 && array[p][q] == 0)
			continue;
		printf("第%d次:p = %d ", i, p);
		printf("q = %d\n", q);
		for (j = 0;j <= n;j++)
		{
			for (k = 0;k <= m;k++)
			{
				printf("%d ", array[j][k]);
			}
			printf("\n");
		}
		plane_num++;
		for (j = 0;j < n;j++)
		{
			array[j][m] -= array[j][q];
		}
		for (j = 0;j < m;j++)
		{
			array[n][j] -= array[p][j];
		}
		for (j = 0;j <= n;j++)
		{
			array[j][q] = 0;
		}
		for (j = 0;j <= m;j++)
		{
			array[p][j] = 0;
		}
	}
	return plane_num;
}

int xylppnum(int **array, int n, int m)
{
	int plane_num = 0;
	int i, j, k;
	int *p, *q;
	p = (int*)malloc(n*sizeof(int));
	q = (int*)malloc(m*sizeof(int));
	for (i = 0;i < n;i++)
	array[i][m] = 0;
	for (i = 0;i < m;i++)
	array[n][i] = 0;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			if (array[i][j] == 0)
			continue;
			else
			{
				if (array[n][j] == 0)
				{
					array[i][m] = array[n][j] = 1;
					q[j] = i;
				}
				else
				{
					
				}
			}
			
		}
	}
	return plane_num;
}
