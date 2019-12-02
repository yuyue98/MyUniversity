#include<stdio.h>
#include<math.h>
int main()
{
	float a,b;
	scanf ("%f", &a);
	b = sqrt(a*a+a)-a;
	printf ("%f", b);
}