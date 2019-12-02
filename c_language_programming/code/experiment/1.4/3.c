#include <stdio.h>
int main(int argc, char *argv[])
{
    int i, j, n;
    printf("请输入一个正整数：");
    while (scanf ("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
    {  
        for (j = 1; j <= n - i; j++)
        {
            printf (" ");
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf ("%d", i);
        }
        printf ("\n");
    }
        for (i = 1; i < n; i++)
    {  
        for (j = 1; j <= i; j++)
        {
            printf (" ");
        }
        for (j = 1; j <= 2 * n - 2 * i - 1; j++)
        {
            printf ("%d", n - i);
        }
        printf ("\n");
    }
    printf("请输入一个正整数："); 
    }
    return 0;
}
