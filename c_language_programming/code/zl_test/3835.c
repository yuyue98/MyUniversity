#include<stdio.h>
int main()
{
	int c, n;
	while (scanf("%d", &n) != EOF)
	{
		c = 0;
		while (n != 1)
		{
			if (n % 2 == 0)
			n = n / 2;
			else
			n = 3 * n + 1;
			c++;
		}
	    printf("%d\n", c);
	}
	return 0;
} 