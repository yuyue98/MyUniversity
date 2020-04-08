#include "head.h"

void init_hfmtree(hfmtree *HT)//初始化哈夫曼树
{
	char ch = '0', p, t[MAX];
	
	if(HT->length == 0 && HT->number == 0 && HT->firstnode == NULL && HT->list == NULL)
	//判断内存中是否存在哈夫曼树 
	{
		int i;
		printf("请输入编码字符个数：");
		while(1)  
	    {  
	        scanf("%d", &HT->length);
			p = getchar();  
	        if(HT->length > 0)  
         	break;  
	        else
			{
				if(p != '\n')
				gets(t);
				printf("输入错误，请重新输入n值！");
			}  
         	  
	    }
		HT->number = HT->length * 2 - 1;
		quanma *qm;
		qm = (quanma*)malloc((HT->length)*sizeof(quanma));
		//申请权码表地址qm 
		if(!qm)
		{
			printf("内存申请失败！\n");
			exit(0);
		}
		printf("请依次输入这%d个编码字符及其权值：\n", HT->length);
		printf("/*输入格式：码+权（例如A64），中间用空格隔开*/\n");
		for(i = 0;i < HT->length;i++)
		{
			scanf("%c%d", &qm[i].ma, &qm[i].quan);
			getchar();
		}
		/*printf("qm中内容显示如下：\n");
		for(i = 0;i < HT->length;i++)
		{
			printf("%c%d ", qm[i].ma, qm[i].quan);
		}
		printf("\n");*/
		//测试qm是否正确录入 
		init_body(HT,qm);
		init_list(HT);
		printf("Init_hfmtree successed!\n");
		free(qm);
	}
	else
	{
		printf("内存中已存在哈夫曼树,是否删除（y/n）：");
		while(ch == '0')
		{
			ch = getchar();
			p = getchar();
			if(ch == 'y' || ch == 'Y')
			{
				free_hfmtree(HT);
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

void free_hfmtree(hfmtree *HT)//删除哈夫曼树
{
	HT->length = HT->number = 0;
	free_body(HT);
	free_list(HT);
	printf("free_hfmtree successed!\n");
} 

void init_body(hfmtree *HT,quanma *qm)//初始化树的主体
{
	int i;
	HT->firstnode = (htnode*)malloc((HT->number)*sizeof(htnode));
	//申请树的主体首地址HT->firstnode 
	if(!(HT->firstnode))
	{
		printf("内存申请失败！\n");
		exit(0);
	}
	for(i = 0;i < HT->length;i++)
	{
		 HT->firstnode[i].data = qm[i].ma;
		 HT->firstnode[i].weight = qm[i].quan;
		 HT->firstnode[i].parent = HT->firstnode[i].lchild = HT->firstnode[i].rchild = HT->firstnode[i].depth = 0;
	}
	for(;i < HT->number;i++)
	{
		 HT->firstnode[i].data = '0';
		 HT->firstnode[i].weight = HT->firstnode[i].parent = HT->firstnode[i].lchild = HT->firstnode[i].rchild = HT->firstnode[i].depth = 0;
	}
	int s1, s2;
	for(i = HT->length;i < HT->number;i++)
	{
		select1(HT->firstnode,i-1,&s1,&s2);
		//printf("out:s1 = %d,s2 = %d\n", s1, s2);
		HT->firstnode[s1].parent = HT->firstnode[s2].parent = i;
		HT->firstnode[i].lchild = s1;
		HT->firstnode[i].rchild = s2;
		HT->firstnode[i].weight = HT->firstnode[s1].weight + HT->firstnode[s2].weight;
	}
	int temp, j;
	for(i = 0;i < HT->number;i++)
	{
		j = i;
		temp = 1;
		while(HT->firstnode[j].parent != 0)
		{
			j = HT->firstnode[j].parent;
			temp++;
		}
		HT->firstnode[i].depth = temp;
	}
	HT->depth = HT->firstnode[0].depth;
	for(i = 1;i < HT->length;i++)
	{
		if(HT->depth < HT->firstnode[i].depth)
		HT->depth = HT->firstnode[i].depth;
	}
	printf("init_tree successed!\n");
}

void free_body(hfmtree *HT)//删除树的主体
{
	free(HT->firstnode);
	HT->firstnode = NULL;
	printf("free_body successed!\n");
}

void init_list(hfmtree *HT)//初始化编码表
{
	char *str;
	htnode *T;
	int i, start, j, k;
	T = HT->firstnode; 
	str = (char*)malloc((HT->length)*sizeof(char));
	HT->list = (char**)malloc((HT->length)*sizeof(char*));
	//申请编码表首地址HT->list
	if(!(HT->list) || !str)
	{
		printf("内存申请失败！\n");
		exit(0);
	}
	str[HT->length-1] = '\0';
	for(i = 0;i < HT->length;i++)
	{
		start = HT->length - 1;
		for(j = i,k = T[i].parent;k != 0;j = k,k = T[k].parent)
		{
			start--;
			if(T[k].lchild == j)	
			str[start] = '0';
			else
			str[start] = '1';
		}
		HT->list[i] = (char*)malloc((HT->length-start)*sizeof(char));
		if(!(HT->list[i]))
		{
			printf("内存申请失败！\n");
			exit(0);
		}
		strcpy(HT->list[i],&str[start]);
	}
	free(str);
	printf("init_list successed!\n"); 
}

void free_list(hfmtree *HT)//删除编码表
{
	int i;
	for(i = 0;i < HT->length;i++)
	free(HT->list[i]);
	free(HT->list);
	HT->list = NULL;
	printf("free_list successed!\n");
}

void select1(htnode *T,int n,int *s1,int *s2)
//在T[0,n]中选择weight最小的两个结点是s1，s2
{
	int i;
	for(i = 0;i <= n;i++)
	{
   		if(T[i].parent == 0)	
	   	break;
	}
   	*s1 = i;
 	i++;
   	for(;i <= n;i++)
	{
		if(T[i].parent == 0)
   		break;
	}
	*s2 = i;
   	if(T[*s1].weight > T[*s2].weight)
	change(s1,s2);
	for(;i <= n;i++)
	{
		if(T[i].parent != 0)
		continue;
		if(T[i].parent == 0 && T[i].weight < T[*s1].weight)
		{
			*s2 = *s1;
			*s1 = i;
		}
		if(T[i].parent == 0 && i != *s1 && T[i].weight >= T[*s1].weight && T[i].weight < T[*s2].weight)
		*s2 = i;
	}
	//printf("in:%d  s1 = %d,s2 = %d\n", n, *s1, *s2);
}

void change(int *a,int *b)//交换两个整型变量
{
	*a ^= *b ^= *a ^= *b;
}
