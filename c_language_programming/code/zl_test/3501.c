#include<stdio.h>
int main()
{
 int a;
 scanf ("%d",&a);
 if (a % 7 == 0 && a % 5 == 0)
 {
  printf ("Yes\n");
 }else
 {
  printf ("No\n");
 }
 return 0;
}