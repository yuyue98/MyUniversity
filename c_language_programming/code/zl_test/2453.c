#include<stdio.h>
void swap(int *p1,int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if (a<b) swap(&a,&b);
        printf("%d %d\n",a,b);
    }
}


