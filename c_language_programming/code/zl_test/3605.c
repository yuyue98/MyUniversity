#include<stdio.h>
int main()
{
	int n, i, j, a;
	while ((scanf("%d", &n)) != EOF)
	{
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i ;j++)
		{
			a = i * j;
			if (i != j)
		    printf("%d*%d=%-2d ", j, i, a);
		    else
		    printf("%d*%d=%d\n", j, i, a);
		}
	}
	}
	return 0;
}