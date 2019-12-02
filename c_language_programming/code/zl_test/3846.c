#include<stdio.h>
int main()
{
	int n, m, i, a, b;
	float c;
	scanf ("%d", &n);
	while (n != 0)
	{
		b = 0;
		scanf ("%d", &m);
		if (m == 0)
		continue;
		for (i = 1; i <= m;i++)
		{
			scanf ("%d", &a);
			b = b + a;
			c = 1.0 * b / m;
		}
		printf ("%.2f\n", c);
		n--;
	}
	return 0;
}