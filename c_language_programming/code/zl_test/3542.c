#include<stdio.h>
int main()
{
	int a[11] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int m, b, c = 0, i;
	scanf ("%d", &m);
	    for (i = 0; i < 10; i++)
		{
			if (m < a[i])
			{
				b = m, m = a[i], a[i] = b;
			}
			else if (m == a[i])
			{
				c = 1;
				break;
			}
			else
			continue;
		}
	if (c == 0)	
	{
		for (i = 0; i < 10; i++)
	    {
	    	printf ("%d", a[i]);
	    	if (i == 9)
	    	printf ("\n");
	    	else
	    	printf (" ");
    	}
	}
	else
	{
		for (i = 0; i < 9; i++)
	    {
	    	printf ("%d", a[i]);
	    	if (i == 8)
	 	   printf ("\n");
	    	else
	    	printf (" ");
    	}
	}
	return 0;
}