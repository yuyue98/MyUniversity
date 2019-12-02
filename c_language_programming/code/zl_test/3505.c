//输入一个实数x(float)，
//计算并输出下列分段函数的值。请调用数学函数计算。
//y=x^5+2x+1（x≤0） y=e^x-lg(x)（x>0）
//求e^x的函数：exp(x)
//求x^y的函数：pow(x,y)
//求lg(x)的函数：log10(x)
//根据计算公式计算y值并输出（保留3位小数)
#include<stdio.h>
#include<math.h>
int main()
{
  float x, y;
  scanf ("%f",&x);
  if (x <= 0)
  y = pow(x,5) + 2 * x + 1;
  else
  y = exp(x) - log10(x) ;
  printf ("y=%.3f\n",y);
  return 0;
}
