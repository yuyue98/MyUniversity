#include<stdio.h>
#include<math.h>
int main()
{
	int a, j, i, n;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			a = j * 1000 + j * 100 + i * 10 + i;
			n = sqrt(a);
		if (a == n * n)
		printf("%d\n", a);
		}
	}
	return 0;
}