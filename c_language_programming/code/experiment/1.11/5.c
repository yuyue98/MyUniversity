#include <stdio.h>

int changeandsum(int *x, int *y); 

int main(int argc, char *argv[])
{
	int (*cs)(int, int);
	int x, y;
	int sum;
	cs = changeandsum;
	printf("请分别输入两个数x，y：");
	while(scanf("%d%d", &x, &y) != EOF)
	{
		sum = (*cs)(&x,&y);
		printf("sum = %d\nx = %d y = %d\n", sum, x, y);
		printf("请分别输入两个数x，y：");
	}
	return 0;
}

int changeandsum(int *x, int *y)
{
	int sum;
	int t;
	sum = (*x) + (*y);
	t = *y;
	*y = *x;
	*x = t;
	return sum;
}
