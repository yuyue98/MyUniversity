#include<stdio.h>
int main()
{
	char s[81];
	int i, n, c;
	while (gets(s) != NULL)
	{
		c = 0;
		n = strlen(s);
		for (i = 0; i < n; i++)
		{
				if (s[i] == ' ' && s[i+1] != ' ')
		    	{
			    	c++;
		    	}
		}
		c = c + 1;
		printf("%d\n", c);
	}
	return 0;
}