#include<stdio.h>
int main()
{
   int j, i;
   j = 0;
   for (i = 10; i <= 60; i++)
   {
       if (i % 7 != 0)
       continue;
       printf ("%d ", i);
       j++;
       if (j % 5 == 0)
       printf ("\n");
   }
   printf("\nj = %d\n", j);
   return 0;
}