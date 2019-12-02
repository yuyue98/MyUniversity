#include<stdio.h>
int main()
{
	int a[100], n, i, j, t, c;
	while ((scanf ("%d", &n) != EOF))
	{
		for (i = 0; i < n; i++)
		scanf ("%d", &a[i]);
		for (i = 0; i < n; i++)
		{
			t = i;
			for (j = i; j < n ;j++)
			{
				if (a[t] < a[j])
				t = j;
			}
			c = a[i];
			a[i] = a[t];
			a[t] = c;
		}
		for (i = 0; i < n; i++)
		printf ("%d ", a[i]);
	}
	return 0;
}