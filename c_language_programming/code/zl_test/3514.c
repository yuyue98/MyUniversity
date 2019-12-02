#include<stdio.h>
int main()
{
	int n, i, a, b, c;
	float s;
	a = 1;
	b = 1;
	c = 1;
	s = 0;
	scanf ("%d", &n);
    for (i = 1;i <= n;i++)
    {
    	s = s + c * a *1.0/ b;
    	a++;
    	b = b + 2;
    	c = -c;
    }
	printf("%.2f\n", s);
	return 0;
}