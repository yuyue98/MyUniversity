#include<stdio.h>
int is(int n);
int main()
{
    int n, m, i, c;
    printf("请分别输入m，n(m<n)：");
    while (scanf("%d%d", &m, &n) != EOF)
    {
        c = 0;
		printf("%d~%d之间满足各位数字立方和等于它本身的数有：", m, n); 
        for (i = m; i <= n; i++)
        {
            if (is(i) == 1 && c == 0)
            {
                printf("%d",i);
                c = 1;
            }
            else if (is(i) == 1 && c == 1)
            {
                printf(" %d",i);
            }
        }
        printf("\n");
        printf("请分别输入m，n(m<n)：");
    }
    return 0;
}
int is(int n)
{
    int a, b, c, s;
    b = n;
    c = 0;
    s = 0;
    do
    {
        a = b % 10;
        b = b / 10;
        s = s + a * a * a;
    }while (b >= 1);
    if (s == n)
    c = 1;
    return c;
}
