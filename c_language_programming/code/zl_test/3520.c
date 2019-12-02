#include<stdio.h>
int main ()
{
	int i, n;
	int a[100];
	int max, min;
	scanf ("%d", &n);
	i = 1;
	while (i <= n)
	{
		scanf ("%d", &a[i]);
		i++;
	}
	max = a[1],min = a[n];
	i = 1;
	while (i <= n)
	{
		if (max <= a[i])
		{max = i;}
		else
		{max = max;}
		if (min >= a[i])
		{min = i;}
		else
		{min = min;}
		i++;
	}
    printf("max=%d, min=%d",a[1],a[n]);
    return 0;	
}