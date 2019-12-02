#include <stdio.h>

int main(int argc, char *argv[])
{
	char *month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"}; 
	int number;
	printf("请输入一个代表月份的数字："); 
	while(scanf("%d", &number) != EOF)
	{
		printf("这个月份的英文为：%s\n", month[number-1]);
		printf("请输入一个代表月份的数字："); 
	} 
	return 0;
}
