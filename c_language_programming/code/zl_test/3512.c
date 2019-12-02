#include<stdio.h>
int main()
{
	int n, i, a, k;
	k = 0;
	n = 200;
    while (n <= 299)
    {
    	i = 2;
    	while (i < n )
    	{
    		if (n % i != 0)
    		{
    			i++;
    		}
    		else
    		break;
    	}
    	if (n == i)
    	{
    		printf ("%d", n);
    	    k++;
    	    if (k != 0 && k % 8 == 0 )
        {
        	printf ("\n");
        }
        else if (k != 0 && k % 8 != 0 )
        {
        	printf (" ");
        }
    	}
        n++;
    }
	return 0;
}