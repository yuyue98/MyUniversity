#include <stdio.h>
#include <malloc.h>

int move(int *a, int n, int m); 

int main(int argc, char *argv[])
{
	int *shuzu;
	int n, m;
	int i;
	printf("请分别输入n，m：");
	while(scanf("%d%d", &n, &m) != EOF)
	{
		shuzu = (int*)malloc(n*sizeof(int));
		if(!shuzu)
		{
			printf("内存申请失败！\n");
			exit(1);
		} 
		printf("请分别输入n个整数：");
		for(i = 0;i < n;i++)
		scanf("%d", shuzu+i);
		move(shuzu,n,m);
		printf("移位后输出为：");
		for(i = 0;i < n-1;i++)
		printf("%d ", shuzu[i]);
		printf("%d\n", shuzu[i]);
		free(shuzu);
		printf("请分别输入n，m：");
	}
	return 0;
}

int move(int *a, int n, int m)
{
	int *t;
	int i;
	t = (int*)malloc(n*sizeof(int));
	if(!t)
	{
		printf("内存申请失败!\n");
		exit(1);
	}
	for(i = 0;i < n - m;i++)
	*(t+i) = *(a+i);
	for(i = 0;i < m;i++)
	*(a+i) = *(a+n-m+i);
	for(i = 0;i < n - m;i++)
	*(a+m+i) = *(t+i);
	free(t);
	return 0;
}
