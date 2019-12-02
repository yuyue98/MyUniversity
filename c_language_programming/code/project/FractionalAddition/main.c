#include "myheader.h"
#include "FractionalAddition.h"

int main(int argc, char* argv[]) {
    /**
     * The c language project main program
     */
    fenshu L;
	char a;
	int c;
	printf("是否建立链表(y/n):");
	scanf("%c", &a);
	getchar();
	if(a =='y' || a == 'Y')
	{
		system("cls");
		L = initlist(L);
		c = getlist(L);
		printf("相加分数个数为：%d\n", c);
		fracadd(L,c);
	} else exit(OVERFLOW);
    system("pause");
	return OK;
}