#include<stdio.h>

int swap(int *p1,int *p2)
{
	int *temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
	printf("a = %d, b = %d\n", *p1, *p2);
}
int main()
{
	int x, y;
	x = 3;
    y = 5;
	swap(&x,&y);
	printf("x = %d, y = %d\n", x, y);
    system("pause");
	return 0;
} 