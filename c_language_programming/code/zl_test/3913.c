#include<stdio.h>
int main()
{
	char s[101], v[26], V[26];
	int a[26], i, n, j, c;
	v[0] = 'a';
	for (i = 1; i < 26; i++)
	{v[i] = v[0] + i;}
	V[0] = 'A';
	for (i = 1; i < 26; i++)
	{
		V[i] = V[0] + i;
	}
	while (gets(s) != NULL)
	{
		for (i = 0; i < 26; i++)
		a[i] = 0;
		n = strlen(s);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 26; j++)
			{
				if (s[i] == v[j] || s[i] == V[j])
		    	{
			    	a[j]++;
			    	break;
		    	}
			}
		}
		for (i = 0; i < 26;i++)
		{
			if (a[i] != 0)
		    printf("%c: %d\n", v[i], a[i]);
		}
		printf("\n");
	}
	return 0;
}