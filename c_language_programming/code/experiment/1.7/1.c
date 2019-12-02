#include <stdio.h>

int main(int argc, char *argv[])
{
	int number[20];
	int n, T;
	int i;
	printf("请输入测试组数T：");
	scanf("%d", &T);
	getchar();
	while(T--)
	{
		printf("请输入要输入的整数个数n：");
		scanf("%d", &n);
		printf("请分别输入%d个整数：", n);
		for(i = 0;i < n;i++)
		scanf("%d", &number[i]);
		printf("这%d个整数逆序输出为：", n);
		for(i = n-1;i > 0;i--)
		printf("%d ", number[i]);
		printf("%d\n", number[0]);
	} 
	return 0;
}
