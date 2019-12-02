#include<stdio.h>
int main()
{
	char s[81];
	int i, n;
	while (gets(s) != NULL)
	{
		n = strlen(s);
		for (i = 0; i < n; i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
		    s[i] = s[i] -32;
		}
		puts(s);
	}
	return 0;
}