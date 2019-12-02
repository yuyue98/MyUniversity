#include <stdio.h>
#include <malloc.h>

char* f(long int x,char *p); 

int main(int argc, char *argv[])
{
	long int number;
	char p[16] ={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E'};
	char *q;
	printf("请输入一个十进制长整数：");
	while(scanf("%ld", &number) != EOF)
	{
		getchar();
		q = f(number,p);
		printf("转化后的十六进制字符串为：%s\n", q);
		free(q);
		//printf("number十六进制表示为：%lx\n", number);
		printf("请输入一个十进制长整数：");
	} 
	return 0;
}

char* f(long int x,char *p)
{
	char chuan[20];
	int num = 1, i;
	char *q;
	chuan[0] = '\0';
	while(x != 0)
	{
		chuan[num] = p[x % 16];
		x = x / 16;
		num++;
	}
	num--;
	q = (char*)malloc((num)*sizeof(char));
	if(!q)
	{
		printf("内存申请失败！\n");
		exit(1);
	}
	for(i = 0;chuan[num] != '\0';i++,num--)
	{
		q[i] = chuan[num];
	}
	q[i] = '\0';
	return q;
}
