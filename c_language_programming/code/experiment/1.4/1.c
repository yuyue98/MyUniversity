#include <stdio.h>
int gongyue(int m, int n);
int gongbei(int m, int n); 
int main(int argc, char *argv[])
{
	int a, b;
	printf("请输入分别两个正整数：");
	while(scanf("%d%d", &a, &b) != EOF)
	{
		printf("这两数的最大公约数为：%d\n", gongyue(a,b));
		printf("这两数的最小公倍数为：%d\n", gongbei(a,b));
		printf("请输入分别两个正整数：");
	}
	
	return 0;
}
int gongyue(int m, int n)
{
	return n?gongyue(n,m%n):m;
}
int gongbei(int m, int n)
{
	return m*n/gongyue(m,n); 
}
