#include<stdio.h>
int main()
{
	int b, s, i;
	float a;
	s = 0;
	for (i = 1; i <= 10; i++)
	{
		scanf ("%d", &b);
		s = s + b;
	}
	a = s / 10.0;
	printf ("ave = %.2f\n", a);
	return 0;
}