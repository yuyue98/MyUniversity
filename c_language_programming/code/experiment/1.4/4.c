#include<stdio.h>
#include<math.h>
int zhi_he(int n);
int main(int argc, char *argv[])
{
	int number, yinzi, i;
	printf("请输入一个正整数：");
 	while(scanf("%d", &number) != EOF)
	{
 		printf("因式分解为：%d=", number);
 		if(zhi_he(number) == 1)
 		printf("1*");
		while(zhi_he(number) != 1)
		{
			for(i=2;i<number;i++)
			if(zhi_he(i) == 1 && number % i == 0)
			{
				printf("%d*", i);
				number = number / i;
				break; 
			} 
			
		}
		printf("%d\n", number);
		printf("请输入一个正整数：");
		
 	}	
	return 0;
}
int zhi_he(int n)
{
	int i=2;
	while(i<n)
	{
		if(n % i != 0)
		{
			i++;
		}
		else
		return 0;
	}
	return 1;
}
