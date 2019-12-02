#include<stdio.h>
int main()
{
	int i, n, a, s;
	a = s = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		a = a + i;
		s = s + a;
	}
	printf("%d\n", s);
	return 0;
} 