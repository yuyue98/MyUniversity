#include<stdio.h>
#include<math.h>
int main()
{
	int a, b, c, d, e, f, g, h;
	scanf ("%d",&a);
	f = 10;
	g = 1;
	while (a / f >= 1)
	{
	    f = f * 10;
	    g++;	
	}
	b = a % 10000;
	a = (a - b) / 10000;
	c = b % 1000;
	b = (b - c) / 1000;
	d = c % 100;
	c = (c - d) / 100;
	e = d % 10;
	d = (d - e) / 10;
	h = pow(10,g-1) * e + pow(10,g-2) * d +      pow(10,g-3) * c + pow(10,g-4) * b +             pow(10,g-5) * a;
	if (g == 5)
	printf ("%d\n%05d\n", g, h);
	else if (g == 4)
	printf ("%d\n%04d\n", g, h);
	else if (g == 3)
	printf ("%d\n%03d\n", g, h);
	else if (g == 2)
	printf ("%d\n%02d\n", g, h);
	else if (g == 1)
	printf ("%d\n%01d\n", g, h);	
    return 0;	
}