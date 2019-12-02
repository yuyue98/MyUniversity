#include<stdio.h>
#include<math.h>
int main()
{
 int x, n, i, a, b, c;
 scanf ("%d", &x);
 if (x < 0)
 x = -x;
 else
 x = x;
 a = x, n = 0;
 while (a > 0)
 {
    a = a / 10;
    n++;
 }
 c = 0;
 for (i = 1;i <= n;i++)
 {
    b = x % 10;
    x = (x - b) / 10;
    c = c + b;
 }
 printf ("%d %d\n", c, n);
 return 0;
}
