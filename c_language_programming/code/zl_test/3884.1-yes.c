#include<stdio.h>
int main()
{
	int a[20], i, n, c, m;
    while((scanf ("%d", &n)) != EOF)
	{
		c = 0;	
		for (i = 0; i < n; i++)
		{
			scanf ("%d", &a[i]);
		}
		scanf ("%d", &m);
		for (i = 0; i < n; i++)
		{
			if (m == a[i])
			{
				a[i] = a[i + 1];
				m = a[i + 1];
			}
			else
			c++;
		}
		if (c == n)
		{
			for (i = 0; i < n; i++)
		    {
	    		printf ("%d", a[i]);
	    		if (i == n - 1)
	    		printf ("\n");
	    		else
	    		printf (" ");
    		}
		}
		else
		{
			for (i = 0; i < n - 1; i++)
	    	{
	    		printf ("%d", a[i]);
	    		if (i == n - 2)
	    		printf ("\n");
	    		else
	    		printf (" ");
	    	}
		}
	}
	return 0;
}