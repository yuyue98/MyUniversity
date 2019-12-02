#include<stdio.h>
#include<math.h>
int main()
{
	float a, b, c, d;
	float x, x1, x2;
	scanf ("%f %f %f", &a, &b, &c);
	d = b * b - 4 * a * c;
	if (a != 0)
	{
		if (d < 0)
		printf ("No\n");
		else if (d > 0)
		{
			x1 = (- b + sqrt(d)) / (2 * a);
			x2 = (- b  - sqrt(d)) / (2 * a);
			if (x1 < x2)
			{
				x = x1, x1 = x2, x2 = x;
			}
			printf ("%f\n%f\n", x1 ,x2);
		}
		else
		{
			x1 = -b / (2 * a);
			x2 = -b / (2 * a);
			printf ("%f\n", x1);
		}
	}
	else
	{
		if (b != 0)
		{
			x1 = - c / b;
			x2 = - c / b;
			printf ("%f\n", x1);
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}