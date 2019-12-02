#include<stdio.h>
int main()
{
 int n, a, b, i;
 scanf ("%d", &n);
 b = 0;
 for (i = 1;i <= n;i++)
 {
  scanf ("%d", &a);
  b = b + a;
 }
 printf ("s=%d\n", b);
 return 0;
}
