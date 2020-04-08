#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

void swap(int *a, int *b);//交换函数 
void sord(int *s, int *w, int n);//排序函数 
void txqbestmove();//贪心算法求最优装载问题 
void hsqbestmove();//回溯法求最优装载问题
int fdghs(int *s, int *w, int *x, int c, int n);//实现非递归回溯 

int main()
{
	while (1)
	{
		printf("*************最优装载问题************\n");
		printf("            1、贪心法求解            \n");
		printf("            2、回溯法求解            \n");
		printf("*************************************\n");
		printf("请输入选项前的数字：");
		char ch[50];
		scanf("%s", ch);
		if (ch[0] == '1' )
		{
			//贪心算法求最优装载问题
			txqbestmove();	
		}
		else if (ch[0] == '2')
		{
			//回溯法求最优装载问题
			hsqbestmove(); 	
		}
		else
		{
			system("cls");
			printf("选择输入不正确，请重新输入！\n");
		}
	}
	return 0;
}

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
} 

void sord(int *s, int *w, int n)
{
	int i, j;//循环变量
	int t;
	for (i = 0;i < n-1;i++)
	{
		t = i;
		for (j = i+1;j < n;j++)
		{
			if (w[t] > w[j])
			{
				t = j;
			}
		}
		swap((w+i),(w+t));
		swap((s+i),(s+t));
	}	
}

void txqbestmove()
{
	int i, j, k;//循环变量
	int n, c;//物品个数，最大容量 
	int *w, *s, *x;//物品重量，物品标号，物品是否装入
	printf("请输入物品个数n：");
	scanf("%d", &n);
	getchar();
	printf("请输入最大容量c：");
	scanf("%d", &c);
	getchar();
	w = (int*)malloc(n*sizeof(int));
	s = (int*)malloc(n*sizeof(int));
	x = (int*)malloc(n*sizeof(int));
	for (i = 0;i < n;i++)
	{
		printf("请输入第%d个物品重量：", i+1);
		scanf("%d", &w[i]);
		getchar();
		s[i] = i;//序号初始化 
		x[i] = 0;//初始化所有物品均为不装入 
	}
	printf("排序前集装箱重量从小到大排列如下：\n");
	for (i = 0;i < n;i++)
	{
		printf("%3d", w[i]);
	}
	printf("\n序号对应如下：\n");
	for (i = 0;i < n;i++)
	{
		printf("%3d", s[i]+1);
	}
	printf("\n");
	sord(s,w,n);
	for (i = 0;i < n && w[s[i]] <= c;i++)
	{
		x[s[i]] = 1;
		c -= w[s[i]];
	}
	printf("可行解为：\n");
	for (i = 0;i < n;i++)
	{
		printf("%3d", x[i]);
		if ((i+1)%10 == 0)
			printf("\n");
	} 
	printf("\n");
	free(w);
	free(s);
	free(x);
	printf("输入任意键返回......\n");
	getchar();
	system("cls");	 
}

void hsqbestmove()
{
	int i, j, k;//循环变量
	int n, c1, c2;//集装箱个数，第一艘船最大载重，第二艘船最大载重
	int *w, *s, *x;
	printf("请输入物品个数n：");
	scanf("%d", &n);
	getchar();
	printf("请输入分别输入两艘船最大容量c1与c2（以空格隔开）：");
	scanf("%d", &c1);
	getchar();
	scanf("%d", &c2);
	getchar();
	w = (int*)malloc(n*sizeof(int)); 
	s = (int*)malloc(n*sizeof(int)); 
	x = (int*)malloc(n*sizeof(int));
	for (i = 0;i < n;i++)
	{
		printf("请输入第%d个物品重量：", i+1);
		scanf("%d", &w[i]);
		getchar();
		s[i] = i;//序号初始化 
		x[i] = 0;//初始化所有物品均为不装入 
	}
	sord(s,w,n);
	printf("排序后集装箱重量从小到大排列如下：\n");
	for (i = 0;i < n;i++)
	{
		printf("%3d", w[i]);
	}
	printf("\n序号对应如下：\n");
	for (i = 0;i < n;i++)
	{
		printf("%3d", s[i]+1);
	}
	printf("\n");
	int bestw = fdghs(s,w,x,c1,n);
	int sy = 0;//剩余集装箱重量 
	for (i = 0;i < n;i++)
	{
		if (x[i] == 0)
		{
			sy += w[i];
		}
	}
	if (sy > c2)
	printf("第二艘船装不下剩余货物！\n");
	else
	{
		for (i = 0;i < n;i++)
	 	{
	 		if (x[i] == 0)
	 		x[i] = 2;
	 	}
		printf("第一艘船：bestw1 = %d\n", bestw);
		printf("第二艘船：bestw2 = %d\n", sy); 
		printf("可行解为：");
		for (i = 0;i < n;i++)
		{
			printf("%3d", x[i]);
		}
		printf("\n");
	}
	free(w);
	free(s);
	free(x); 
	printf("输入任意键返回......\n");
	getchar();
	system("cls");	
}

int fdghs(int *s, int *w, int *x, int c, int n)
{
	int i, j = 0, k = 0;
	int cw = 0, bestw = 0;
	int *bestx;
	bestx = (int*)malloc(n*sizeof(int));
	for (i = 0;i < n;i++)
		bestx[i] = 0;
    int r = 0;          //剩余集装箱重量  
    for (i = 0;i < n;i++)  
    {  
        r += w[i];  
    }
    while(1)//搜索子树  
    {       
        while(k < n)//进入左子树  
        {
			if (cw+w[k] <= c)
			{
				r -= w[k];  
	            cw += w[k];  
	            x[k] = 1;  
	            k++;  	
			}
			else
				break; 
        }  
        if (k >= n)//到达叶结点  
        { 
	        for (i = 0;i < n;i++)  
            {  
                bestx[i] = x[i]; 
            } 
            bestw = cw;	
			 	   
        }  
        else//进入右子树  
        {            
            r -= w[k];  
            x[k] = 0; 
			k++;  
        }  
        while (cw+r <= bestw)  
        { //剪枝回溯  
            k--;     
            while (k>=0 && !x[k])  
            {   
                r += w[k];  
                k--;  
            }     
            //从右子树返回  
            if (k == -1)  
            {
                for (i = 0;i < n;i++)
                {
                	x[i] = bestx[i];
                }
				free(bestx);  
                return bestw;  
            }  
            x[k] = 0;  
            cw -= w[k];  
            k++;  
        }  
    }    
}  
