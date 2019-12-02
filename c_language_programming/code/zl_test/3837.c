#include<stdio.h>
int main()
{
	int i, n;
	float a, s;
	while (scanf("%d", &n) != EOF)
	{
	    a = 1;
		s = 0;
	    for (i = 1; i <= n; i++)
	    {
            a = a * i;
	    	s = s + a;
      	}
	printf("%.0f\n", s);
	}
	return 0;
} 