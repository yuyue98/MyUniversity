#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int a, b, c, d, e, p, q, x, y, z, n = 0, k = 0, i = 0, m = 0;
	FILE *fp;
	fp = fopen("锁具型号.txt","w"); 
	printf("符合的锁具型号如下：\n");
	fprintf(fp,"符合的锁具型号如下：\n");
	int as[5880],bs[5880],cs[5880],ds[5880],es[5880];
	for(a = 1;a < 7;a++)
	{
		k = 1, p = k;
		for(b = 1;b < 7;b++)
		{
			k = p;
			if(abs(a-b) == 5)
			continue;
			if(b != a)
			k++;
			q = k;
			for(c = 1;c < 7;c++)
			{
				k = q;
				if(abs(b-c) == 5)
				continue;
				if(c != a && c != b)
				k++;
				x = k;
				for(d = 1;d < 7;d++)
				{
					k = x;
					if(abs(c-d) == 5)
					continue;
					if(d != a && d != b && d != c)
					k++;
					y = k;
					for(e = 1;e < 7;e++)
					{
						k = y;
						if(abs(d-e) == 5)
						continue;
						if(e != a && e != b && e != c && e != d)
						k++;
						z = k;
						if(k >= 3)
						{
                            as[n] = a,bs[n] = b,cs[n] = c,ds[n] = d,es[n] = e;
							printf("%d%d%d%d%-2d%", a, b, c, d, e);
							fprintf(fp,"%d%d%d%d%-2d%", a, b, c, d, e);
							n++;
							if(n != 0 && n % 20 == 0)
							{
								printf("\n");
								fprintf(fp,"\n");
							}
						}
					}
				}
			}
		}
	}
	printf("符合的锁具有%d件。\n", n);
	fprintf(fp,"符合的锁具有%d件。\n", n);
	fclose(fp);
	system("pause");
	return 0;
}
