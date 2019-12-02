#include<stdio.h>
int main()
{
	int a[20], i, n, c, m;
    while((scanf ("%d", &n)) != EOF)
	{	
		c = n;
		for (i = 0; i < n; i++)
		{
			scanf ("%d", &a[i]);
		}
		scanf ("%d", &m);
		for (i = 0; i < n; i++)
		{
			if (m == a[i])
			{
				c = i;
				break;
			}
			else
			continue;
		}
			for (i = 0; i < c; i++)
		    {
	    		printf ("%d", a[i]);
	    		if (i == n - 1)
	    		printf ("\n");
	    		else
	    		printf (" ");
    		}
			for (i = c + 1; i < n; i++)
	    	{
	    		printf ("%d ", a[i]);
	    		if (i == n - 1)
	    		printf ("\n");
	    		else
	    		printf (" ");
	    	}
	}
	return 0;
}