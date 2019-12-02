#include<stdio.h>
int main()
{
	int a[100], x, b, c =0, n, i;
	scanf ("%d%d", &x, &n);
	for (i = 0; i < n; i++)
	{
		scanf ("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		if(x == a[i])
		{
			b = i;
		    c++;
		    break;
		}
		else
		continue;
	}
	if (c == 0)
	printf ("Not Found\n");
	else
	printf ("%d", b);
	return 0;
}