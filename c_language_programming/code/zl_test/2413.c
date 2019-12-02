#include<stdio.h>
#include<math.h>
int main()
{
	float a, b, c;
	float p, s;
	scanf ("%f %f %f", &a, &b, &c);
	p=(a + b + c) *1.0 / 2;
    s= sqrt (p * (p - a) * (p - b) * (p - c) * 1.0);
    printf ("%.2f\n", s);
	return 0;
}