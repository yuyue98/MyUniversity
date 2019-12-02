#include<stdio.h>
float sum_diff(float op1,float op2,float *psum,float *pdiff);
int main()
{
	float a, b;
	float sum, diff;
	scanf ("%f%f", &a, &b);
	sum_diff(a, b, &sum, &diff);
	printf("a+b=%f,a-b=%f\n", sum, diff);
	return 0;
}
float sum_diff(float op1,float op2,float *psum,float *pdiff)
{
	*psum = op1 + op2;
	*pdiff = op1 - op2;
}