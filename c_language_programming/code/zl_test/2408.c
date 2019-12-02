#include<stdio.h>
int main()
{
	float fahr, celsius;
	scanf ("%f", &fahr);
	celsius = 5.0 * (fahr - 32) / 9;
	printf("fahr=%f,celsius=%f\n", fahr, celsius);
    return 0;
}