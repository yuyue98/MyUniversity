#include<stdio.h>
int main()
{
	int a, b, c, i;
	    scanf ("%d", &b);
	    a = 0,i = 1;
	    while (i < b)
	    {
	    	if (b % i == 0)
	    	{a = a + i;}
	    	else
	    	{a = a;}
	    	i++;
	    }
	    if (a == b)
	    printf ("%d is cloze.\n", b);
	    else
	    printf ("%d is not cloze.\n", b);
	    return 0;	    	
}