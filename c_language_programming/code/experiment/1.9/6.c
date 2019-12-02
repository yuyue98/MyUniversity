#include <stdio.h>
#include <string.h>
#include <malloc.h>

int findsame(char *s1,char *s2);

int main(int argc, char *argv[])
{
	char s1[20],s2[20];
	printf("请输入第一串字符："); 
	while(gets(s1) != NULL)
	{
		printf("请输入第二串字符：");
		gets(s2);
		findsame(s1,s2);
		printf("请输入第一串字符："); 
	} 
	return 0;
}

int findsame(char *s1,char *s2)
{
	char s[20];
	int i,j,k = 0;
	int flag = 0;
	for(i = 0;s1[i] != '\0';i++)
	{
		for(j = 0;j < k;j++)
		{
			if(s[j] == s1[i])
			{
				flag = 1;
				break;
			}
		}
		for(j = 0;s2[j] != '\0';j++)
		{
			if(s1[i] == s2[j] && flag == 0)
			{
				s[k] = s1[i];
				k++;
			}
		}
		flag = 0;
	}
	s[k] = '\0';
	printf("这两个字符串中相同的元素为：%s\n", s);
	return 0;
}
