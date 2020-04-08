#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

int main()
{
	FILE *fp, *fp1;
	fp = fopen("账单序列.txt","w");
	if((fp1 = fopen("账单.txt","r")) == NULL)
	{
		printf("不存在文件账单.txt!\n");
		exit(0);
	}
	int i, j, k, o, m;
	int xulie1[8][8], xulie2[12][12], zhangdan[7][4];
	xulie1[0][0] = 1, xulie2[0][0] = 2;
	for(i = 1;i < 8;i++)
	xulie1[0][i] = xulie1[i][0] = i;
	for(i = 1;i < 12;i++)
	xulie2[0][i] = xulie2[i][0] = i;
	char str[10];
	for(i=0;i<10;i++)
		str[i] = 0;
	int cat;//行结束条件 
	str[0] = 'x';
	for(i = 0;i < 7;i++)
		for(j = 0;j < 4;j++)
			zhangdan[i][j] = 0;
	for(i = 1;i < 8;i++)
		for(j = 1;j < 8;j++)
			xulie1[i][j] = 0;
	for(i = 1;i < 12;i++)
		for(j = 1;j < 12;j++)
			xulie2[i][j] = 0;
	//书 = 1，牛奶 = 2，面包 = 3，水 = 4，发夹 = 5
	//啤酒 = 6，尿布 = 7，青菜 = 8，苹果 = 9，米 = 10，油 = 11
	for(i = 0;i < 7;i++) 
	{
		m = 0, cat = 0, j = 0;
		fgets(str,6,fp1);
		printf("%s\n",str);
		while(1)
		{
			str[m] = fgetc(fp1);
			if(str[m] == ' ' || str[m] == '\n')
			{
				if(str[m] == '\n')
				cat = 1;
				str[m] = '\0';
				if(strcmp(str,"书") == 0)
				zhangdan[i][j] = 1;
				if(strcmp(str,"牛奶") == 0)
				zhangdan[i][j] = 2;
				if(strcmp(str,"面包") == 0)
				zhangdan[i][j] = 3;
				if(strcmp(str,"水") == 0)
				zhangdan[i][j] = 4;
				if(strcmp(str,"发夹") == 0)
				zhangdan[i][j] = 5;
				if(strcmp(str,"啤酒") == 0)
				zhangdan[i][j] = 6;
				if(strcmp(str,"尿布") == 0)
				zhangdan[i][j] = 7;
				if(strcmp(str,"青菜") == 0)
				zhangdan[i][j] = 8;
				if(strcmp(str,"苹果") == 0)
				zhangdan[i][j] = 9;
				if(strcmp(str,"米") == 0)
				zhangdan[i][j] = 10;
				if(strcmp(str,"油") == 0)
				zhangdan[i][j] = 11;	
				printf("%s\n", str);
				m = 0;
				j++; 	
			}
			else
			m++;
			if(cat) {
				// printf("%s\n",str);
				break;
			}
		}
	}//读取账单 
	for(i = 0;i < 7;i++)
	{
		j = 0;
		while(j < 4 && zhangdan[i][j])
		{
			for(k = 0;k < 7;k++)
			{
				o = 0;
				while(o < 4 && zhangdan[k][o])
				{
					if(zhangdan[i][j] == zhangdan[k][o])
					xulie1[i+1][k+1]++;
					o++;
				}	
			}
			j++;
		}
	}//计算商品数矩阵
	for(i = 0;i < 7;i++)
	{
		j = 0;
		while(j < 4 && zhangdan[i][j])
		{
			k = 0;
			while(k < 4 && zhangdan[i][k])
			{
				xulie2[zhangdan[i][j]][zhangdan[i][k]]++;
				k++;
			}
			j++;
		}
	}//计算人数矩阵 
	printf("账单如下：\n");
	for(i = 0;i < 7;i++)
	{	
		for(j = 0;j < 4;j++)
		{
			printf("%d ", zhangdan[i][j]);
		}
		printf("\n");
	}
	printf("相同商品种类数矩阵如下：\n");
	fprintf(fp,"相同商品种类数矩阵如下：\n"); 
	for(i = 0;i < 8;i++)
	{	
		for(j = 0;j < 8;j++)
		{
			printf("%3d", xulie1[i][j]);
			fprintf(fp,"%3d", xulie1[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
	printf("相同客人人数矩阵如下：\n");
	fprintf(fp,"相同客人人数矩阵如下：\n");
	for(i = 0;i < 12;i++)
	{	
		for(j = 0;j < 12;j++)
		{
			printf("%3d", xulie2[i][j]);
			fprintf(fp,"%3d", xulie2[i][j]);
		}
		printf("\n");
		fprintf(fp,"\n");
	}
	fclose(fp);
	fclose(fp1);
	return 0;
} 
