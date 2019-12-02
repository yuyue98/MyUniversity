#include<stdio.h>
int main()
{
    int c, r, n, m;
	scanf ("%d%d", &n, &m);
	if ((m - 2 * n) % 2 == 0 && m - 2 * n > 0)
	{
	    r = (m - 2 * n) / 2;
	    c = n - r;   
	    printf ("%d %d\n", c, r);	
	}
	else
	{
	    printf ("No\n");    		
	}
    return 0;
}