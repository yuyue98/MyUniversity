#include<stdio.h>
int main()
{
        int a1,a2,a3,b,c,d;
        scanf("%d",&c);
        b=c%100;
        a1=b%10;
        a2=(b-a1)/10;
        a3=(c-b)/100;
        d=a1*100+a2*10+a3;
        printf ("%03d\n",d);
}