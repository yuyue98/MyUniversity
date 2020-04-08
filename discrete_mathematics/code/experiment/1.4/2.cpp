#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define MAX 50

int main()
{
	int i, j, k;
	int r[MAX][MAX];
	int flag = 1;
	int n = 0;
	scanf("%d",&n);
	for(i=1;i<=n && flag;i++)
	{
		int sum=0;
		for(j=1;j<=n;j++)
			if(r[i][j]) sum++;
		if (sum%2!=0) flag = 0;
			
	}
	if (flag)
		printf("无向图r是欧拉图");
	flag = 1;
	for(i=1;i<=n && flag;i++)
	{
		int sum1=0;
		int sum2=0;
		for(j=1;j<=n;j++)
			if(r[i][j]) sum1++;
		for(j=1;j<=n;j++)
			if(r[j][i]) sum2++;
		if (sum1 != sum2) flag = 0;
	}
	system("pause");
	return 0;
} 