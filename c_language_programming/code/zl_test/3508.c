#include<stdio.h>
int main()
{
	int a, b, m, n, i;
	scanf ("%d,%d", &a, &b);
	if (a < b)
	m = b;
	else
	m = a;
	i = 1;
	n = 1;
	while (i <= m)
	{
	    if (a % i == 0 && b % i == 0 && i > n)
	    n = i;
	    else
	    n = n;
	    i++;	
	}
	printf ("%d\n", n);
    return 0;	
}