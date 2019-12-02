#include<stdio.h>
void main()
{
int i,n;
int a[100];
int s,p;

scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
s=a[0];
p=0;
for(i=1;i<n;i++)
{
if(s<a[i])
{
s=a[i];
p=i;
}
}
a[p]=a[n-1];
a[n-1]=s;
s=a[0];
p=0;
for(i=1;i<n;i++)
{
if(s>a[i])
{
s=a[i];
p=i;
}
}
a[p]=a[0];
a[0]=s;
printf("max=%d, min=%d",a[n-1],a[0]);
printf("\n");
}