#include<stdio.h>
int main()
{
	char x;
	int n, c = 0, b = 0, d = 0, o = 0;
	while ((x = getchar()) != '\n')
	{
		n = x;
		if (n == 32)
		b++;
		else if (n >= 48 && n <= 57)
		d++;
		else if (n >= 65 && n <= 90)
		c++;
		else if (n >= 97 && n <= 122)
		c++;
		else
		o++;
	}
	printf ("charaters: %d\nblanks: %d\ndigitals: %d\nothers: %d\n", c, b, d, o);
}