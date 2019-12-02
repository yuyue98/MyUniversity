#include<stdio.h>
int main ()
{
    int a[20];
    int n,m,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        scanf("\n");
        scanf("%d",&m);

        for(i=0;i<n;i++)
           if(a[i]==m)
           {
            for(j=i;j<n-1;j++)
               a[j]=a[j+1];
               a[n-1]=0;
               printf("%d ",a[i]);

               break;
           }
           else
           printf("%d ",a[i]);
           for (j=i;j<n-1;j++)
           printf ("%d ",a[j]);
    }
    return 0 ;
}