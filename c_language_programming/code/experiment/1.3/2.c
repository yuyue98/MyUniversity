#include <stdio.h>

int main(int argc, char *argv[])
{
	int chesu, xiansu;
	printf("请输入限速：");
	scanf("%d", &xiansu);
	printf("请输入车速：");
	while(scanf("%d", &chesu) != EOF)
	{
		if (1.0 * xiansu / (chesu - xiansu) <= 0 || chesu == xiansu)
		printf("该车未超速!\n"); 
		else if (1.0 * xiansu / (chesu - xiansu) < 2)
		printf("该车严重超速，吊销驾驶者驾照！\n");
		else if (1.0 * xiansu / (chesu - xiansu) < 5)
		printf("该车超速，处罚款200元！\n"); 
		else if (1.0 * xiansu / (chesu - xiansu) >= 5)
		printf("该车轻微超速，不处罚款！\n");
	}
	sysytem("pause");
	return 0;
}
