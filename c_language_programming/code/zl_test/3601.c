#include<stdio.h>
int main()
{
   int s, a, b, c, t, n, i;
   scanf ("%d", &n);
   {
   a = n;
   s = 0;
   for (i = 1; i <= n; i++)
   {
   	b = 1;
   	for (t = 1; t <= a;t++)
   	{
   		b = b * t;
   	}
       a = a - 1;
       s = s + b;
   }
   printf ("%d\n", s);
   }
   return 0;
}