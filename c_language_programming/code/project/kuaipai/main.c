#include "myheader.h"
#include "kuaipai.h"

int main(int argc, char* argv[]) {
    /**
     * The c language project main program
     */

	FILE *fp;
	cjlist *S;
    int i;
    char ch;S = (cjlist*)malloc(sizeof(cjlist));
    if(!S)
    {
        printf("内存申请失败！\n");
        exit(0);
    }
    if((fp = fopen("chenji.txt","w")) == NULL)
    {
    	printf("文件打开失败！\n");
    	exit(0);
    }
    init_cjlist(S);
    dg_kuaipai(S,1,S->length,paixu_cj);
    for(i = 1;i < (S->length)+1;i++)
   	S->student[i].number = i; 
	loop:printf("1、按成绩排序\n2、按学号排序\n");
	printf("请输入排序方式前的数字："); 
	ch = getchar();
	getchar();
	if(ch == '1')
	{
		dg_kuaipai(S,1,S->length,paixu_cj);
    	for(i = 1;i < (S->length)+1;i++)
   		S->student[i].number = i;
		printf("按成绩排，学生成绩表如下：\n");
	    printf("名次\t学号\t姓名\t成绩\n"); 
	    for(i = 1;i < (S->length)+1;i++)
		printf("%d\t%s\t%s\t%d\n", S->student[i].number, (S->student)[i].xuehao, (S->student)[i].xingming, (S->student)[i].chengji);
	}
	else if(ch == '2')
	{
		dg_kuaipai(S,1,S->length,paixu_xh);
		printf("按学号排，学生成绩表如下：\n");
	    printf("学号\t名次\t姓名\t成绩\n"); 
	    for(i = 1;i < (S->length)+1;i++)
		printf("%s\t%d\t%s\t%d\n", (S->student)[i].xuehao, S->student[i].number, (S->student)[i].xingming, (S->student)[i].chengji);
	}
	if(ch != '0')
	goto loop;
    return OK;
}