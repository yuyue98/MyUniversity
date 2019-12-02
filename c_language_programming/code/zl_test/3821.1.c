#include<stdio.h>
int main()
{
	float f, d;
	scanf ("%f", &f);
	d = 5.0 / 9;
	printf("fahr=%f,celsius=%f\n", f, d*(f-32));
    return 0;
}