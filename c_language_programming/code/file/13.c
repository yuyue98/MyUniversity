#include<stdio.h>
int main()
{
	int a[5], i, c = 0, x;
	for (i = 0; i <= 4; i++)
	scanf ("%d", &a[i]);
	printf ("input a number:\n");
	scanf ("%d", &x);
	for (i = 0; i <= 4; i++)
	{
		if (x == a[i])
		printf ("%d\n", i);
		else
		c++;
	}
	if (c != 0)
	printf ("not found\n");
	return 0;
}