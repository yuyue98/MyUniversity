#include<stdio.h>
#include<math.h>
int main()
{
	float a, b, n, pi = 3.1415926;
	scanf ("%f", &n);
	a = sin(n*pi/180);
	b = cos(n*pi/180);
	printf("%.2f\n%.2f\n", a, b);
    return 0;	
}