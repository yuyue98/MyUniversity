#include <stdio.h>

int main(int argc, char *argv[])
{
	int a, b;
	char c;
	float money;
	printf("请分别输入加油量、汽油品种(90,93,97)、服务类型(m为自助服务，e为协助服务）：\n");
	while(scanf("%d%d", &a, &b) != EOF)
	{
		getchar();
		scanf("%c", &c);
		printf("%d %d %c\n", a, b, c);
		if (c == 'm')
		{
			printf("现在为自助服务！\n");
			if (b == 90)
			printf("应付款为：%.2f元\n", a * 6.950 * 0.95);
			else if (b == 93)
			printf("应付款为：%.2f元\n", a * 7.440 * 0.95);
			else if (b == 97)
			printf("应付款为：%.2f元\n", a * 7.930 * 0.95);
			else
			printf("不存在该种汽油！\n");
		}
		else if (c == 'e')
		{
			printf("现在为协助服务！\n");
			if (b == 90)
			printf("应付款为：%.2f元\n", a * 6.950 * 0.97);
			else if (b == 93)
			printf("应付款为：%.2f元\n", a * 7.440 * 0.97);
			else if (b == 97)
			printf("应付款为：%.2f元\n", a * 7.930 * 0.97);
			else
			printf("不存在该种汽油！\n");
		}
		else
		printf("不存在该种服务类型！\n");
		printf("请分别输入加油量、汽油品种(90,93,97)、服务类型(m为自助服务，e为协助服务）：\n");
	}
	sysytem("pause");
	return 0;
}
