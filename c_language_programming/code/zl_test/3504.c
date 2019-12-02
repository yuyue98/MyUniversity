//x<0 y=0 0<=x<10 y=x 10<=x<20 y=10 x>=20 y=30

#include<stdio.h>
int main()
{
  int x;
  float y;
  scanf ("%d",&x);
  if (x < 0)
  y = 0;
  else if (x < 10)
  y = x;
  else if (x < 20)
  y = 10;
  else
  y = 30;
  printf ("y=%f\n",y);
  return 0;
}
