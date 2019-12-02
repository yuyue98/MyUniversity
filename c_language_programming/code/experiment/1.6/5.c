#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	printf("请输入要输出的杨辉三角层数n：");
	while(scanf("%d", &n) != EOF)
	{
		int i, j;
		int a[30][30];
		a[0][0] = 1;
		for(i = 1;i < n;i++)
		{
			a[i][0] = 1;
			for(j = 1;j < i;j++)
			{
				a[i][j] = a[i-1][j-1] + a[i-1][j];
			}
			a[i][j] = 1;
		}
		for(i = 0;i < n;i++)
		{
			for(j = 0;j <= i;j++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("请输入要输出的杨辉三角层数n：");
	} 
	return 0;
}
