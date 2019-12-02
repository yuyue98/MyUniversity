#include<stdio.h>
int main()
{
	int n, i, a;
	while ((scanf("%d", &n)) != EOF)
	{a = 2;
	for (i = 2; i < n; i++)
	{
		if (n % i != 0)
		a++;
		else
		break;
	}
	if (a == n)
	printf ("Yes\n");
	else
	printf ("No\n");
	}
	return 0;
}