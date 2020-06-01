#include<stdio.h>
int main()
{
	int a=0;
	while (getchar() != '\n')
	a++;
	printf("输入位数为：%d", a);
	return 0;
}