#include<stdio.h>
int length(char *s);
int main()
{
    int l;
    char s[80];
    printf("请输入一串字符："); 
    while (gets(s) != NULL)
    {
        printf("该字符串长度为：%d\n", length(s));
        printf("请输入一串字符："); 
    }
    return 0;
}
int length(char *s)
{
    int l;
    l = 0;
    while (*s != '\0')
    {
        l++;
        s++;
    }
    return l;
}
