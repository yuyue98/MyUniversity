#include  <stdio.h>
main()
{
    int count;
    int ac[10000];
    int i,j,k;
    int ac_same;
    int ac_same_count;

    count = 0;
    ac_same = 0;
    ac_same_count = 0;
    scanf("%d\n", &count);
    if (count==0)
        break;
    for(i=0; i<count; i++)
    {
         scanf("%d", &ac[i]);
         k=0;
         for(j=0; j<i; j++)
             if (ac[i] == ac[j])
                 k++;
         if (k > ac_same_count)
         {
             ac_same_count=k;
             ac_same = ac[i];
          }
     }

     if (ac_same_count>0 && (ac_same_count+1) >= count/2)
         printf("%d\n", ac_same);
     else
         printf("0\n");
}