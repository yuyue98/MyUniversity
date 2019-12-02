#include<stdio.h>
int main()
{
	int b[10], s, i;
	float a;
	s = 0;
	for (i = 0; i <= 9; i++)
	{
		scanf ("%d", &b[i]);
		s = s + b[i];
	}
	a = s / 10.0;
	printf ("ave = %.2f\n", a);
	for (i = 0; i <= 9; i++)
	{
		if (b[i] > a)
		printf ("%d\n", b[i]);
		else
		continue;
	}
	return 0;
}