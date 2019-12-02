#include<stdio.h>
int main()
{
        int n,i;
        scanf("%d",&n);
        i=n-1;
        while(i>1)
        {n=n*i;
        i=i-1;
        }
        printf ("%d\n",n);
}