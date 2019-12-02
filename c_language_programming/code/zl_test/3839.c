#include<stdio.h>
int main()
{
    int n;
    int i, a;
    int b, c;
    scanf("%d", &n);
    for(i = 1;i <= n;i++)
    {
    	scanf ("%d %d", &b, &c);
    	a = b + c;
    	printf ("%d\n", a);
     }
     return 0;
}