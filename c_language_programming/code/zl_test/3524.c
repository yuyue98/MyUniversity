#include<stdio.h>
#include<math.h>
int main()
{
	int n, i, j;
	float x, s, a;
	scanf ("%f", &x);
	s = 0, i = 1;
	do
	{
		a = pow(x, i);
		for (j = 1; j <= i; j++)
		{
			a = a / j;
		}
		s = s + a;
		i++;
	}while (a > 0.00001);
	printf ("%.3f\n", s);
	return 0;
}