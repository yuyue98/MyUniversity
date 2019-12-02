#include<stdio.h>
int countdigit(int number, int digit);
int main()
{
    int number;
    int c;
    printf("请输入一个整数：");
    while (scanf("%d", &number) != EOF)
    {
        c = countdigit(number, 2);
        printf("数中‘2’的个数为：%d\n", c);
        printf("请输入一个整数：");
    }
    return 0;
}
int countdigit(int number, int digit)
{
    int a, c;
    c = 0;
    do
    {
        a = number % 10;
        number = number / 10;
        if (a == digit)
        c++;
    }while (number > 1);
    return c;
}
