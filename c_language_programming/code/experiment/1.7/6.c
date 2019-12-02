#include <stdio.h>

int main(int argc, char *argv[])
{
	char chuan[100];
	int i, n;
	printf("请输入一串字符：");
	while((chuan[0] = getchar()) != EOF)
	{
		i = 1;
		while((chuan[i] = getchar()) != '\n')
		i++;
		n = i;
		printf("该串字符反序输出为：");
		for(i--;i >= 0;i--)
		putchar(chuan[i]);
		putchar(chuan[n]); 
		printf("请输入一串字符：");
	} 
	return 0;
}
