#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
int main(void)
{
	int x, a, n;
	x = 12;
	n = 1;
	do
	{
		printf ("input a number\n", a);
		scanf ("%d", &a);
		if (a > x)
		printf ("too big\n");
		else if (a < x)
		printf ("too small\n");
		else
    	printf ("you win\n");
    	printf ("you guess %d\n", n);
		n++;
	}while (a != x);

	return 0;
}