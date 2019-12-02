#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	for(i = 1000;i <= 1100;i++)
	{
		if((i % 3 == 2) && (i % 5 == 3) && (i % 7 == 2))
		printf("韩信宣布勇士数有：%d\n", i);
	}
	return 0;
}
