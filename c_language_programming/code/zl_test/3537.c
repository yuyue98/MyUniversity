#include<stdio.h>
int main()
{
	int a[100], max, b, c, n, i;
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &a[i]);
	}
	max = a[n - 1];
	for (i = n - 1; i >= 0; i--)
	{
		if(max <= a[i])
		{
	        max = a[i];
		    b = i;
		}
		else
		continue;
	}
	a[b] = a[n - 1];
	a[n - 1] = max;
	for (i = 0; i < n; i++)
	{
	printf ("%d ", a[i]);
	}
	return 0;
}