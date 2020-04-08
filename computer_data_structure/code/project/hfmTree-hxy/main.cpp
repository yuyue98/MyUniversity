#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

//*****赫夫曼树和赫夫曼编码的存储表示*****
typedef struct{
    char ch;                   //关联字符信息
    unsigned int weight;       //每个节点的权值
    unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;      //存储哈夫曼编码

HuffmanTree HT;//存储哈夫曼树
HuffmanCode HC;//存储哈夫曼编码

int n=0;  //字符个数
int *w;   //权值
char *ch; //字符信息

//*****主要函数定义*****
void Menu();    //主菜单界面

void Select(HuffmanTree HT,int j,int &s1,int &s2); //选择parent为0且weight最小的两个结点
void HuffmanCoding(HuffmanTree&HT,HuffmanCode &HC,int *w,int n,char *ch);
// 算法6.12
// w存放n个字符的权值(均>0)，构造哈夫曼树HT，
// 并求出n个字符的哈夫曼编码HC
void Initialization(); //1.输入字符及其权值，建立哈夫曼树
void Encoding();       //2.编码
void Decoding();       //3.译码
void Print();          //4.打印代码
void Tree_printing();  //5.打印哈夫曼树
void Free();           //6.释放空间

void Menu()
{
	printf("———————————————————\n");
	printf("|         请选择如下操作：           |\n");
	printf("|            1.初始化                |\n");
	printf("|            2.编码                  |\n");
	printf("|            3.译码                  |\n");
	printf("|            4.打印代码文件          |\n");
	printf("|            5.打印哈夫曼树          |\n");
	printf("|            6.退出                  |\n");
	printf("———————————————————\n");
}

void Select(HuffmanTree HT,int j,int &s1,int &s2)//选择parent为0且weight最小的两个结点
{
	int i;
	for(i=1;i<=j;i++)
		if(HT[i].parent==0){s1=i;break;}
	for (;i<=j;i++)
   		if ((HT[i].parent==0)&&(HT[i].weight<HT[s1].weight))
    		s1=i;
  	HT[s1].parent=1;
	for(i=1;i<=j;i++)
   		if(HT[i].parent==0){s2=i;break;}
	for(;i<=j;i++)
   		if((HT[i].parent==0)&&(i!=s1)&&(HT[i].weight<HT[s2].weight))
    		s2=i;
}

void HuffmanCoding(HuffmanTree&HT,HuffmanCode &HC,int *w,int n,char *ch)//构造哈夫曼树HT、HC
{
	int m;
	m=2*n-1;//图的节点数
	int j,s1,s2,k;
	HT=(HTNode *)malloc((m+1)*sizeof(HTNode));
	HTNode *p;
	int i;
	for(p=HT+1,i=1;i<=n;++p,++i,++w,++ch){
		p->ch=*ch;
		p->weight=*w;
		p->parent=p->lchild=p->rchild=0;
	}
	for(;i<=m;++i,++p){
		p->ch=0;
		p->weight=0;
		p->parent=p->lchild=p->rchild=0;
	}//HT粗态建立结束
	for(i=n+1;i<=m;++i){
		Select(HT,i-1,s1,s2);
		HT[s1].parent=i;HT[s2].parent=i;
		HT[i].lchild=s1;HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}//HT末态建立结束
	HC=(char**)malloc((n+1)*sizeof(char*));
	char *cd;
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	int start,c,f;
	for(i=1;i<=n;++i){
		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent){
			if(HT[f].lchild==c) cd[--start]='0';
			else cd[--start]='1';
		}
		HC[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}

void Initialization()//1.输入字符及其权值，建立哈夫曼树
{
	FILE *fp;//定义文件指针
	int i;
	printf("请输入字符个数:\n");
	scanf("%d",&n);
	while(n<2){
		printf("输入的数据有误，请重新输入:\n");
		scanf("%d",&n);
	}
	ch=(char *)malloc(n*sizeof(char));
	printf("请输入所有字符:\n");
	getchar();
	for(i=0;i<n;++i)
		scanf("%c",&ch[i]);
	w=(int *)malloc(n*sizeof(int));
	printf("请输入这些字符的权值，用空格分开:\n");
	for(i=0;i<n;++i)
		scanf("%d",&w[i]);
	HuffmanCoding(HT,HC,w,n,ch);
	fp=fopen("hfmTree.txt","w");
	fprintf(fp,"个数：%d",n);
	fprintf(fp,"\n字符:");
	for(i=0;i<n;++i)
		fprintf(fp,"%5c",ch[i]);
    fprintf(fp,"\n权值:");
	for(i=0;i<n;++i)
		fprintf(fp,"%5d",w[i]);
	for(i=1;i<=n;++i)
		fprintf(fp,"\n%c:%s",HT[i].ch,HC[i]);
	fclose(fp);
	printf("初始化成功\n");
}

void Encoding()//2.编码
{
	FILE *fp,*fp1;
	int i;
	char in;
	if(n==0)
	{
		fp=fopen("hfmTree.txt","r");
		fscanf(fp,"%d",&n);
		if(feof(fp)){
			printf("请先初始化哈夫曼树！\n");
		}
		ch=(char *)malloc(n*sizeof(char));
		for(i=0;i<n;++i)
			fscanf(fp,"%c",&ch[i]);
		w=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;++i)
			fscanf(fp,"%d",&w[i]);
		HuffmanCoding(HT,HC,w,n,ch);
		printf("已载入哈夫曼树！\n");
		fclose(fp);
	}
	fp=fopen("ToBeTran.txt","r");
	printf("成功读取ToBeTran.txt\n");
	fp1=fopen("CodeFile.txt","w");
	fscanf(fp,"%c",&in);
	while(!feof(fp))
	{
		for(i=1;i<=n;++i){
		if(HT[i].ch==in)
				break;
		}

		fprintf(fp1,"%s",HC[i]);
		fscanf(fp,"%c",&in);
	}
	printf("\n编码结束，结果已存入CodeFile.txt文件中！\n");
	fclose(fp);
	fclose(fp1);
}

void Decoding()//3.译码
{
	FILE *fp,*fp1;
	int i,m;
	char in;
		if(n==0)
	{
		fp=fopen("hfmTree.txt","r");
		fscanf(fp,"%d",&n);
		if(feof(fp)){
			printf("请先初始化哈夫曼树！\n");
		}
		ch=(char *)malloc(n*sizeof(char));
		for(i=0;i<n;++i)
			fscanf(fp,"%c",&ch[i]);
		w=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;++i)
			fscanf(fp,"%d",&w[i]);
		HuffmanCoding(HT,HC,w,n,ch);
		printf("已载入哈夫曼树！\n");
		fclose(fp);
	}
	fp=fopen("CodeFile.txt","r");
	fp1=fopen("TextFile.txt","w");
	for(i=1;HT[i].parent!=0;++i);
	m=i;
	while(!feof(fp)){
	if(HT[m].lchild && HT[m].rchild){
		fscanf(fp,"%c",&in);
		if(in=='0') m=HT[m].lchild;
		else m=HT[m].rchild;
		}
	else{
		fprintf(fp1,"%c",HT[m].ch);
		m=i;
		}
	}
		printf("\n译码结束，译码结果已保存到TextFile.txt文件中！\n");
		fclose(fp);
		fclose(fp1);
}
void Print()//4.打印代码
{
	FILE *fp,*fp1;
	int i=0;
	char in;
	printf("代码文件为:\n");
	fp=fopen("CodeFile.txt","r");
	fp1=fopen("CodePrin.txt","w");
	fscanf(fp,"%c",&in);
	while(!feof(fp))
	{
		printf("%c",in);
		fprintf(fp1,"%c",in);
			i++;
		if(i==50){
			printf("\n");
			fprintf(fp1,"\n");
			i=0;
		}
		fscanf(fp,"%c",&in);
	}
	printf("\n");
	fclose(fp);
	fclose(fp1);
	printf("代码文件已存入CodePrin.txt文件中");
	printf("\n");
}


void Tree_printing()//5.打印哈夫曼树
{
	FILE *fp;
	fp=fopen("TreePrint.txt","w");//以表格形式读入
	int i;
	for(i=1;i<=2*n-1;i++){
		printf("%c%8d%8d%8d%8d\n",HT[i].ch,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
		fprintf(fp,"%c%8d%8d%8d%8d",HT[i].ch,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
		fprintf(fp,"\n");
	}
	fclose(fp);
	printf("哈夫曼树已存入TreePrint.txt\n");
}

void Free()//6.释放空间
{
	free(HT);
	free(HC);
	free(w);
	free(ch);
}

int main()
{
	char choice;
	while(1)
	{
	   Menu();
	   scanf("%d",&choice);
	   switch(choice)
	   {
		case 1:Initialization();break;
		case 2:Encoding();break;
		case 3:Decoding();break;
		case 4:Print();break;
		case 5:Tree_printing();break;
		case 6:Free();exit(1);
		default :printf("Input error!\n");
	   }
		getchar();
	}
return 0;
}
