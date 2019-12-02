#include<stdio.h>
int move(int *p, int n, int m);
int main()
{
	int *p;
	int n, m;
	int i, c;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		c = 0;
		p = (int *)malloc(sizeof(int)*n);
		for (i = 0; i < n; i++)
		scanf("%d", p+i);
		move(p,n,m);
		for (i = 0; i < n; i++)
		if (c == 0)
		{
			printf("%d",*(p+i));
			c = 1;
		}
		else
		printf(" %d", *(p+i));
		printf("\n");
		free(p);
	}
	return 0;
}
int move(int *p, int n, int m)
{
	int t, i;
	t = *(p+n-1);
	if (m > 0)
	{
		for (i = n - 1; i >= 0; i--)
		{
			*(p+i+1)=*(p+i);
		}
		*p = t;
        m--;
	    move(p,n,m);
	}
}