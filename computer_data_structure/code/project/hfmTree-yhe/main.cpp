#include "head.h"

int main()
{
	char ch = '0', p, t[MAX];
	hfmtree *HT = NULL;
	HT = (hfmtree*)malloc(sizeof(hfmtree));
	//申请哈夫曼树地址HT 
	if(!HT)
	{
		printf("内存申请失败！\n");
		exit(0);
	}
	HT->length = HT->number = HT->depth = 0;
	HT->firstnode = NULL;
	HT->list = NULL;
	while (ch == '0')
	{
	    first_menu();
    	ch = getchar();
    	p = getchar();
    	if(p != '\n')
    	gets(t);
		//system("cls");
		switch(ch)
		{
			case '1':system("cls");init_hfmtree(HT);break;
			case '2':system("cls");save_hfmtree(HT);break;
			case '3':system("cls");load_hfmtree(HT);break;
			case '4':system("cls");save_codefile(HT);break;
			case '5':system("cls");load_codefile(HT);break;
			case '6':system("cls");dayin_hfmcode(HT);break;
			case '7':system("cls");dayin_hfmtree(HT);break;
			case '8':system("cls");free_hfmtree(HT);exit(0);
			default:system("cls");printf("选项不存在请重新输入！\n");
		} 
		ch = '0';
	}
		
	return OK;
}

void first_menu()//主菜单
{
	//system("cls");
	printf("******赫夫曼编码\\译码器主菜单******\n");
	printf("\t1、初始化赫夫曼树\n");
	printf("\t2、保存赫夫曼树\n");
	printf("\t3、读取赫夫曼树\n");
	printf("\t4、赫夫曼编码\n");
	printf("\t5、赫夫曼译码\n");
	printf("\t6、打印代码文件\n"); 
	printf("\t7、打印赫夫曼树\n");
	printf("\t8、退出\n");
	printf("请输入选项前的序号：");
}
