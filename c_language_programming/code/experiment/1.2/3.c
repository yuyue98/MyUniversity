#include<stdio.h>
#include<math.h>
int main()
{
	int s = 0; 
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
		s = s + (int)pow(2,i);
		if (i == 1)
		printf("2^1");
		else 
		printf("+2^%d", i);
	} 
    printf("=%d\n", s);
    system("pause");
	return 0;
}
