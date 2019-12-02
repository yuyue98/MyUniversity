#include<stdio.h>
int main()
{
	int a, b, s, n;
	b=0;
	scanf ("%d", &a);
	for (n=1;n<=a;n++)
	{
		b = b*10+2;
		s = s+b;
	}
	printf ("%d\n", s);
	return 0;
}