#include<stdio.h>
int main()
{
    int a, b, c, d;
    scanf ("%d%d%d",&a,&b,&c);
    if (a>b)
    {
        d=a;
        if (c>d)
        {
            a=c;	
        }else
        {
            a=d	
        }	
    }else
    {
        d=b;	
    }	
}

