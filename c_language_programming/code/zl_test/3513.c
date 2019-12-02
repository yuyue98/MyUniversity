#include<stdio.h>
int main()
{
 int n, i;
 float x, a;
 scanf ("%f %d", &x, &n);
 a = x;
 for (i = 1;i < n;i++)
 {
  x = x * a * 1.0;
 }
 printf ("%.2f\n", x);
 return 0;
}
