#include <stdio.h>
#include <string.h>

void fun(char **p); 

int main(int argc, char *argv[])
{
	char *a[] = {"ihg","fed","cba"};
	fun(a);
	return 0;
}

void fun(char **p)
{
	int i, j;
	char str[8];
	printf("指针数组中内容如下：\n");
	for(i = 0;i < 3;i++)
	printf("第%d串字符为：%s\n", i+1, p[i]);
	printf("字符串逆序输出为：");
	for(i = 2;i >= 0;i--)
	{
		for(j = 2;j >= 0;j--)
		printf("%c", p[i][j]);
	}
	printf("\n");
	system("pause");
}