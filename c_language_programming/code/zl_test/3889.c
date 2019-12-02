#include<stdio.h>
int main()
{
	int a[100], i, j, n, c;
	float s;
	while (scanf("%d", &n) != EOF)
	{
		s = 0.0;
		for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
		{
			for (j = i; j < n; j++)
			if (a[i] < a[j])
			{c = a[i];
			a[i] = a[j];
			a[j] = c;
			}
		}
		for (i = 1; i < n - 1; i++)
		s = s + a[i];
		s = s / (n - 2);
		printf("%.2f\n", s);
	}
	return 0;
}