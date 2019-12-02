#include<stdio.h>
int main()
{
	int h1, h2, m1, m2, x;
	scanf ("%d:%d\n%d:%d", &h1, &m1, &h2, &m2);
	x = (h2 - h1) * 60 + m2 - m1;
	printf ("%d\n", x);
	return 0;
}