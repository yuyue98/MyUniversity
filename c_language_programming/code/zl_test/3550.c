#include<stdio.h>
int main()
{
	char s[81];
	int a[5] = {0,0,0,0,0}, i, n;
	while (gets(s) != NULL)
	{
		n = strlen(s);
		for (i = 0; i < n; i++)
		{
			if (s[i] == 'a' || s[i] == 'A')
		    a[0]++;
		    else if (s[i] == 'e' || s[i] == 'E')
		    a[1]++;
		    else if (s[i] == 'i' || s[i] == 'I')
		    a[2]++;
		    else if (s[i] == 'o' || s[i] == 'O')
		    a[3]++;
		    else if (s[i] == 'u' || s[i] == 'U')
		    a[4]++;
		}
		for (i = 0; i < 5; i++)
		printf("%d\n", a[i]);
	}
	return 0;
}