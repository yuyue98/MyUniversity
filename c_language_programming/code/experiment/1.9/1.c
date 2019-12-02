#include <stdio.h>
#include <string.h>

char* mcopy(char *src, char *dst, int m); 

int main(int argc, char *argv[])
{
	int m, len;
	char src[80], *dst;
	printf("请输入一个正整数m：");
	while(scanf("%d", &m) != EOF)
	{
		getchar();
		printf("请输入一个字符串：");
		gets(src);
		dst = mcopy(src,dst,m);
		printf("部分复制的字符串为：");
		puts(dst);
		printf("请输入一个正整数m：");
	}
	return 0;
}

char* mcopy(char *src, char *dst, int m)
{
	return src + m - 1;
}
