#include <stdio.h>
int main()
{
    int a, na = 0, flag;
    scanf ("%d", &a);
    if (a<0){
        flag = -1;
        a = -a;
    }
    else {
        flag = 1;
    }
    while (a){
        na = na*10+a%10;
        a /= 10;
    }
    na *= flag;
    printf ("%d\n", na);
    return 0;
}