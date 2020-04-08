#include<stdio.h>
#include <stdlib.h>
int main()
{
	int P,Q,a,b,c,d,p,q;
	printf("   P的值");
	for(P=0;P<2;P++)
	{
		for(Q=0;Q<2;Q++)
			printf("\t%d",P);
	}
	printf("\n   Q的值");
	for(P=0;P<2;P++)
	{
		for(Q=0;Q<2;Q++)
			printf("\t%d",Q);
	}
	printf("\n  非P的值");
	for(P=0;P<2;P++)
	{
		for(Q=0;Q<2;Q++)
		{
			if(P==0)/*判断非P的值*/
				p=1;
			else
				p=0;
			printf("\t%d",p);
		}
	}
	printf("\n  非Q的值");
	for(P=0;P<2;P++)
	{
		for(Q=0;Q<2;Q++)
		{
			if(Q==1)/*判断非Q的值*/
				q=0;
			else
				q=1;
			printf("\t%d",q);
		}
	}
	printf("\n P与Q的值");
	for(P=0;P<2;P++)
	{
		for(Q=0;Q<2;Q++)
		{
			if(Q==0||P==0)/*判断P与Q的值*/
				a=0;
			else
				a=1;
			printf("\t%d",a);
		}
	}
	printf("\n P或Q的值");
	
	// 补充代码
	for(P=0;P<2;P++)
	{
		for(Q=0;Q<2;Q++)
		{
			if(Q==0&&P==0)/*判断P或Q的值*/
				a=0;
			else
				a=1;
			printf("\t%d",a);
		}
	}
	printf("\n P蕴含Q的值");
	for(P=0;P<2;P++)
	{
		for(Q=0;Q<2;Q++)
		{
			if(P==1&&Q==0)/*判断P蕴含Q的值*/
				a=0;
			else
				a=1;
			printf("\t%d",a);
		}
	}
	printf("\n Q蕴含P的值");
	for(P=0;P<2;P++)
	{
		for(Q=0;Q<2;Q++)
		{
			if(Q==1&&P==0)/*判断Q蕴含P的值*/
				a=0;
			else
				a=1;
			printf("\t%d",a);
		}
	}
	printf("\n P与Q双条件的值");
	for(P=0;P<2;P++)
	{
		for(Q=0;Q<2;Q++)
		{
			if(P!=Q)/*判断P与Q双条件的值*/
				a=0;
			else
				a=1;
			printf("\t%d",a);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
