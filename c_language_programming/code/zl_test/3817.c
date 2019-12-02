#include<stdio.h>
int main ()
{
	int a,b,c,d;
	scanf ("%d%d%d",&b,&c,&d);
	if (b>c && b>d)
	{
	   a=b;
	   if (c>d)
	   {
	      b=c;
	      c=d;	
	   }else
	   {
	      b=d;
	   }	
	}else if (c>b && c>d)
	{
	   a=c;
	   if (b>d)
	   {
	      c=d;
	   }else
	   {
	      c=b;
	      b=d;	
	   }	
	}else
	{
	   a=d;
	   if (b>c)
	   {
	      b=b;
	      c=c;	
	   }else
	   {
	      d=c;
	      c=b;
	      b=d;	
	   }	
	}
	printf ("%d %d %d",a,b,c);
	return 0;
}