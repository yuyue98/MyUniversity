#include<stdio.h>
int main()
{
	int a[1000], max, b, c, n, i, j, t, s;
	while ((scanf ("%d", &n)) != EOF)
	{
	s = 0;
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &a[i]);
	}
	for (j = 0; j < n - 1; j++)
	{
		for (i = j + 1; i < n; i++)
		{
			if (a[j] > a[i])
			{
				b = a[j], a[j] = a[i], a[i] = b;
			}
			else
			continue;
		}
	}
	if (n == 1)
	s = a[0];
	else
	{
		s = a[1];
		for (t = 2; t < n; t++)
    	{
	    	if (t % 2 == 0)
	    	s = s + a[0] + a[n - t + 1];
	    	else
	    	s = s + 2 * a[1];
    	}
	}
	printf ("%d\n", s);
	}
	return 0;
}