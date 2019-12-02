#include<stdio.h>
int main()
{
	int a, b, c, i, n;
	scanf ("%d,%d", a, b);
	if (a < b)
	{
	a = a;
	b = b;
	}
	else
	{
	c = a;
	a = b;
	b = c;
	}
	while (b % a != 0)
	{
		c = b % a;
		b = a;
		a = c;
	}
	printf ("%d\n", c);
    return 0;	
}