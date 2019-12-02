#include<stdio.h>
int main()
{
	int a[100], max, b, c, n, i, j;
	scanf ("%d", &n);
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
	for (i = 0; i < n; i++)
	{
	printf ("%d ", a[i]);
	}
	return 0;
}