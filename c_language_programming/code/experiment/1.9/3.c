#include<stdio.h>
struct student
{
    int id;
    int name[20];
    int score;
};
int main()
{
    struct student s[20], m;
    int i, j, t, n;
    printf("请输入学生人数n："); 
    while (scanf("%d", &n) != EOF)
    {
    	printf("请分别输入这%d个学生的信息：\n", n); 
        for (i = 0; i < n; i++)
        scanf("%d%s%d", &s[i].id, &s[i].name, &s[i].score);
        for (i = 0; i < n-1; i++)
        {
            t = i;
            for (j = i+1; j < n; j++)
            if (s[t].score > s[j].score)
            t = j;
            m = s[i];
            s[i] = s[t];
            s[t] = m;
        }
        printf("最高分学生的信息：学号%d 姓名%s 成绩%d\n", s[n-1].id, s[n-1].name, s[n-1].score);
        printf("最低分学生的信息：学号%d 姓名%s 成绩%d\n", s[0].id, s[0].name, s[0].score);
    	printf("请输入学生人数n：");
	}
    return 0;
}
