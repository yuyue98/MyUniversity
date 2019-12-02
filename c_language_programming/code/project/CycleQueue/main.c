#include "myheader.h"
#include "cyclequeue.h"

int main(int argc, char* argv[]) {
    /**
     * The c language project main program
     */
    char a;
	squeue q;
	printf("是否建立一个循环队列（y/n）：");
	scanf("%c", &a);
	getchar();
	if (a == 'y' || a == 'Y')
	{	
	    initqueue(&q);
		menu(q);
	}
	else
	    exit(OVERFLOW);  
    system("pause");
	return OK;
}