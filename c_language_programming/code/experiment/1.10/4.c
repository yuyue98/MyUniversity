#include <stdio.h>
#include <string.h>
#include <math.h>

int nixu(int number, int len);
 
int main(int argc, char *argv[])
{
	int number;
	int n;
	int len;
	printf("请输入一个整数n：");
	while(scanf("%d", &number) != EOF)
	{
		getchar();
		n = number;
		len = 0;
		while(n != 0)
		{
			n = n / 10;
			len++;
		}
		if(number >= 0)
		printf("nixu(%d) = %d\n", number, nixu(number,len-1));
		else
		printf("nixu(%d) = %d\n", number, -nixu(-number,len-1));
		printf("请输入一个整数n：");
	}
	return 0;
}

int nixu(int number, int len)
{
	int result;
	int n, i, b = 1;
	if(number < 10)
	result = number;
	else
	{
		for(i = 1;i <= len;i++)
		b = b * 10;
		result = nixu(number-number/b*b,len-1) * 10 + number/b;
	}
	return result;
}
