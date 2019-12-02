#include<stdio.h>
struct student
{
    int id;
    char name[20];
    int score;
};
int main()
{
    struct student s[20];
    struct student t;
    int i, j, index, n;
    printf("请输入学生人数n："); 
    while (scanf("%d", &n) != EOF)
    {
    	printf("请输入这%d个学生的信息：\n", n); 
    	for (i = 0; i < n; i++)
        scanf("%d%s%d", &s[i].id, s[i].name, &s[i].score);
    	for (i = 0; i < n-1; i++)
    	{
        index = i;
        for (j = i + 1; j < n; j++)
        	if (s[index].score> s[j].score)
        		index = j;
       	t = s[i];
       	s[i] = s[index];
       	s[index] = t;
    	}
    	printf("学生信息按成绩从小到大顺序输出如下：\n");
    	for (i = 0; i < n; i++)
    	printf("%d %s %d\n", s[i].id, s[i].name, s[i].score);
    	printf("请输入学生人数n："); 
	}
    return 0;
}
