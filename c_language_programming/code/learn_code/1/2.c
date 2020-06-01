#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int i;
    // if (argc != 2)
	// {
	// 	printf("You forgot to type your name.\n");
	// 	exit(1);
	// }
	i = i + 1;
	for (i = 0;i < argc;i++)
	    printf("Hello %s\n", argv[i]);
	return 0;
}