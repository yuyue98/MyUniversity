#include<stdio.h>
int main()
{
	int i, a, n;
	scanf ("%d", &a);
	n = 1;
	 i = 1;
	while (i <= a)
	{
	    n = n * i;	
		i = i + 1;
	}
	printf ("%d!=%d\n", a, n);
    return 0;	
}