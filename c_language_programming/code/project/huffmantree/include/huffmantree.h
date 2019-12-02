#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

//储存结构定义 
typedef struct htnode
{
	char data;
	unsigned int weight;
	unsigned int parent, lchild, rchild;
	unsigned int depth;
}htnode;//定义哈夫曼树的主体储存结构 

typedef char** hfmlist;//定义编码表储存结构 

typedef struct hfmtree
{
	unsigned int length;
	unsigned int number;
	unsigned int depth;
	htnode *firstnode;
	hfmlist list;
}hfmtree;//定义哈夫曼树储存结构 

typedef struct quanma
{
	char ma;
	unsigned int quan;
}quanma;//定义权码表储存结构 

//函数声明 
void first_menu();//主菜单 
void init_hfmtree(hfmtree *HT);//初始化哈夫曼树 
void free_hfmtree(hfmtree *HT);//删除哈夫曼树 
void init_body(hfmtree *HT,quanma *qm);//初始化树的主体 
void free_body(hfmtree *HT);//删除树的主体 
void init_list(hfmtree *HT);//初始化编码表 
void free_list(hfmtree *HT);//删除编码表 
void select1(htnode *T,int n,int *s1,int *s2);
//在T[0,n]中选择weight最小的两个结点是s1，s2 
void change(int *a,int *b);//交换两个整型变量 
void save_hfmtree(hfmtree *HT);//储存哈夫曼树 
void load_hfmtree(hfmtree *HT);//读取哈夫曼树
void save_codefile(hfmtree *HT);//保存文件编码 
void load_codefile(hfmtree *HT);//读取文件编码
void dayin_hfmcode(hfmtree *HT);//打印文件编码 
void dayin_hfmtree(hfmtree *HT);//打印哈夫曼树 
int chengfang(int n,int m);//计算n的m次方 

#endif