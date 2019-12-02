#include <stdio.h>
#include <string.h>

int max_len(char *s[], int n); 

int main(int argc, char *argv[])
{
	char *color[10];
	int i;
	char str[20];
	int n;
	printf("请输入字符串个数n：");
	while(scanf("%d", &n) != EOF)
	{
		getchar();
		for(i = 0;i < n;i++)
		{	
			printf("请输入第%d个字符串：", i+1);
			scanf("%s", str);
			color[i] = (char*)malloc((strlen(str)+1)*sizeof(char));
			if(!color[i])
			{
				printf("内存申请失败！\n");
				exit(0);
			}
			strcpy(color[i],str);
		}
		printf("最长字符串有效长度为：%d\n", max_len(color,n));
		for(i = 0;i < n;i++)
		{
			printf("color[%d] = %s\n", i, color[i]);
			free(color[i]);
		}
		printf("请输入字符串个数n：");
	}
	return 0;
}

int max_len(char *s[], int n)
{
	int i;
	int temp;
	temp = 0;
	for(i = 1;i < n;i++)
	{
		if(strlen(s[temp]) < strlen(s[i]))
		temp = i;
	}
	return strlen(s[temp]);
}
