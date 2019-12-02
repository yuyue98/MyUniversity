#include<stdio.h>
int main()
{
	int a[5], i, m, c;
	for (i = 0; i <= 4; i++)
	scanf("%d", &a[i]);
	m = a[1];
	for (i = 0; i <= 4; i++)
	{
		if ( m >= a[i])
		{
			m = a[i];
			c = i;
		}
		else
		continue;
	}
	a[c] = a[0];
	a[0] = m;
	for (i = 0; i <= 4; i++)
	printf ("%d ", a[i]);
	printf ("min = %d, i = %d\n", m, c);
	return 0;
}