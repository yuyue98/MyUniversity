#include <stdio.h>
#include <string.h> 

int main(int argc, char *argv[])
{
	char s[81], v[26];
    int i, j, n;
    v[0] = 'A';
    for (i = 1; i < 26; i++)
    v[i] = v[0] + i;
    printf("请输入一串字符："); 
    while (gets(s) != NULL)
    {
        n = strlen(s);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < 26; j++)
            {
                if (s[i] == v[j])
                {
                    s[i] = v[25 - j];
                    break;
                }
            }
        }
        printf("该串字符加密后输出为：");
        puts(s);
        printf("请输入一串字符："); 
    }
	return 0;
}
