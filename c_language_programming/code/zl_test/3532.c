#include<stdio.h>
int main()
{
	int a, a1, a2, a3, a4, a5, a6, a7, a8,a9, a0;
	float ave;
	scanf ("%d%d%d%d%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a0);
	a=a1+a2+a3+a4+a5+a6+a7+a8+a9+a0;
	ave = a / 10.0;
	printf ("ave=%.1f\n", ave);
    return 0;	
}