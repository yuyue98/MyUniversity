#include<stdio.h>
int main()
{
	char s[81];
	int i, l;
	while (gets(s) != NULL)
	{
		l = strlen(s) - 1;
		for (i = l; i >= 0; i--)
		printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}