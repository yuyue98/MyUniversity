#include<stdio.h>
#include<math.h>
int main()
{
 int x, n, i, a, b, c;
 scanf ("%d", &n);
 for (i = 2;i <= n;i++)
 {
 b =i % 100;
 c =b % 10;
 a =(i - b) / 100;
 b =(b - c) /10;
 x = pow(a,3)+pow(b,3)+pow(c,3);
 if (x == i)
 printf ("%d   ", i);
 }
 return 0;
}
