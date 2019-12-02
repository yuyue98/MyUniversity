#include "myheader.h"
#include "kuaipai.h"

void init_cjlist(cjlist *S)
{
    int i;
    int n;
    printf("请输入要录入学生人数n：");
    scanf("%d", &n);
    getchar();
    S->length = n;
    S->student = (cjnode*)malloc((n+1)*sizeof(cjnode));
    if(!(S->student))
    {
        printf("内存申请失败！\n");
        exit(0);
    }
    for(i = 1;i < n+1;i++)
    {
        printf("第%d个学生的学号、姓名、成绩为（中间以空格隔开）：", i);
        scanf("%s %s %d", &(S->student)[i].xuehao, &(S->student)[i].xingming, &(S->student)[i].chengji);
        getchar();
        (S->student)[i].number = 0;
    }
}

void dg_kuaipai(cjlist *S, int low, int high, int (*paixu)(cjlist*,int,int))
{
	int n;
	if(low < high)
	{
		n = paixu(S,low,high);
		dg_kuaipai(S,low,n-1,paixu);
		dg_kuaipai(S,n+1,high,paixu);
	}
}

int paixu_cj(cjlist *S, int low, int high)
{
	//int i;
	//static int tang = 0;
	S->student[0] = S->student[low];
	while(low < high)
	{
		while(low < high && S->student[0].chengji >= S->student[high].chengji)
		high--;
		S->student[low] = S->student[high];
		while(low < high && S->student[0].chengji <= S->student[low].chengji)
		low++;
		S->student[high] = S->student[low];
	}
	S->student[low] = S->student[0];
	/*tang++;
	printf("第%d趟排序结果如下：\n", tang);
    printf("学号\t姓名\t成绩\n"); 
	for(i = 1;i < (S->length)+1;i++)
    {
        printf("%s\t%s\t%d\n", (S->student)[i].xuehao, (S->student)[i].xingming, (S->student)[i].chengji);
    }*/
	return low;
}

int paixu_xh(cjlist *S, int low, int high)
{
	//int i;
	//static int tang = 0;
	S->student[0] = S->student[low];
	while(low < high)
	{
		while(low < high && strcmp(S->student[0].xuehao,S->student[high].xuehao) <= 0)
		high--;
		S->student[low] = S->student[high];
		while(low < high && strcmp(S->student[0].xuehao,S->student[low].xuehao) >= 0)
		low++;
		S->student[high] = S->student[low];
	}
	S->student[low] = S->student[0];
	/*tang++;
	printf("第%d趟排序结果如下：\n", tang);
    printf("学号\t姓名\t成绩\n"); 
	for(i = 1;i < (S->length)+1;i++)
    {
        printf("%s\t%s\t%d\n", (S->student)[i].xuehao, (S->student)[i].xingming, (S->student)[i].chengji);
    }*/
	return low;
}