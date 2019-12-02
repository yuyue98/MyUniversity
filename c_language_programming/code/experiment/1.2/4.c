#include<stdio.h>
#include<math.h>
int jiecheng(int n);
int main()
{
	int s = 0; 
	int n; 
	int i;
	printf("请输入正整数n：");
	scanf("%d", &n);
	if (n<0)
	{
		printf("错误提示：n小于0\n");
		return 0;
	}
	printf("前%d项和为：\n", n+1);
	for (i=0;i<=n;i++)
	{
		s = s + jiecheng(i);
		if (i == 0)
		printf("0!");
		else 
		printf("+%d!", i);
	} 
    printf("=%d\n", s);
    system("pause");
	return 0;
}
int jiecheng(int n)
{
	int i;
	int s = 1;
	if (n == 0)
	s = 1;
	else
	for (i=1;i<=n;i++)
	s = s * i;
	return s;
}
