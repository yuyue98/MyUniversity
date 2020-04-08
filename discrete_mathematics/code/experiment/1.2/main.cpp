#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int zifan(int **q, int n);//判断自反性 
int duicheng(int **q, int n);//判断对称性 
int chuandi(int **q, int n);//判断传递性 

int main()
{
	int n;
	int i, j, k;
	char x, y;
	FILE *fp1, *fp2;
	char ch = '0', sh = 'y';
	char *p;
	int **q;
	do 
	{//文件的读写 
		printf("是否希望从文件读取二元关系（y/n）：");
		scanf("%c", &ch);
		getchar();
		if (ch == 'y' || ch == 'Y')
		{
			char str[30]; 
			printf("请输入要读取的文件名：");
			gets(str);
			if ((fp1 = fopen(str,"r")) == NULL)
			{
				system("cls");
				printf("文件%s不存在!\n", str);
				continue;
			}
			fscanf(fp1,"%d", &n);
			fscanf(fp1,"%c", &ch);
			//根据实际需求分配数组存储空间 
			p = (char*)malloc((n+1) * sizeof(char));
			q = (int**)malloc((n+1) * sizeof(int*));
			for (i = 0;i <= n;i++)
			*(q + i) = (int*)malloc((n+1) * sizeof(int));
			p[0] = 'A';
			//输入集合A中元素 
			for (i = 1;i <= n;i++)
			{
				fscanf(fp1,"%c", &p[i]);
				fscanf(fp1,"%c", &ch);
			}
			q[0][0] = 'R';
			//初始化关系矩阵R 
			for (i = 1;i <= n;i++)
				q[i][0] = q[0][i] = i;
			for (i = 1;i <= n;i++)
				for (j = 1;j <= n;j++)
					q[i][j] = 0;
			//输入二元关系 
			while((fscanf(fp1,"%c", &x)) != EOF) 
			{
				fscanf(fp1,"%c", &ch);
				fscanf(fp1,"%c", &y);
				fscanf(fp1,"%c", &ch);
				for (i = 1;i <= n;i++)
				{
					if (x == p[i])
					break;
				}
				for (j = 1;j <= n;j++)
				{
					if (y == p[j])
					break;
				}
				q[i][j] = 1;
			}
		}
		else if (ch == 'n' || ch == 'N')
		{
			char str[30]; 
			printf("请输入要保存的文件名：");
			gets(str); 
			fp1 = fopen(str,"w");	
			printf("请输入集合A中的元素个数n：");
			scanf("%d", &n);
			fprintf(fp1,"%d", n); 
			fprintf(fp1,"%c", getchar());
			//根据实际需求分配数组存储空间 
			p = (char*)malloc((n+1) * sizeof(char));
			q = (int**)malloc((n+1) * sizeof(int*));
			for (i = 0;i <= n;i++)
			*(q + i) = (int*)malloc((n+1) * sizeof(int));
			p[0] = 'A';
			//输入集合A中元素
			printf("请依次输入集合A中各元素（用空格隔开）：\n");
			for (i = 1;i <= n;i++)
			{
				scanf("%c", &p[i]);
				fprintf(fp1,"%c", p[i]);
				fprintf(fp1,"%c", getchar());
			}
			q[0][0] = 'R';
			//初始化关系矩阵R
			for (i = 1;i <= n;i++)
				q[i][0] = q[0][i] = i;
			for (i = 1;i <= n;i++)
				for (j = 1;j <= n;j++)
					q[i][j] = 0;
			//输入二元关系
			printf("请依次输入二元关系对应的有序对,'#'代表结束（例 1,4）：\n");
			while((x = getchar()) != '#') 
			{
				fprintf(fp1,"%c", x);
				fprintf(fp1,"%c", getchar());
				y = getchar();
				fprintf(fp1,"%c", y);
				fprintf(fp1,"%c", getchar());
				for (i = 1;i <= n;i++)
				{
					if (x == p[i])
					break;
				}
				for (j = 1;j <= n;j++)
				{
					if (y == p[j])
					break;
				}
				q[i][j] = 1;
			}
			getchar();
		}
		fp2 = fopen("结果.txt","w");
		//打印集合A 
		printf("A = {");
		fprintf(fp2,"A = {");
		for (i = 1;i < n;i++)
		{
			printf("%c,", *(p+i));
			fprintf(fp2,"%c,", *(p+i));
		}
		printf("%c}\n", *(p+i));
		fprintf(fp2,"%c}\n", *(p+i));
		//打印关系矩阵R 
		printf("A的关系矩阵如下：\n");
		fprintf(fp2,"A的关系矩阵如下：\n");
		for (i = 0;i <= n;i++)
		{
			for (j = 0;j <= n;j++)
			{
				if (i == 0 && j == 0)
				{
					printf("  ");
					fprintf(fp2,"  ");
				}
				else if (i == 0)
				{
					printf("%c ", p[j]);
					fprintf(fp2,"%c ", p[j]);
				}
				else if (j == 0)
				{
					printf("%c ", p[i]);
						fprintf(fp2,"%c ", p[i]);
				}
				else
				{
					printf("%d ", q[i][j]);
					fprintf(fp2,"%d ", q[i][j]);
				}
			}
			printf("\n");
			fprintf(fp2,"\n");
		}
		//输出自反性判断
		if (zifan(q,n))
		{
			printf("这个二元关系具有自反性！\n");
			fprintf(fp2,"这个二元关系具有自反性！\n");
		}
		else
		{
			printf("这个二元关系不具有自反性！\n");
			fprintf(fp2,"这个二元关系不具有自反性！\n");
		} 
		//输出对称性判断 
		if (duicheng(q,n))
		{
			printf("这个二元关系具有对称性！\n");
			fprintf(fp2,"这个二元关系具有对称性！\n");
		}
		else
		{
			printf("这个二元关系不具有对称性！\n");
			fprintf(fp2,"这个二元关系不具有对称性！\n");
		}
		//输出传递性判断
		if (chuandi(q,n))
		{	
			printf("这个二元关系具有传递性！\n");
			fprintf(fp2,"这个二元关系具有传递性！\n");
		}
		else
		{
			printf("这个二元关系不具有传递性！\n");
			fprintf(fp2,"这个二元关系不具有传递性！\n");
		}
		//判断等价关系 
		if (zifan(q,n) && duicheng(q,n) && chuandi(q,n))
		{
			printf("这个二元关系是等价关系！\n");
			fprintf(fp2,"这个二元关系是等价关系！\n");
			//输出商集
			int a[10] ={0,0,0,0,0,0,0,0,0,0};
			printf("A/R = {");
			fprintf(fp2,"A/R = {");
			for (i = 1;i <= n;i++)
			{
				if(a[i-1] == 0)
				{
					printf("{");
					fprintf(fp2,"{");
					for(j = i;j <= n;j++)
					{
						if(q[i][j] == 1)
						{
							printf("%c,", p[j]);
							fprintf(fp2,"%c,", p[j]);
							a[j-1] = i;
						}
					}
					printf("\b},");
					fprintf(fp2,"}");
				}
				else
				continue;
			}
			printf("\b}\n");
			fprintf(fp2,"}\n");
			//输出等价类 
			printf("该二元关系的等价类如下：\n");
			fprintf(fp2,"该二元关系的等价类如下：\n");
			for (i = 1;i <= n;i++)
			{
				printf("{%c} = {", p[i]);
				fprintf(fp2,"{%c} = {", p[i]);
				for (j = 0;j < n;j++)
				{
					if (a[j] == a[i-1])
					{
						printf("%c,", p[j+1]);
						fprintf(fp2,"%c,", p[j+1]);
					}
				}
				printf("\b}\n");
				fprintf(fp2,"}\n");
			}
		printf("\n");
		}
		else
		{
			printf("这个二元关系不是等价关系！\n");
			fprintf(fp2,"这个二元关系不是等价关系！\n");
		}
		//释放之前申请的存储空间 
		free(p);
		for (i = 0;i <= n;i++)
		free(*(q + i));
		free(q);
		fclose(fp1);
		fclose(fp2);
		printf("是否继续判断等价关系（y/n）：");
		scanf("%c", &sh);
		getchar();
		system("cls");
	}while(sh == 'y' || sh == 'Y');
	system("pause");	
	return 0;
}

int zifan(int **q, int n)
{
	int i;
	for (i = 1;i <= n;i++)
	{
		if (q[i][i] != 1)
			return 0;
	}
	return 1;
}

int duicheng(int **q, int n)
{
	int i, j;
	for (i = 1;i <= n;i++)
	{
		for (j = i;j <= n;j++)
		{
			if (q[i][j] != q[j][i])
				return 0;
		}
	}
	return 1;
}

int chuandi(int **q, int n)
{
	int i, j, k;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= n;j++)
		{
			if (q[i][j] != 1)
			continue;
			else
			for (k = 1;k <= n;k++)
			{
				if (q[j][k] != 1)
				continue;
				else
				{
					if (q[i][k] != 1)
					return 0;
				}
			}
		}
	}
	return 1;
}
