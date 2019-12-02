#include<stdio.h>
int main()
{
	int a, i, c, n;
	scanf ("%d", &n);
	a = 0, i = 1, c = 1;
	while (i <= n)
	{
	    a = a + c * i;
	    c = -c;
	    i++;	
	}
	printf ("%d\n", a);
    return 0;	
}