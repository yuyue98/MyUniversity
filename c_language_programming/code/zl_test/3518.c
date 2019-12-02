#include<stdio.h>
int main()
{
	int n, i, a, b;
	int s;
	s = 0;
	b = 0;
	scanf ("%d,%d", &a, &n);
    for (i = 1;i <= n;i++)
    {
    	b = b * 10 + a;
    	s = s + b;
    }
	printf("%d\n", s);
	return 0;
}