#include "myheader.h"
#include "huffmantree.h"

void save_codefile(hfmtree *HT)//保存文件编码 
{
	FILE *fp;
	char str[MAX];
	int i, j;
	if((fp = fopen("ToBeTran.txt","r")) == NULL)
	{
		printf("文件ToBeTran.txt不存在！\n");
		printf("请输入待编码内容：\n");
		fp = fopen("ToBeTran.txt","w");
		gets(str);
		fprintf(fp,"%s",str);
		if(fclose(fp))
		{
			printf("文件关闭失败！\n");
			exit(0);
		}
	}
	else
	{
		fgets(str,MAX,fp);
	}
	if(fp != NULL)
	fclose(fp);
	if((fp = fopen("CodeFile.txt","r")) != NULL)
	{
		fclose(fp);
		fp = fopen("CodeFile.txt","w");
		fclose(fp);
	}
	if(HT->length == 0 && HT->number == 0 && HT->firstnode == NULL && HT->list == NULL)
	load_hfmtree(HT);
	printf("报文为：%s\n", str);
	printf("哈夫曼编码如下：\n");
	fp = fopen("CodeFile.txt","a");
	for(i = 0;str[i] != '\0';i++)
	{
		for(j = 0;j < HT->length;j++)
		{
			if(str[i] == HT->firstnode[j].data)
			break;
		}
		printf("%s", HT->list[j]);
		fprintf(fp,"%s", HT->list[j]);
	}
	printf("\n");
	if(fclose(fp))
	{
		printf("文件关闭失败！\n");
		exit(0);
	} 
}

void load_codefile(hfmtree *HT)//读取文件编码 
{
	FILE *fp;
	char str[MAX_CODE];
	int i, j, temp;
	if((fp = fopen("CodeFile.txt","r")) == NULL)
	save_codefile(HT);
	if(fp == NULL)
	fp = fopen("CodeFile.txt","r");
	if(HT->length == 0 && HT->number == 0 && HT->firstnode == NULL && HT->list == NULL)
	load_hfmtree(HT);
	fgets(str,MAX_CODE,fp);
	if(fclose(fp))
	{
		printf("文件关闭失败！\n");
		exit(0);
	}
	if((fp = fopen("TextFile.txt","r")) != NULL)
	{
		fclose(fp);
		fp = fopen("TextFile.txt","w");
		fclose(fp);
	}
	fp = fopen("TextFile.txt","a");
	printf("哈夫曼编码为：\n%s\n", str);
	printf("译文为："); 
	temp = HT->number - 1;
	for(i = 0;i <= strlen(str);i++)
	{
		if(HT->firstnode[temp].lchild == 0 && HT->firstnode[temp].rchild == 0)
		{
			printf("%c", HT->firstnode[temp].data);
			fprintf(fp,"%c", HT->firstnode[temp].data);
			temp = HT->number - 1;
		}
		if(str[i] == '0')
		temp = HT->firstnode[temp].lchild;
		else
		temp = HT->firstnode[temp].rchild;	
	}
	printf("\n");
	if(fclose(fp))
	{
		printf("文件关闭失败！\n");
		exit(0);
	} 
}
