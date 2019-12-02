#include<stdio.h>
int main()
{
 int a;
 float b,c,d,e,f;
 scanf ("%d",&a);
 scanf ("%f%f%f",&b,&c,&d);
 e = b + c + d;
 f = e / a;
 printf ("%.2f\n",f);
 return 0;
}
