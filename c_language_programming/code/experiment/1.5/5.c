#include<stdio.h>
int reverse(int number);
int main()
{
    int n, m, c;
    printf("请输入一个整数：");
    while (scanf("%d", &n) != EOF)
    {
        c = 1;
        if (n < 0)
        {
            n = -n;
            c = -1;
        }
        m = c * reverse(n);
        printf("此数逆序输出为：%d\n", m);
        printf("请输入一个整数：");
    }
    return 0;
}
int reverse(int number)
{
    int a, b, c, s;
    b = number;
    c = 0;
    s = 0;
    do
    {
        a = b % 10;
        b = b / 10;
        s = 10 * s + a;
    }while (b >= 1);
    return s;
}
