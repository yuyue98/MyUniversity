#include<stdio.h>
#include<math.h>
int main()
{
	int j, i, n, c, d;
	printf ("input a number:");
	scanf ("%d", &n);
	d = 0;
	for (i = 2; i <= n; i++)
	{
		c = 0;
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				c = 1;
				break;
			}
		}
		if (c == 0)
		{
			printf ("%8.d ", i);
			d++;
			if (d % 5 == 0)
		    printf ("\n");
		    if (d % 100 == 0)
		    printf ("%d\n", d);
		}
	}
	return 0;
}