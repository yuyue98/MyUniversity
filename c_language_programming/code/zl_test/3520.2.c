 #include <stdio.h>
int main(void)
{
 int i,n,max,min,temp;
 int a[100];
 scanf("%d",&n);
 max = min =0;//首先不知道最大，小 值的时候，预定值得大，小为0.也就是为数组中的第一个值大小。 
 for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]); //输入为第一个的值大小 ，通过依次比较10个数组值的大小，从而得出最值大小。 
    if(a[i]>a[max])
          max = i;//如果i 数组大小大于max 则把i的值赋给max。
    if(a[i]<a[min]) //同理也就可以得出min的 大小了。    
          min = i;
   } 
   temp = a[max]; //通过数组就可以简单地转换 最小值与第一个数。或者。最大值与最后一个数了。 
   a[max] = a[n-1];
   a[n-1] = temp;
   temp = a[min];
   a[min] = a[0];
   a[0] = temp;
        printf("max=%d, min=%d", a[n-1],a[0]);
        //最后输出经过转换后的数组值就可以了。
 return 0;
}