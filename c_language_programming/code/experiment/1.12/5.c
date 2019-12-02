#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, j;
	char ch;
	char xuehao[8], xingming[10], str[100];
	int math, chinese, english, sum;
	if((fp = fopen("f3.txt","r")) == NULL)
	{
		printf("文件f3.txt不存在，正在创建。。。\n");
		fp = fopen("f3.txt","w");
		fprintf(fp,"学号    姓名    数学    语文    英语\n");
		for(i = 0;i < 5;i++)
		{
			j = 0;
			printf("输入第%d个学生信息：", i+1);
			while((ch = getchar()) != ' ')
			xuehao[j++] = ch;
			xuehao[j] = '\0';
			j = 0;
			while((ch = getchar()) != ' ')
			xingming[j++] = ch;
			xingming[j] = '\0';
			scanf("%d %d %d", &math, &chinese, &english);
			getchar();
			//printf("%s %s%d%d%d\n", xuehao, xingming, math, chinese, english);
			fprintf(fp,"%-8s%-8s%-8d%-8d%-8d\n", xuehao, xingming, math, chinese, english);
		}
		fclose(fp);
		printf("文件f3.txt创建完毕！\n");
		fp = fopen("f3.txt","r");
	}
	printf("文件f3.txt读取成功！\n");
	fgets(str,100,fp);
	printf("学号    姓名    数学    语文    英语    总分    平均分\n");
	for(i = 0;i < 5;i++)
	{
		fgets(xuehao,8,fp);
		xuehao[7] = '\0';
		fgets(xingming,10,fp);
		xingming[5] = '\0';
		fscanf(fp,"%d", &math);
		fgets(str,7,fp);
		fscanf(fp,"%d", &chinese);
		fgets(str,7,fp);
		fscanf(fp,"%d", &english);
		fgets(str,7,fp);
		fscanf(fp,"%-9d%-9d%-9d", &math, &chinese, &english);
		sum = math + chinese + english;
		printf("%-7s%-9s%-8d%-8d%-8d%-8d%-8d\n", xuehao, xingming, math, chinese, english, sum, sum/3);
	}
	fclose(fp);
	return 0;
}
