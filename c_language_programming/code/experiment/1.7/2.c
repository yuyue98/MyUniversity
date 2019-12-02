#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[20], i, n, c, m;
	printf("请输入要输入的整数个数n："); 
    while((scanf ("%d", &n)) != EOF)
    {
        c = 0;
		printf("请输入%d个整数：", n);  
        for (i = 0; i < n; i++)
        {
            scanf ("%d", &a[i]);
        }
        printf("请输入要删除的整数m：");
        scanf ("%d", &m);
        for (i = 0; i < n; i++)
        {
            if (m == a[i])
            {
                a[i] = a[i + 1];
                m = a[i + 1];
            }
            else
            c++;
        }
        printf("删数后输出为：");
        if (c == n)
        {
            for (i = 0; i < n; i++)
            {
                printf ("%d", a[i]);
                if (i == n - 1)
                printf ("\n");
                else
                printf (" ");
            }
        }
        else
        {
            for (i = 0; i < n - 1; i++)
            {
                printf ("%d", a[i]);
                if (i == n - 2)
                printf ("\n");
                else
                printf (" ");
            }
        }
        printf("请输入要输入的整数个数n："); 
    }
	return 0;
}
