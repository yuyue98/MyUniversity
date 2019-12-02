#include<stdio.h>
int main()
{
	int a, b, i = 1;
	printf ("input a number:\n");
	scanf ("%d", &a);
	while (i < 10)
	{   
	    printf ("input a number:\n");
	    scanf ("%d", &b);
	    if (a < b)
	    a = b;
	    else
	    a = a;
	    i++;	
	}
	printf ("%d\n", a);
	return 0;
}