#include<stdio.h>
int factorsum(int n);
int main()
{
    int i;
    int n, m, c;
    int a[100];
    printf("请分别输入m与n(m<n)："); 
    while (scanf("%d%d", &m, &n) != EOF)
    {
        c = 0;
        for (i = m; i <= n; i++)
        {
            if(i == factorsum(i))
            {
                a[c] = i;
                c++;
            }
        }
       	printf("在%d~%d间的完数有：", m, n);
        for (i = 0; i < c; i++)
        { 
            printf("%d", a[i]);
            if (i == c - 1)
            printf("\n");
            else
            printf(" ");
        }
        printf("请分别输入m与n(m<n)："); 
    }
    return 0;
}
int factorsum(int n)
{
    int i, sum;
    sum = 0;
    for(i = 1; i < n; i++)
    {
        if (n % i == 0)
        sum = sum + i;
    }
    return sum;
}
