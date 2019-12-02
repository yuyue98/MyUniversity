#include<stdio.h>
int main()
{
	char c[100];
	int i;
	gets (c);
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] >= 'A' && c[i] <= 'W')
		c[i] = c[i] + 3;
		else if (c[i] >= 'a' && c[i] <= 'w')
		c[i] = c[i] + 3;
		else if (c[i] >= 'x' && c[i] <= 'z')
		c[i] = c[i] - 23;
		else if (c[i] >= 'X' && c[i] <= 'Z')
		c[i] = c[i] - 23;
	}
	puts (c);
	return 0;
}