#include<stdio.h>
int main()
{
  int a, b, c;
  scanf ("%d%d",&a,&b);
  c = 1500 + 5*(a+b);
  if (c < 1600)
  printf ("D\n");
  else if (c < 1700)
  printf ("C\n");
  else if (c < 1800)
  printf ("B\n");
  else
  printf ("A\n");
  return 0;
}
