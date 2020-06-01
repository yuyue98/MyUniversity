#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

void swap(int m, int n)
{
	int t;
	t = m;
	m = n;
	n = t;
}

void gengxindu(int **s, int *am, int *an, int m, int n)
{
}

int main()
{
	int m;//shao
	int n;//duo
	int *am, *an, **s;
	int i, j, k;
	while (1)
	{
		printf("please input the m and n:");
		scanf("%d",  &m);
		getchar();
		scanf("%d",  &n);
		getchar();
		if (m < n)
		//jiaohuan
		swap(m,n);
		am = (int *)malloc(m * sizeof(int));
		an = (int *)malloc(n * sizeof(int));
		s = (int **)malloc(m * sizeof(int *));
		for (i = 0;i < m;i++)
			s[i] = (int *)malloc(n * sizeof(int));
		for (i = 0;i < m;i++)
		    am[i] = 0;
		for (i = 0;i < n;i++)
		    an[i] = 0;
		for (i = 0;i < m;i++)
	        for (j = 0;j < n;j++)
	            s[i][j] = 0;
	    int a = 100, b;
	    printf("please input a&b(the 0 is end):\n");
	    while ((a = getchar())!= '0')
	    {
	    	a -= 48;
	    	getchar();
	    	scanf("%d", &b);
	    	getchar();
	    	s[a-1][b-1] = 1;
	    }
	    //gengxin am and sn
	    gengxindu(s,am,an,m,n);
	    //xianshi reason
	    printf("juzhen s is:\n");
	    for (i = 0;i < m;i++)
	    {
	        for (j = 0;j < n;j++)
	            printf("%d ", s[i][j]);
	        printf("\n");
	    }
	    printf("hangdu am is:\n");
	    for (i = 0;i < m;i++)
		    printf("%d ", am[i]);
		printf("\n");
		printf("liedu an is:\n");
		for (i = 0;i < n;i++)
		    printf("%d ", an[i]);
		printf("\n");
		free(am);
		free(an);
		for (i = 0;i < m;i++)
			free(s[i]);
		free(s);
	}
	return 0;
}