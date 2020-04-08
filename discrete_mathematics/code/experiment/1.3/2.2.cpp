#include<stdio.h>
#include<stdlib.h>
int vote(int a,int b,int c,int d,int e)
{
	// 五人中任取三人的不同的取法有10种。
	// 补充代码
	if((a&&b&&c)||(a&&b&&d)||(a&&b&&e)||(a&&c&&d)||(a&&c&&e)||(b&&c&&d)||(b&&c&&e)||(c&&d&&e)||(b&&d&&e)||(a&&d&&e)) 
		return 1;
	else 
		return 0;
}
	
int main()
{
	int a,b,c,d,e;
	printf("请输入五个人的表决值（0或1，空格分开）：");
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	if(vote(a,b,c,d,e)) 	
		printf("很好，表决通过！\n");
	else
		printf("遗憾，表决没有通过！\n");
	system("pause");
	return 0;
}
//注：联结词不定义成函数，否则太繁
