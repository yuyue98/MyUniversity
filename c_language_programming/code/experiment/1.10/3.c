#include <stdio.h>

float f(float a,int n); 

int main(int argc, char *argv[])
{
	float a;
	int n;
	printf("请分别输入数a与自然数n：");
	while(scanf("%f%d", &a, &n) != EOF)
	{
		getchar();
		printf("f(%.2f,%d) = %.2f\n", a, n, f(a,n));
		printf("请分别输入数a与自然数n：");
	}
	return 0;
}

float f(float a,int n)
{
	float result;
	if(n == 0)
	result = 0;
	else 
	result = a * (1 - f(a, n-1));
	return result;
}
