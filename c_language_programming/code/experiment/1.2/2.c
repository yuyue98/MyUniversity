#include<stdio.h>
int main()
{
	float s = 0, flag = 1.0; 
	int n; 
	int i;
	printf("请输入正整数n：");
	scanf("%d", &n);
	if (n<=0)
	{
		printf("错误提示：n小于或等于0\n");
		return 0;
	}
	printf("前%d项和为：\n", n);
	for (i=1;i<=n;i++)
	{
		s = s + flag * i / (2 * i - 1);
		flag = - flag;
		if (i == 1)
		printf("1");
		else if (i % 2 == 0)
		printf("-%d/%d", i, 2 * i - 1);
		else if (i % 2 != 0)
		printf("+%d/%d", i, 2 * i - 1);
	} 
    printf("=%f\n", s);
    system("pause");
	return 0;
}
