#include<stdio.h>
int main()
{
	int n, i, a, b, c;
	int s;
	s = 1;
	a = 0;
	b = 1;
	scanf ("%d", &n);
    for (i = 1;i <= n;i++)
    {
    	printf ("%d ", s);
    	s = a + b;
    	a = b;
    	b = s;
    }
	return 0;
}