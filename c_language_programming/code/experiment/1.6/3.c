#include<stdio.h>
#include<math.h>
#include<malloc.h>
#define OVERFLOW 3

int main()
{
	int n;
	int i, j;
	int *p;
	printf("请输入圈中人数初始值n：");
	while(scanf("%d", &n) != EOF)
	{
		int a, b, c = n;
		int m = 0;
		p = (int*)malloc(n*sizeof(int));
		if(!p)
		{
			printf("Malloc failed!\n");
			exit(OVERFLOW);
		}
		for(i = 0;i < n;i++)
		p[i] = i + 1;
		printf("出圈顺序为："); 
		while(c > 2)
		{
			a = c / 3;
			b = 3 - c % 3;
			c = c - a;
			for(i = 0;i < n;i++)
			{
				if(p[i] != 0)
				{
					m++;
					if(m % 3 == 0)
					{
						printf("%d ", p[i]);
						p[i] = 0;
					}
				}
			}
		   //printf("\nm = %d\n", m);
			m = (m - 3 * a) ;
		}
		//printf("\nm = %d\n", m);
		if(m % 2 == 0)
		for(i = 0;i < n;i++)
		{
			if(p[i] != 0)
			{
				printf("%d ", p[i]);
				p[i] = 0;
			}
		}
		else if(m % 2 == 1)
		for(i = n - 1;i > -1;i--)
		{
			if(p[i] != 0)
			{
				printf("%d ", p[i]);
				p[i] = 0;
			}
		}
		/*printf("\n");
		for(i = 0;i < n;i++)
		printf("%d ", p[i]);*/
		free(p);
		printf("\n请输入圈中人数初始值n：");
	}
	return 0;
}
