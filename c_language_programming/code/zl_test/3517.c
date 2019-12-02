#include<stdio.h>
#include<math.h>
int main()
{
	int y;
	float p, t;
	p = 13.076;
		while ((scanf ("%d", &y)) != EOF)
		{
		if (y <= 2005)
		;
		else 
		{
			t = y - 2005;
			t = pow(1.00589, t);
			p = p * 1.0 * t;
		}
	printf ("%.3f\n", p);
		}
	return 0;
}