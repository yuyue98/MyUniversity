#include<stdio.h>
int main()
{
	int a, i, n;
	a = 0;
	do
	{
		scanf ("%d", &n);
		if (n < 0)
		break;
		if (n % 2 == 0)
		{
			a = a + n;
		}
		else 
		{
			a = a;
		}
	}while (n > 0);
	printf ("%d", a);
	return 0;
}