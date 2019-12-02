#include<stdio.h>
int main()
{
	int a[5], i, m, c;
	for (i = 0; i <= 4; i++)
	scanf("%d", &a[i]);
	m = a[0];
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
	printf ("min = %d, i = %d\n", m, c);
	return 0;
}