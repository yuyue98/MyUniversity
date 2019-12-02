#include<stdio.h>
struct timeline
{
    int year;
    int month;
    int day;
};
int main()
{
    struct timeline t1;
    int days, i;
    int p[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int r[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    printf("请输入年-月-日：");
    while (scanf("%d", &t1.year) != EOF)
    {
        scanf("-%d", &t1.month);
        scanf("-%d", &t1.day);
        days = 0;
        if ((t1.year % 4 == 0 && t1.year % 100 != 0) || t1.year % 400 == 0)
        {
            for (i = 0; i < t1.month - 1; i++)
            days += r[i];
            days += t1.day;
        }
        else
        {
            for (i = 0; i < t1.month - 1; i++)
            days += p[i];
            days += t1.day;
        }
        printf("其在该年中对应第%d天\n",days);
        printf("请输入年-月-日：");
    }
    return 0;
}
