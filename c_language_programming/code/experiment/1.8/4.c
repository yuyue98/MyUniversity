#include <stdio.h>
#include <malloc.h>

void swap(int *pa, int *pb);
void sort(int *a, int n);

int main()
{
    int n, *a;
    int i;
    printf("请输入正整数n：");
    while (scanf("%d", &n) != EOF)
    {
    	a = (int*)malloc(n*sizeof(int));
    	if(!a)
    	{
	    	printf("内存申请失败！\n");
	    	exit(1);
	    }
        printf("请分别输入n个数：");
        for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
        sort(a,n);
        printf("排序后输出为：");
        for (i = 0; i < n-1; i++)
        printf("%d ", *(a+i));
        printf("%d\n", *(a+i));
        printf("请输入正整数n：");
    }
    return 0;
}
void sort(int *a, int n)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        t = i;
        for (j = i + 1;j < n; j++)
        {
            if (*(a+t) > *(a+j))
            t = j;
        }
        swap(a+i,a+t);
    }
}
void swap(int *pa, int *pb)
{
    int t;
    t = *pa;
    *pa = *pb;
    *pb = t;
}
