#include<stdio.h>
int main()
{
    int a,b,c,d,t=0;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
       d=a+b+c;
       if( t>0) 
	   printf("\n");
       printf("%d\n",d);//ע������\n
       t++;
    }
    return 0;
}


