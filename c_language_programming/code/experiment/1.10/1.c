#include <stdio.h>

int ack(int m,int n); 

int main(int argc, char *argv[])
{
	int m, n;
	int result = 0;
	printf("请分别输入两个自然数m，n：");
	while(scanf("%d%d", &m, &n) != EOF)
	{
		getchar();
		result = ack(m,n);
		printf("Ack(%d,%d) = %d\n", m, n, result);
		printf("请分别输入两个自然数m，n：");
	}
	return 0;
}

int ack(int m,int n)
{
	int result;
	if(m == 0)
	result = n+1;
	if(n == 0 && m > 0)
	result = ack(m-1,1);
	if(n > 0 && m > 0)
	result = ack(m-1,ack(m,n-1));
	return result;
}
