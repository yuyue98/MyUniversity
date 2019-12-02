#include<stdio.h>
int main()
{
    int a, b, c;
    scanf ("%d%d", &a, &b);
    if (a < b)
    c = a, a = b, b = c;
    else
    a = a, b = b;
    printf ("%d %d\n", a, b);
    return 0;	
}