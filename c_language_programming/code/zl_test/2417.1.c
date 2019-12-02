#include <stdio.h>
int fun(int year,int month,int day);
void main()
{
while(1)
{
int year,month,day;
scanf("%d-%d-%d",&year,&month,&day);
fun(year,month,day);//调用fun方法。
}
}
int fun(int year,int month,int day)
{
int s=0;
int
a[2][12]={0,31,59,90,120,151,181,212,243,273,304,334,0,31,60,91,121,152,182,213,244,274,305,335};

if((year%400==0)||(year%4==0&&year%100!=0))//若果是闰年则调用该函数。
 {
s=a[1][month-1]+day;
printf("%d\n",s); 
}
else//如果非闰年调用该函数。
{
s=a[0][month-1]+day;
printf("%d\n",s); 
}
return 0;
}