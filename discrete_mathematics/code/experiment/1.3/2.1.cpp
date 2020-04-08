#include<stdio.h>
#include<stdlib.h>
int main()
{
   int a[5],i;
   printf("please input five persons' choices (1 means YES 0 means NO):\n");
   for(i=0;i<5;i++)
      scanf("%d",&a[i]);
   a[5]=0;
   for(i=0;i<5;i++)
      a[5]=a[5]+a[i];
   if(a[5]>=3)
      printf("YES!");
   else
      printf("NO!");
   system("pause");
   return 0;
}
