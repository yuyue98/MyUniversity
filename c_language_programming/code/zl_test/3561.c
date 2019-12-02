#include<stdio.h>
int main()
{
	char s[81], v[31], V[31];
	int i, n, c;
	while (gets(s) != NULL)
	{
		c = 0;
		n = strlen(s);
		for (i = 0; i < n; i++)
		{
			if (s[i] != s[n - 1 - i])
			{
				c = 1;
				break;
			}
		}
		if (c != 1)
		printf("Yes\n");
		else 
		printf("No\n");
	}
	return 0;
}