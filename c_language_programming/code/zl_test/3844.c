#include<stdio.h>
int main()
{
	int n, m, i, a, b;
	scanf ("%d", &n);
	while (n != 0)
	{
		scanf ("%d", &m);
		if (m == 0)
		continue;
		scanf ("%d", &a);
		for (i = 1; i < m;i++)
		{
			scanf ("%d", &b);
			if(a < b)
			a = b;
		}
		printf ("%d\n", a);
		n--;
	}
	return 0;
}