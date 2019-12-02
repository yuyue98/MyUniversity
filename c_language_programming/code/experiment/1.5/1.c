#include<stdio.h>
int fn(int a, int n);
int main()
{
    int a, b, n;
    int i, s;
    printf("请分别输入a与n：");
    while (scanf("%d%d", &a, &n) != EOF)
    {
        s = a;
		printf("%d", a);
        for (i = 2; i <= n; i++)
        {
        	b = fn(a, i);
        	printf("+%d", b);
        	s = s + b;
        }
        
        printf("=%d\n", s);
        printf("请分别输入a与n：");
    }
    return 0;
}
int fn(int a, int n)
{
    int s, i;
    s = 0;
    for (i = 1; i <= n; i++)
        s = s * 10 + a;
    return s;
}
