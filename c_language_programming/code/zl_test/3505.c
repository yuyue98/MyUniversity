//����һ��ʵ��x(float)��
//���㲢������зֶκ�����ֵ���������ѧ�������㡣
//y=x^5+2x+1��x��0�� y=e^x-lg(x)��x>0��
//��e^x�ĺ�����exp(x)
//��x^y�ĺ�����pow(x,y)
//��lg(x)�ĺ�����log10(x)
//���ݼ��㹫ʽ����yֵ�����������3λС��)
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
