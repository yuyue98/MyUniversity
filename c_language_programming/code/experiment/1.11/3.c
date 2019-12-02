#include <stdio.h>
#include <string.h>

char* change(char *s[], int n);  

int main(int argc, char *argv[])
{
	char *word[8];
	int n, i;
	char str[20];
	printf("请输入字符串个数n：");
	while(scanf("%d", &n) != EOF)
	{
		char *p;
		getchar();
		for(i = 0;i < n;i++)
		{
			printf("请输入第%d个字符串：", i+1);
			scanf("%s", str);
			word[i] = (char*)malloc((strlen(str)+1)*sizeof(char));
			if(!word[i])
			{
				printf("内存申请失败！\n");
				exit(0);
			}
			strcpy(word[i],str);
		}
		p = change(word,n);
		printf("每个单词最后一个字母连起来形成的新单词为：%s\n", p);
		for(i = 0;i < n;i++)
		printf("word[%d] = %s\n", i, word[i]);
		for(i = 0;i < n;i++)
		free(word[i]);
		free(p);
		printf("请输入字符串个数n：");
	}
	return 0;
}

char* change(char *s[], int n)
{
	char *newword;
	int i;
	newword = (char*)malloc((n+1)*sizeof(char));
	if(!newword)
	{
		printf("内存申请失败！\n");
		exit(0);
	}
	for(i = 0;i < n;i++)
	{
		newword[i] = *(s[i]+strlen(s[i])-1);
	}
	newword[i] = '\0';
	return newword;
}
