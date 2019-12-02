#include <stdio.h>

int prime(int n);

int main(int argc, char *argv[])
{
	int i, j;
	int a = 0;
	for(i = 6;i <= 100;i+=2)
	{
		for(j = 3;j <= i/2;j++)
		{
			if(prime(j) == 1 && prime(i - j) == 1)
			{
				printf("%3d=%2d+%2d", i, j, i-j);
				a++;
				if(a % 5 == 0)
				printf("\n");
				else
				printf("\t");
				break;
			}
		}
	} 
	printf("\n");
	return 0;
}

int prime(int n)
{
	int i;
	for(i = 2;i < n / 2;i++)
	{
		if(n % i == 0)
		return 0;
	}
	return 1;
}
