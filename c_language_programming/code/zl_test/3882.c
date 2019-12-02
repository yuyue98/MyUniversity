#include<stdio.h>
int main()
{
	int a[10], max, b, n, i;
	while ((scanf ("%d", &n)) != EOF)
	{
	b = 0;
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &a[i]);
	}
	max = a[0];
	b = 0;
	for (i = 0; i < n; i++)
	{
		if(max < a[i])
		{
			max = a[i];
		    b = i;
		}
		else
		continue;
	}
	printf ("%d %d\n", max, b);
	}
	return 0;
}