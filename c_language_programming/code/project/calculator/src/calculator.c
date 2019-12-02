#include "myheader.h"
#include "calculator.h"

void menu()
{
    char n;
    system("cls");
    printf ("    **********菜单*********\n");
    printf ("简易型(j)/t科学型(k)/退出(x)\n");
    printf ("请输入你的选择(j,k,x):");
    choose();
}
void simple()
{
    char n, m;
    float a, b;
    printf ("加(a)/减(s)/乘(m)/除(d)/向上(r)/退出(x)\n");
    printf ("请输入你的选择(a,s,m,d,r,x):");
    scanf("%s",&n);
    if (n == 'r')
        menu();
    else
    {
        printf ("请输入两个数字a,b:");
        scanf("%f%f", &a, &b);
        system("cls");
        switch (n)
        {
        case 'a':
            printf ("%.2f + %.2f = %.2f\n", a, b, a+b);
            break;
        case 's':
            printf ("%.2f - %.2f = %.2f\n", a, b, a-b);
            break;
        case 'm':
            printf ("%.2f * %.2f = %.2f\n", a, b, a*b);
            break;
        case 'd':
            if (b == 0)
                printf("error\n");
            else
                printf ("%.2f / %.2f = %.2f\n", a, b, a/b);
            break;
        case 'x':
            exit(0);
        }
        printf ("是否继续运算(Y/N):");
        scanf ("%s", &m);
        system("cls");
        if (m == 'Y' || m == 'y')
            simple();
        else
            exit(0);
    }
}
void complex()
{
    char n, m;
    printf("正弦(i)/余弦(c)/正切(t)/x^y(m)/ln(e)/log(s)/n!(j)/1/x(d)/立方(u)/平方(p)/向上(r)/退出(x)\n");
    scanf("%s",&n);
    if (n == 'r')
        menu();
    else if (n == 'm')
    {
        float x, y;
        printf ("请输入两个数字x,y:");
        scanf ("%f%f", &x, &y);
        system("cls");
        printf ("%.2f^%.2f = %.2f\n", x, y, pow(x,y));
    }
    else
    {
        float a;
        printf ("请输入一个数字:");
        scanf("%f", &a);
        system("cls");
        switch (n)
        {
        case 'i':
            printf ("sin(%.2f) = %.2f\n", a, sin(a));
            break;
        case 'c':
            printf ("cos(%.2f) = %.2f\n", a, cos(a));
            break;
        case 't':
            printf ("tan(%.2f) = %.2f\n", a, tan(a));
            break;
        case 'e':
            if (a <= 0)
                printf("error\n");
            else
                printf ("ln(.2f) = %.2f\n", a, log(a));
            break;
        case 's':
            if (a <= 0)
                printf("error\n");
            else
                printf ("log(%.2f) = %.2f\n", a, log10(a));
            break;
        case 'j':
            printf ("%.2f! = %.2f\n", a, jc(a));
            break;
        case 'd':
            if (a == 0)
                printf("error\n");
            else
                printf ("1/%.2f = %.2f\n", a, 1/a);
            break;
        case 'u':
            printf ("%.2f^2 = %.2f\n", a, a*a);
            break;
        case 'p':
            printf ("%.2f^3 = %.2f\n", a, a*a*a);
            break;
        case 'x':
            exit(0);
        }
        printf ("是否继续运算(Y/N):");
        scanf ("%s", &m);
        system("cls");
        if (m == 'Y' || m == 'y')
            complex();
        else
            exit(0);
    }
}
void choose()
{
    char a;
    scanf ("%s", &a);
    system("cls");
    if (a == 'j')
        simple();
    else if (a == 'k')
        complex();
    else if (a == 'x')
        exit(0);
}
float jc(float n)
{
    float s;
    if (n == 1)
        s = 1;
    else
        s = n * jc(n-1);
    return s;
}