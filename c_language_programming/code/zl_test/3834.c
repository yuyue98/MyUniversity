#include<stdio.h>
int main()
{
	int i, n, c;
	float a, b, s;
	
	while (scanf("%d", &n) != EOF)
	{
		c = 1.0;
	    a = s = b = 0;
	    for (i = 1; i <= n; i++)
	    {
            a = a + c * (2 * i - 1);
		    b = 1.0 / a;
	    	s = s + b;
	    	c = -c;
      	}
	printf("%.2f\n", s);
	}
	return 0;
} 