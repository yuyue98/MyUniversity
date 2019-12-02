#include<stdio.h>
int main()
{
	int j, i, a, b, c;
    for (i = 0;i <= 20;i++)
    {
    	a = 100 - 5 * i;
    	b = a / 3;
    	for (j = 0;j <= b;j++)
    	{
    		c = a - 3 * j;
    		if ((i + j + 3 * c) == 100)
    		printf ("%d %d %d\n", i, j, 3 * c);
    	}
    }
	return 0;
}