#include<stdio.h>
#include<math.h>
int zhi_he(int n); 
int main(int argc, char *argv[])
{
    int n, i, a, k;
    k = 0;
    n = 200;
    printf("200~299间素数如下：\n"); 
    while (n <= 299)
    {   
        if (zhi_he(n) == 1)
        {
            printf ("%d", n);
            k++;
            if (k != 0 && k % 8 == 0 )
        {
            printf ("\n");
        }
        else if (k != 0 && k % 8 != 0 )
        {
            printf (" ");
        }
        }
        n++;
    }
    return 0;
}
int zhi_he(int n)
{
	int i=2;
	while (i < n)
        {
            if (n % i != 0)
            {
                i++;
            }
            else
            return 0;
        }
	return 1;
}
