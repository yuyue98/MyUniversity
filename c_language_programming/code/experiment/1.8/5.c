#include<stdio.h>
int sumDiff(int op1, int op2, int *psum, int *pdiff);
int main()
{
    int a, b;
    int sum, diff;
    printf("请任意输入两个整数a，b："); 
    while (scanf("%d%d", &a, &b) != EOF)
    {
        sumDiff(a,b,&sum,&diff);
        printf("两数的和与差如下：\n"); 
        printf("sum=%d diff=%d\n", sum,diff);
    	printf("请任意输入两个整数a，b：");
	}
    return 0;
}
int sumDiff(int op1, int op2, int *psum, int *pdiff)
{
    *psum = op1 + op2;
    *pdiff = op1 - op2;
}
