#include <stdio.h>

int fib(int n); 

int main(int argc, char *argv[])
{
	int n;
	printf("请输入正整数n：");
	while(scanf("%d", &n) != EOF)
	{
		printf("fib(%d) = %d\n", n, fib(n));
		printf("请输入正整数n：");
	} 
	return 0;
}

int fib(int n)
{
	int result;
	if(n == 1 || n == 2)
	result = 1;
	else
	result = fib(n - 1) + fib(n - 2);
	return result;
	 
}
