#include<stdio.h>
int main()
{
   int a, b, n, i;
   scanf ("%d", &n);
   b = 2;
   for (i = 2; i < n; i++)
   {
       if (n % i != 0)
       b++;
   }
   if (b == n)
   printf ("Yes\n");
   else
   printf("No\n");
}