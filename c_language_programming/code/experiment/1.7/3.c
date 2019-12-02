#include <stdio.h>

int main(int argc, char *argv[])
{
	int chengji[30];
	int n;
	int i, j;
	printf("请输入参加选拔的学生人数n：");
	while(scanf("%d", &n) != EOF)
	{
		printf("请分别输入这%d个学生的成绩：", n);
		for(i = 0;i < n;i++)
		scanf("%d", &chengji[i]);
		for(i = 0;i < n-1;i++)
		{
			for(j = i+1;j < n;j++)
			{
				if(chengji[i] < chengji[j])
				chengji[i]^=chengji[j]^=chengji[i]^=chengji[j];
			}
		}
		printf("成绩排序后输出为：");
		for(i = 0;i < n-1;i++)
		printf("%d ", chengji[i]);
		printf("%d\n", chengji[n-1]);
		printf("请输入参加选拔的人数n：");
	} 
	return 0;
}
