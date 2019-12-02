#include<stdio.h>
int main()
{
	int n, s;
	scanf("%d", &n);
	s = 1;
	for (n = n; n > 1; n--)
	{
		s = 2 * (s + 1);
	}
    printf("%d\n", s);
	return 0;
}