#include<stdio.h>
#include<math.h>
int main()
{
   int a, b, n, i;
   scanf ("%d", &n);
   a = 0;
   for (i = 2; i < n; i++)
   {
       if (n % i == 0)
       a++;
   }
   if (a == 0)
   printf ("Yes\n");
   else
   printf("No\n");
   return 0;
}