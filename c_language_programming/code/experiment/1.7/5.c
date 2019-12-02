#include <stdio.h>

int main(int argc, char *argv[])
{
	int juzhen[6][6];
	int n;
	int i, j, t;
	int p, q, s;
	printf("请输入一个正整数n：");
	while(scanf("%d", &n) != EOF)
	{
		printf("要输入的矩阵如下：\n");
		for(i = 0;i < n;i++)
		{
			printf("请输入第%d行的数：", i+1);
			for(j = 0;j < n;j++)
			{
				scanf("%d", &juzhen[i][j]);
			}
		}
		s = 0;
		for(i = 0;i < n;i++)
		{
			p = i;
			q = 0;
			for(j = 0;j < n;j++)
			{
				if(juzhen[i][j] > juzhen[p][q])
				q = j;
			}
			for(t = 0;t < n;t++)
			{
				if(juzhen[t][q] < juzhen[p][q])
				p = t;
			}
			if(i == p)
			{
				printf("矩阵鞍点下标为：%d %d\n", p, q);
				s = 1;
			}
			
		}
		if(s == 0)
		printf("该矩阵的鞍点不存在！\n");
		printf("请输入一个正整数n：");
	} 
	return 0;
}
