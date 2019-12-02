#include<stdio.h>
int main()
{
	int i, a, n;
	scanf ("%d", &a);
	n = 0;
	 i = 1;
	while (i <= a)
	{
	    n = n + i;	
		i = i + 1;
	}
	printf ("sum=%d\n", n);
    return 0;	
}