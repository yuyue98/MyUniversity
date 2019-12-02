#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, day;
	printf("请输入要知道情况的天数：");
	while(scanf("%d", &day) != EOF)
	{
		if (day % 5 >= 1 && day % 5 <= 3)
		printf("此人在打渔！\n");
		else if (day != 0 && day % 5 == 0 || day % 5 == 4)
		printf("此人在晒网！\n"); 
		else 
		printf("此情况不存在！\n");
		printf("请输入要知道情况的天数：");
	}
	sysytem("pause");
	return 0;
}