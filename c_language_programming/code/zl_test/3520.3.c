#include<stdio.h>
int main()
{
 int min, max, n, a, b, i;
 scanf ("%d %d", &n, &b);
 min = b; max = b;
 for (i = 1;i < n;i++)
 {
  scanf ("%d", &a);
  if (max < a)
  {
    max = a;
  }
  else
  max = max;
  if (min > a)
  {
    min = a;
  }
  else
  min = min;
 }
 printf ("max=%d, min=%d\n", max, min);
 return 0;
}
