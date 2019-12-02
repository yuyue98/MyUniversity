#include<stdio.h>
int main()
{
	int a[80], b, c, n, i;
	scanf ("%d", &n);
	if (n % 2 == 0)
	b = n / 2;
	else
	b = (n - 1) / 2;
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &a[i]);
	}
	for (i = 0; i < b; i++)
	{
		c = a[n - 1 - i];
		a[n - 1 - i] = a[i];
		a[i] = c;
	}
	for (i = 0; i < n; i++)
	{
		printf ("%d ", a[i]);
	}
	return 0;
}