#include<stdio.h>
int main()
{
    int a,b,c,d;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
       d=a+b+c;
       printf("%d\n",d);//注意后面的\n
    }
    return 0;
}
