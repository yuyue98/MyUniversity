#include <stdio.h>

int main(int argc, char *argv[])
{
	int a, b;
	int s;
	char c;
	printf("请输入所要计算的式子：");
	while(scanf("%d", &a) != EOF)
	{
		printf("此式结果为：");
		printf("%d", a);
		s = a;
		c = getchar();
		while(c != '=')
		{
			scanf("%d", &b);
			printf("%c%d", c, b);
			if(c == '+')
			s = s + b;
			else if(c == '-')
			s = s - b;
			else if(c == '*')
			s = s * b;
			else if(c == '/')
			s = s / b;
			else
			{
				printf("未设置此符号！\n");
				exit(1);
			}
			c = getchar();
		}
		printf("%c%d\n", c, s);
		printf("请输入所要计算的式子：");
	} 
	return 0;
}
