#include<stdio.h>
int main()
{
	int a[5], i, m, c, n;
	for (i = 0; i <= 4; i++)
	scanf("%d", &a[i]);
	for (n = 0; n < 4; n++)
	{
	m = a[n];
	for (i = n; i <= 4; i++)
	{
		if ( m >= a[i])
		{
			m = a[i];
			c = i;
		}
		else
		continue;
	}
	a[c] = a[n];
	a[n] = m;
	}
	for (i = 0; i <= 4; i++)
	{
		printf ("%d", a[i]);
		if (i != 4)
		printf (" ");
		else
		printf ("\n");
	}
	return 0;
}