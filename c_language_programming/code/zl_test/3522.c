#include<stdio.h>
int main()
{
	int n, a, s, i, c, j;
	scanf ("%d", &n);
	s = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		c = 0;
		for (j = 2; j < a; j++)
		{
			if (a % j == 0)
			c++;
		}
		if (c != 0 || a == 1)
		;
		else 
		{
			printf ("%d ", a);
			s = s + a;
		}
	}
	printf ("s=%d\n", s);
	return 0;
}