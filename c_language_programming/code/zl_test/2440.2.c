#include<stdio.h>
int main()
{
	int a[1000], min, b, n, s, i;
	while ((scanf ("%d", &n)) != EOF)
	{
	s = 0;
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &a[i]);
	}
	min = a[0];
	b = 0;
	for (i = 0; i < n; i++)
	{
		s = s + a[i];
		if(min > a[i])
		{
			min = a[i];
		    b = i;
		}
		else
		continue;
	}
	if (n > 1)
	s = s - a[b];
	else if (n == 1)
	s = s;
	printf ("%d\n", s);
	}
	return 0;
}