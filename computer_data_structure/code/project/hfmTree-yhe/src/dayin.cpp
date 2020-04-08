#include "head.h"

void dayin_hfmcode(hfmtree *HT)//打印文件编码
{
	FILE *fp;
	int i;
	char str[MAX_CODE];
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
	if((fp = fopen("CodePrin.txt","r")) != NULL)
	{
		fclose(fp);
		fp = fopen("CodePrin.txt","w");
		fclose(fp);
	}
	fp = fopen("CodePrin.txt","a");
	for(i = 0;i < strlen(str);i++)
	{
		if(i == 0)
		{
			printf("第%d行:", i+1);
			fprintf(fp,"第%d行:", i+1);
		}
		if(i != 0 && i % 50 == 0)
		{
			printf("\n第%d行:", i/50+1);
			fprintf(fp,"%c第%d行:", '\n', i/50+1);
		}
		printf("%c", str[i]);
		fprintf(fp,"%c",str[i]);
	}
	printf("\n");
	if(fclose(fp))
	{
		printf("文件关闭失败！\n");
		exit(0);
	} 
} 

void dayin_hfmtree(hfmtree *HT)//打印哈夫曼树 
{
	FILE *fp;
	int i, all = chengfang(2,HT->depth);
	int *q, *p;
	if(HT->length == 0 && HT->number == 0 && HT->firstnode == NULL && HT->list == NULL)
	load_hfmtree(HT);
	if((fp = fopen("TreePrin.txt","r")) != NULL)
	{
		fclose(fp);
		fp = fopen("TreePrin.txt","w");
		fclose(fp);
	}
	fp = fopen("TreePrin.txt","a");
	printf("length = %d, number = %d, depth = %d\n", HT->length, HT->number, HT->depth);
	printf("hfmtree中内容如下：\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	printf("序号\t字符\t权值\t父亲\t左孩子\t右孩子\t深度\n");
	for(i = 0;i < HT->number;i++)
	printf("%d\t%c\t%d\t%d\t%d\t%d\t%d\n", i, HT->firstnode[i].data, HT->firstnode[i].weight, HT->firstnode[i].parent, HT->firstnode[i].lchild, HT->firstnode[i].rchild, HT->firstnode[i].depth);	
	printf("hfmlist中内容如下：\n");
	printf("序号\t字符\t编码\n");
	for(i = 0;i < HT->length;i++)
	printf("%d\t%c\t%s\n", i, HT->firstnode[i].data, HT->list[i]);
	//测试hfmtree是否正确录入
	int front, rear; 
	front = rear = 0;
	p = (int*)malloc(all*sizeof(int));
	q = (int*)malloc(HT->depth*sizeof(int));
	if(!p || !q)
	{
		printf("内存申请失败！\n");
		exit(0);
	}
	p[rear++] = HT->number - 1;
	while(front != rear && rear < all - 1)
	{
		//printf("%d\t%d\n", front, rear);
		if(p[front] == -1 || (HT->firstnode[p[front]].lchild == 0 && HT->firstnode[p[front]].rchild == 0))
		{
			p[rear++] = -1;
			p[rear++] = -1;
		}
		else
		{
			p[rear++] = HT->firstnode[p[front]].lchild;
			p[rear++] = HT->firstnode[p[front]].rchild;	
		}
		front++;
	}
	/*for(i = 0;i < rear;i++)
	{
		if(i % 10 == 0)
		printf("\n");
		printf("%d ", p[i]);
	}
	printf("\n");*/
	//测试hfmtree是否全部进入队列p 
	int j, k, n = 0, m = 0;
	int temp = 0;
	printf("hfmtree树形打印如下：\n");
	fprintf(fp,"hfmtree树形打印如下：\n");
	for(i = 1;i <= HT->depth;i++)
	{
		temp = chengfang(2,HT->depth-i)-1;
		for(j = 0;j < temp;j++)
		{
			printf(" ");
			fprintf(fp," ");
		} 
		temp = chengfang(2,i-1);
		for(j = 0;j < temp;j++)
		{
			if(p[n] == -1)
			{
				printf(" ");
				fprintf(fp," ");	
			}
			else
			{
				if(HT->firstnode[p[n]].data == ' ')
				{
					printf("_");
					fprintf(fp,"_");
				}
				else
				{
					printf("%c", HT->firstnode[p[n]].data);
					fprintf(fp,"%c", HT->firstnode[p[n]].data);
				}
			}
			n++;
			if(j == temp - 1)
			{
				printf("\n");
				fprintf(fp,"\n");
			}
			else
			{
				for(k = 0;k < chengfang(2,HT->depth-i+1)-1;k++)
				{
					printf(" ");
					fprintf(fp," ");
				}
			}
		}
		if(i < HT->depth)
		{
			temp = chengfang(2,HT->depth-i-1)-1;
			for(j = 0;j < temp;j++)
			{
				printf(" ");
				fprintf(fp," ");
			}
			temp = chengfang(2,i-1);
			for(j = 0;j < temp;j++)
			{
				if(p[2*m+1] == -1 && p[2*m+2] == -1)
				{
					for(k = 0;k < chengfang(2,HT->depth-i)+1;k++)
					{
						printf(" ");
						fprintf(fp," ");
					}
				}
				else
				{
					for(k = 0;k < chengfang(2,HT->depth-i-1);k++)
					{
						printf("_");
						fprintf(fp,"_");
					}
					printf("|");
					fprintf(fp,"|");
					for(k = 0;k < chengfang(2,HT->depth-i-1);k++)
					{
						printf("_");
						fprintf(fp,"_");
					}	
				}
				m++;
				if(j == temp - 1)
				{
					printf("\n");
					fprintf(fp,"\n");
				}
				else
				{
					for(k = 0;k < chengfang(2,HT->depth-i)-1;k++)
					{
						printf(" ");
						fprintf(fp," ");
					}
				}
			}	
		}
		
	}
	free(p);
	free(q);
	if(fclose(fp))
	{
		printf("文件关闭失败！\n");
		exit(0);
	} 
}

int chengfang(int n,int m)
{
	int i;
	int s = 1;
	for(i = 0;i < m;i++)
	s = s * n;
	return s;
} 
