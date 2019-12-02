#include<stdio.h>
void swap(int *pa, int *pb);
int main()
{
    int a, b, c;
    printf("请分别输入a，b，c三个数：");
    while (scanf("%d%d%d", &a, &b, &c) != EOF)
    {
        if (a > b)
        swap(&a,&b);
        if (a > c)
        swap(&a,&c);
        if (b > c)
        swap(&b,&c);
        printf("%d %d %d\n", a, b, c);
    	printf("请分别输入a，b，c三个数：");
	}
    return 0;
}
void swap(int *pa, int *pb)
{
    int pt;
    pt = *pa;
    *pa = *pb;
    *pb = pt;
}
