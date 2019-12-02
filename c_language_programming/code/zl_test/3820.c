#include<stdio.h>
int main()
{
	float a, b, c;
	float n;
	scanf ("%f%f%f", &a, &b, &c);
	n = (a + b + c) / 3;
	printf("%.3f\n", n);
    return 0;
}