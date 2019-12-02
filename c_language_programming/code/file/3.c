#include<stdio.h>
int main()
{
    int s;
    char z;
    scanf ("%d",&s);
    if (s >= 90)
    z = 'A';
    else if (s >= 80)
    z = 'B';
    else if (s >= 70)
    z = 'C';
    else if (s >= 60)
    z = 'D';
    else
    z = 'E';
    printf ("%c",z);
    return 0;	
}