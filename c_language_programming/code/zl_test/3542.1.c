#include<stdio.h>
int main()
{
	int a[12] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 9010000000};
	int m, b, c = 0, i;
	scanf ("%d", &m);
	    for (i = 0; i < 10; i++)
		{
			if (m < a[i])
			{
				b = m, m = a[i], a[i] = b;
			}
			else
			continue;
		}
		for (i = 0; i < 10; i++)
	    {
	    	printf ("%d", a[i]);
	    	if (i == 10)
	    	printf ("\n");
	    	else
	    	printf (" ");
    	}
	return 0;
}