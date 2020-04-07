#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#define MAXLEN 50

int num;

int getstrlen(int **array, char *str1, char *str2, int len1, int len2);
void getstr(int **array, char *str, char *str1, int len, int len1,int len2);

int main()
{
	int i, j, k;
	char str[MAXLEN], str1[MAXLEN], str2[MAXLEN];
	while(1)
	{
		num = 0;
		printf("请分别输入两个字符串：\n");
		gets(str1);
		gets(str2);
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		if (len1 > len2)
		{
			memcpy(str,str1,MAXLEN);
			memcpy(str1,str2,MAXLEN);
			memcpy(str2,str,MAXLEN);
			int t = len1;
			len1 = len2;
			len2 = t;
		}
		int **array;
		array = (int**)malloc((len1+1)*sizeof(int*));
		for (i = 0;i <= len1;i++)
			array[i] = (int*)malloc((len2+1)*sizeof(int));
		for (i = 0;i <= len2;i++)
			array[0][i] = 0;
		for (i = 0;i <= len1;i++)
	 		array[i][0] = 0;
		for (i = 0;i <= len1;i++)
	 		for (j = 1;j <= len2;j++)
	 			array[i][j] = 0;
		for (i = 0;i <= len1;i++)
		{
			for (j = 1;j <= len2;j++)
			{
				printf("%3d", array[i][j]);
			}
			printf("\n");
		}
		int len = getstrlen(array,str1,str2,len1,len2);
	 	getstr(array,str,str1,len,len1,len2);
	 	str[len] = '\0';
		puts(str1);
		puts(str2);
		puts(str);
		printf("len1 = %d, len2 = %d\n", len1, len2);
		for (i = 0;i <= len1;i++)
		{
			for (j = 0;j <= len2;j++)
			{
				printf("%3d ", array[i][j]);
			}
			printf("\n");
		}
		for(i = 0;i <= len1;i++)
			free(array[i]);
		free(array);
	}
}

int getstrlen(int **array, char *str1, char *str2, int len1, int len2)
{
	if (len1 == 0 || len2 == 0)
	{
		array[len1][len2] = 0;
	} 
	else
	{
		if (str1[len1-1] == str2[len2-1])
		{
			array[len1][len2] = getstrlen(array,str1,str2,len1-1,len2-1) + 1;
		}
		else 
		{
			int num1 = getstrlen(array,str1,str2,len1-1,len2);
			int num2 = getstrlen(array,str1,str2,len1,len2-1);
			array[len1][len2] = num1>num2?num1:num2;
		}
	}
	return array[len1][len2];	
}

void getstr(int **array, char *str, char *str1, int len, int len1,int len2)
{
	if (len1 == 0 || len2 == 0)
	{
		return;
	}
	else
	{
		if(array[len1][len2] == array[len1][len2-1])
		{
			getstr(array,str,str1,len,len1,len2-1);
		}
		else if (array[len1][len2] == array[len1-1][len2])
		{
			getstr(array,str,str1,len,len1-1,len2);
		}
		else
		{
			str[len-1] = str1[len1-1];
    		getstr(array,str,str1,len-1,len1-1,len2-1);
		}
	}
}
