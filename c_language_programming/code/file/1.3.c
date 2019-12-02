#include<stdio.h>
int swap(int *p1,int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
    if (a < b)
	swap(&a,&b);
	if (a < c)
	swap(&a,&c);
	if (b < c)
	swap(&b,&c);
	printf("%d %d %d\n", a, b, c);
	return 0;
}