#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int sum = 0, number;
	char ch;
	if((fp = fopen("INT_DATA","r")) == NULL)
	{
	   printf("文件INT_DATA不存在,正在创建。。。\n");
	   fp = fopen("INT_DATA","w");
	   printf("请输入一串正整数：");
       scanf("%d", &number);
	   while(getchar() != '\n')
	   {
	       fprintf(fp,"%d ", number);
	       scanf("%d", &number);
       }
       fprintf(fp,"%d ", number);
	   printf("文件INT_DATA创建完毕！\n");
       fclose(fp);
       fp = fopen("INT_DATA","r");
    }
    printf("求和前文件INT_DATA中数据如下：\n");
    while(fscanf(fp,"%d",&number) != EOF)
    {
        printf("%d ", number);
        sum = sum +number;
    }
    printf("\n");
    fclose(fp);
    fp = fopen("INT_DATA","a");
    fprintf(fp," %d", sum);
    fclose(fp);
    fp = fopen("INT_DATA","r");
    printf("求和后文件INT_DATA中数据如下：\n");
    while(fscanf(fp,"%d",&number) != EOF)
    printf("%d ", number);
    printf("\n");
    fclose(fp);
	return 0;
}
