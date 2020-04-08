#include "head.h"

void save_hfmtree(hfmtree *HT)//储存哈夫曼树
{
	int i;
	htnode *T;
	T = HT->firstnode; 
	if(HT->length == 0 && HT->number == 0 && HT->firstnode == NULL && HT->list == NULL)
	printf("内存中不存在哈夫曼树，请初始化哈夫曼树！\n");
	else
	{
		FILE *fp;
		char ch = '0', p, t[MAX]; 
		if((fp = fopen("hfmTree.txt","r")) == NULL)
		{
			fp = fopen("hfmTree.txt","w");
			fprintf(fp,"length=%d,number=%d,depth=%d\n", HT->length, HT->number, HT->depth);
			fprintf(fp,"hfmtree中内容如下：\n");
			fprintf(fp,"序号\t字符\t权值\t父亲\t左孩子\t右孩子\t深度\n");
			for(i = 0;i < HT->number;i++)
			fprintf(fp,"%d\t%c\t%d\t%d\t%d\t%d\t%d\n", i, T[i].data, T[i].weight, T[i].parent, T[i].lchild, T[i].rchild, T[i].depth); 
			fprintf(fp,"hfmlist中内容如下：\n");
			fprintf(fp,"序号\t字符\t编码\n");
			for(i = 0;i < HT->length;i++)
			fprintf(fp,"%d\t%c\t%s\n", i, T[i].data, HT->list[i]);
			if(fclose(fp))
			{
				printf("文件关闭失败！\n");
				exit(0);
			}
			printf("save_hfmtree successed!\n");
		}
		else
		{
			if(fclose(fp))
			{
				printf("文件关闭失败！\n");
				exit(0);
			}
			printf("已存在文件hfmTree.txt,是否覆盖（y/n）：");
			while(ch == '0')
			{
				ch = getchar();
				p = getchar();
				if(ch == 'y' || ch == 'Y')
				{
					printf("cover start!\n");
					fp = fopen("hfmTree.txt","w");
					fprintf(fp,"length=%d,number=%d,depth=%d\n", HT->length, HT->number, HT->depth);
					fprintf(fp,"hfmtree中内容如下：\n");
					fprintf(fp,"序号\t字符\t权值\t父亲\t左孩子\t右孩子\t深度\n");
					for(i = 0;i < HT->number;i++)
					fprintf(fp,"%d\t%c\t%d\t%d\t%d\t%d\t%d\n", i, T[i].data, T[i].weight, T[i].parent, T[i].lchild, T[i].rchild, T[i].depth); 
					fprintf(fp,"hfmlist中内容如下：\n");
					fprintf(fp,"序号\t字符\t编码\n");
					for(i = 0;i < HT->length;i++)
					fprintf(fp,"%d\t%c\t%s\n", i, T[i].data, HT->list[i]); 
					if(fclose(fp))
					{
						printf("文件关闭失败！\n");
						exit(0);
					}
					ch == '1';
					printf("cover end\n");
				}
				else if(ch == 'n' || ch == 'N')
				ch == '1';
				else
				{
					printf("该输入不合法，请重新输入：");
					if(p != '\n')
					gets(t); 
					ch = '0';
				}//End else
			}//End while
		}//End else
	}//End else
}

void load_hfmtree(hfmtree *HT)//读取哈夫曼树
{
	int i, j;
	char data, str[100]; 
	FILE *fp;
	htnode *T;
	if(HT->length == 0 && HT->number == 0 && HT->firstnode == NULL && HT->list == NULL)
	{
		if((fp = fopen("hfmtree.txt","r")) == NULL)
		printf("文件hfmtree.txt不存在！\n");
		else
		{
			fscanf(fp,"length=%d,number=%d,depth=%d\n", &HT->length, &HT->number, &HT->depth);
			HT->firstnode = (htnode*)malloc((HT->number)*sizeof(htnode));
			//申请树的主体首地址HT->firstnode
			if(!(HT->firstnode))
			{
				printf("内存申请失败！\n");
				exit(0);
			}
			T = HT->firstnode;
			fgets(str,100,fp);
			fgets(str,100,fp);
			for(i = 0;i < HT->number;i++)
			{
				if(i < 10)
				fgets(str,3,fp);
				else if(i < 100)
				fgets(str,4,fp);
				T[i].data = fgetc(fp);
				fgetc(fp);
				fscanf(fp,"%d", &T[i].weight);
				fgetc(fp);
				fscanf(fp,"%d", &T[i].parent);
				fgetc(fp);
				fscanf(fp,"%d", &T[i].lchild);
				fgetc(fp);
				fscanf(fp,"%d", &T[i].rchild);
				fgetc(fp);
				fscanf(fp,"%d", &T[i].depth);
				fgets(str,2,fp);
			}
			init_list(HT); 
			printf("load_hfmtree successed!\n");
			if(fclose(fp))
			{
				printf("文件关闭失败！\n");
				exit(0);
			}		
		}
	}
	else
	{
		char ch = '0', p, t[MAX];
		printf("内存中已存在哈夫曼树，是否覆盖（y/n）：");
		while(ch == '0')
		{
			ch = getchar();
			p = getchar();
			if(ch == 'y' || ch == 'Y')
			{
				if((fp = fopen("hfmtree.txt","r")) == NULL)
				printf("文件hfmtree.txt不存在！\n");
				else
				{
					printf("cover start!\n");
					fscanf(fp,"length=%d,number=%d,depth=%d\n", &HT->length, &HT->number, &HT->depth);
					HT->firstnode = (htnode*)malloc((HT->number)*sizeof(htnode));
					//申请树的主体首地址HT->firstnode
					if(!(HT->firstnode))
					{
						printf("内存申请失败！\n");
						exit(0);
					}
					T = HT->firstnode;
					fgets(str,100,fp);
					fgets(str,100,fp);
					for(i = 0;i < HT->number;i++)
					{
						fgets(str,3,fp);
						T[i].data = fgetc(fp);
						fgetc(fp);
						fscanf(fp,"%d", &T[i].weight);
						fgetc(fp);
						fscanf(fp,"%d", &T[i].parent);
						fgetc(fp);
						fscanf(fp,"%d", &T[i].lchild);
						fgetc(fp);
						fscanf(fp,"%d", &T[i].rchild);
						fgetc(fp);
						fscanf(fp,"%d", &T[i].depth);
						fgets(str,2,fp);
					}
					init_list(HT); 
					printf("load_hfmtree successed!\n");
					if(fclose(fp))
					{
						printf("文件关闭失败！\n");
						exit(0);
					}
					printf("cover end\n");	
				}
				ch == '1';
			}
			else if(ch == 'n' || ch == 'N')
			ch == '1';
			else
			{
				printf("该输入不合法，请重新输入：");
				if(p != '\n')
				gets(t); 
				ch = '0';
			}
		}
	}
} 
