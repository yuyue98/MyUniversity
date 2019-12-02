#include<stdio.h> 
int sushu(int n);
int main()
{
	int a, b, c, i, s;
	a = 1, b = 1;
	while (scanf ("%d%d", &a, &b) != EOF)
	{
	    c = 1; 
		if (a == 0 && b == 0)
		break;
		for (i = a; i <= b; i++)
		{
			s = i * i + i + 41;
			if (sushu(s) == 1)
			{
			    printf("Sorry\n");
			    c = 0;
				break;
			}
		}
		if (c == 1)
		printf("OK\n");
	}
	return 0;
}
int sushu (int n)
{
	int i, c;
	c = 0;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			c = 1;
			break;
		}
	}
	return c;
}