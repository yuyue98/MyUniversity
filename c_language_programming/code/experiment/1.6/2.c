#include <stdio.h>
int main ()
{
    int n,i,s;
    printf("请输入一个正整数n：");
    while(scanf("%d",&n) != EOF)
    {
    	s = 1;
    	for(i=1;i<n;i++)
    	s=s*2+2;
    	printf("猴子第一天摘了%2d个桃\n",s);
    	printf("请输入一个正整数n：");
    }
    
        return 0;
}
