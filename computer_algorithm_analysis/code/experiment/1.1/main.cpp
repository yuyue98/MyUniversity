#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

int *paixu(int *array,int n);
void swap(int *a,int *b);
//直接二分查找
int zjerfind(int *array,int n,int m);
//递归二分查找
int dgerfind(int *array,int p,int q,int m);

int main()
{
	int i, j, k;
	int array[80];
	int n, m;
	printf("请输入数组长度：");
	scanf("%d", &n);
	getchar();
	printf("请分别输入数组元素(以空格隔开)：\n");
	for (i = 0;i < n;i++)
	{
		scanf("%d", &array[i]);
		getchar();
	}
	printf("排序前数组内容如下：\n");
	for (i = 0;i < n;i++)
	{
		printf("%d ", array[i]);
	}
	//数组排序（小到大）
	paixu(array,n);
	printf("\n排序后数组内容如下：\n");
	for (i = 0;i < n;i++)
	{
		printf("%d ", array[i]);
	} 
	while(1)
	{
		printf("\n请输入要查找的数：");
		scanf("%d", &m);
		getchar();
		printf("直接二分查找结果如下：\n");
		//直接二分查找
		k = zjerfind(array,n,m);
		if (n != 0)
		{
			if (k == 10000)
			printf("数组中不存在数%d！\n", m);
			else
			printf("数%d是数组中第%d个元素。\n", m, k+1);
			printf("递归二分查找结果如下：\n");	
		}
		//递归二分查找
		k = dgerfind(array,0,n,m);
		if (n != 0)
		{
			if (k == 10000)
			printf("数组中不存在数%d！\n", m);
			else
			printf("数%d是数组中第%d个元素。\n", m, k+1);
		}	
	}
	
	return 0;
} 

int *paixu(int *array,int n)
{
	int i, j, k;
	for (i = 0;i < n-1;i++)
	{
		k = i;
		for (j = i;j < n;j++)
		{
			if (array[k] > array[j])
			{
				k = j; 
			}
		}
		//交换两数
		swap(&array[i],&array[k]); 
	}	
}

void swap(int *a,int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t; 
}

//直接二分查找
int zjerfind(int *array,int n,int m)
{
	int i = 0;
	int p, q, k = 10000;
	if (n != 0)
	{
		p = 0;
		q = n;
		while(p != q-1)
		{
			
			{
				i++;
				k = (p+q)/2;
				printf("第%d次：k = %d\n", i, k);
				if (m < array[k])
					q = k;
				else
					p = k;	
			}
			if (m == array[p])
			return p;
		}
	}
	else
	printf("数组中没有数！\n");
	return 10000;
}

//递归二分查找
int dgerfind(int *array,int p,int q,int m)
{
	int k, t;
	k = (p+q)/2;
	if (q == 0)
	{
		printf("数组中没有数！\n");
		return 10000;
	}
	if (p == q-1)
	{
		if (m == array[p])
		return p;
		else
		return 10000;
	}
	else
	{
		if(m < array[k])
			return dgerfind(array,p,k,m);
		else 
			return dgerfind(array,k,q,m);	
	}	
}
