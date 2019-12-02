#include <stdio.h>

int main(int argc, char *argv[])
{
	int juzhen[10][11];
	int m, n;
	int i, j;
	printf("请分别输入矩阵的行数与列数m，n：");
	while(scanf("%d%d", &m, &n) != EOF)
	{
		printf("以下为输入的矩阵：\n");
		for(i = 0;i < m;i++)
		{
			juzhen[i][n] = 0;
			printf("请输入第%d行的数：", i+1);
			for(j = 0;j < n;j++)
			{
				scanf("%d", &juzhen[i][j]);
				juzhen[i][n] += juzhen[i][j]; 
			}	
		}
		for(j = 0;j <= n;j++)
		juzhen[0][j] ^= juzhen[m-1][j] ^= juzhen[0][j] ^= juzhen[m-1][j];
		printf("整理后矩阵如下：\n");
		for(i = 0;i < m;i++)
		{
			printf("第%d行的数为：", i+1);
			for(j = 0;j <= n;j++)
			{
				printf("%d", juzhen[i][j]);
				if(j == n)
				printf("\n");
				else
				printf(" ");
			}
		}
		printf("请分别输入矩阵的行数与列数m，n：");
	} 
	return 0;
}
