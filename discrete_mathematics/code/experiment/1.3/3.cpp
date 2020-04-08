#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int A, B, C, D, E;
	A = B = C = D = E = 1;
	if ((A||B) && (!A||C) && (!D||E) && (D||!C) && !E)
		printf("营业员A偷了手表！\n");
	else 
		printf("营业员B偷了手表！\n");
   system("pause");
	return 0;
}