#include<stdio.h>
int main()
{
    int n, i, a, b, c;
    int s;
    printf("请输入正整数n：");
    while(scanf ("%d", &n) != EOF)
    {
    	s = 1;
    	a = 0;
    	b = 1;
    	printf("斐波那契数列前%d项如下：\n", n);
    	for (i = 1;i <= n;i++)
    	{
        	printf ("%d ", s);
        	s = a + b;
        	a = b;
        	b = s;
    	}
    	printf("\n请输入正整数n：");
    }
    
    return 0;
}
