#include<stdio.h>
int main()
{
    int n,i,s,a;
    while(scanf("%d",&n)!= EOF && n!=0)
    {
    	 s = 0;
         for(i=1;i<=n;i++)
         { 
              scanf ("%d", &a);
              s = s + a;
         }
         printf ("%d\n", s);
    }
}
