#ifndef ECTREE_H
#define ECTREE_H

typedef struct ecnode
{
	char data;
	struct ecnode *lchild, *rchild;
}ecnode, *ectree;

typedef struct lqnode
{
	ectree base[MAX];
	int front, rear;
}lqnode, *squeue;

int inittree(ectree T);//初始化二叉树
int inputtree(ectree T);//建立二叉树
int heighttree(ectree T);//树的高度 
int blqianxu(ectree T);//前序遍历 
int blzhongxu(ectree T);//中序遍历 
int blhouxu(ectree T);//后序遍历 
squeue initqueue();//初始化队列
int emptyqueue(squeue Q);//判断队列是否为空
int enqueue(squeue Q,ectree T);//入队列
int outqueue(squeue Q,ectree *T);//出队列
ectree gethead(squeue Q);//取队列首元素
int blqueue(ectree T);//队列遍历 
int destroytree(ectree T);//销毁二叉树

#endif