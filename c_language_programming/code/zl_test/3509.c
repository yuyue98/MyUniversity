#include<stdio.h>
int main()
{
	int n, i, a, b, c;
	float s;
	a = 1;
	b = 1;
	s = 0;
	scanf ("%d", &n);
    for (i = 1;i <= n;i++)
    {
    	c = a + b;
    	s = s + c *1.0/ b;
    	a = b;
    	b = c;
    }
	printf("s=%.2f\n", s);
	return 0;
}