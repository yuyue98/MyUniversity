#include "myheader.h"
#include "arctu.h"

int main(int argc, char* argv[]) {
    /**
     * The c language project main program
     */
    algraph *G;
    G = (algraph*)malloc(sizeof(algraph));
    if(!G)
    {
        printf("内存申请失败！\n");
        exit(OVERFLOW);
    }
    initgraph(G);
    printf("生成的邻接表如下：\n");
	outputljlist(G);
	printf("深度优先遍历结果为：");
	dfstraverse(G);
	printf("广度优先遍历结果为：");
	bfstraverse(G); 
    system("pause");

    return 0;
}