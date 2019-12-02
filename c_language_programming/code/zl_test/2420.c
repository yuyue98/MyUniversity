#include<stdio.h>
int main()
{
	int a, b, c, d, e;
	scanf ("%d",&a);
	b = a % 10000;
	a = (a - b) / 10000;
	c = b % 1000;
	b = (b - c) / 1000;
	d = c % 100;
	c = (c - d) / 100;
	e = d % 10;
	d = (d - e) / 10;
	if (a == e && b == d)
	{
	    printf ("Yes\n");	
	}else
	{
	    printf ("No\n");	
	}
    return 0;	
}