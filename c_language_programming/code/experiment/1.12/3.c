#include <stdio.h>


int main(int argc, char *argv[])
{
	FILE *fp;
	char str;
	if((fp = fopen("a.txt","r")) == NULL)
	{
		printf("文件a.txt不存在，正在创建。。。\n");
		fp = fopen("a.txt","a");
		fputs("HELLO WORLD!\n",fp);
		fputs("MY name is COMPUTER.\n",fp);
		fputs("I love YOU!\n",fp);
		fputs("Bybe~\n",fp);
		fclose(fp);
		printf("文件a.txt创建完毕！\n");
		fp = fopen("a.txt","r");
	} 
	printf("文件a.txt读取成功！\n");
	while(fscanf(fp,"%c",&str) != EOF)
	{
		if(str >= 'A' && str <= 'Z')
		str = str + 'a' - 'A';
		putchar(str);
	}
	fclose(fp);
	return 0;
}
