#include "myheader.h"
#include "ectree.h"

int number = 0;

int main(int argc, char* argv[]) {
    /**
     * The c language project main program
     */
    ectree T;
	T = (ectree)malloc(sizeof(struct ecnode));
	if(!T)
	{
		printf("Malloc memery failed!\n");
		exit(OVERFLOW);
	}
	inittree(T);
	inputtree(T);
	printf("二叉树中元素有%d个!\n", number);
	printf("二叉树的高度为：%d\n", heighttree(T)); 
	printf("前序遍历如下：\n");
	blqianxu(T);
	printf("\n中序遍历如下：\n");
	blzhongxu(T);
	printf("\n后序遍历如下：\n");
	blhouxu(T);
	printf("\n层次遍历如下：\n");
	blqueue(T); 
	printf("\ndestroy state!\n");
	destroytree(T);
	printf("destroy end!\n");
    system("pause");
	return OK;
}