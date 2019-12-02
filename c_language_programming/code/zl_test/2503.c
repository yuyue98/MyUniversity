//score:90-100 ----> good score:80-89 ---->
//nicer score:70-79 ----> medium score:60-69 ---->
//pass score:0-59 ----> fail
#include<stdio.h>
int main()
{
  int a;
  scanf ("%d",&a);
  if (a < 60)
  printf ("fail\n");
  else if (a < 70)
  printf ("pass\n");
  else if (a < 80)
  printf ("medium\n");
  else if (a < 90)
  printf ("nicer\n");
  else
  printf ("good\n");

  return 0;
 
}
