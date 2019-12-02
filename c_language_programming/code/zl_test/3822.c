#include<stdio.h>
int main()
{
	float f, c;
	scanf("%f", &f);
	c = 5.0 / 9 * (f - 32);
	printf("%.3f\n", c);
    return 0;
}