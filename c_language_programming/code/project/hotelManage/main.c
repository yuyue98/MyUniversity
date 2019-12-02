#include "myheader.h"
#include "hotelManage.h"

int allmoney;

int main(int argc, char* argv[]) {
    /**
     * The c language project main program
     */
	char a;	
	printf("是否需要初始化酒店信息(y/n):");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	endry();
	else if(a == 'n' || a == 'N')
	menu1();
    system("pause");
    return 0;
}