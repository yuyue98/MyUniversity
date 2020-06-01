#include<stdio.h>
void f1(void);
int main()
{
	int x;
	x = 10;
	if (x == 10)
	{
		int x;
		x = 99;
		printf("Inner x: %d\n", x);
	}
	printf("Outer x: %d\n", x);
	int i;
	for(i = 0;i < 10;i++)
	f1();
	return 0;
}
void f1(void)
{
	int j;
	j = 10;
	printf("%d ", j);
	j++;
}