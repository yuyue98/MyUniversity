#include "myheader.h"
#include "hotelManage.h"

extern int allmoney;

void endry()
{
    
	int n, i;
	int slot;
	init();
	printf("需要录入多少房间：");
    scanf("%d",&n);
    system("cls");
    for(i = 0; i < n; i++)
    {
    	slot = freefind();
	    if(slot == -1)
	    {
		    printf("数据库容量已满，请扩容！\n");
		    save();
		    return;
	    }
	    printf("请输入第%d间房间的房间号:", i+1);
	    scanf("%d",&slot);
	    slot = slot - 1;
	    if(slot >= MAX)
	    {
		    printf("数据库中无此房间位置，请扩容！\n");
		    save();
		    return; 
	    }
	    room[slot].number = slot + 1;
		printf("（A.标准房  B.单人房  C.大床房）\n");
		printf("请输入房间类别前的大写字母：");
		scanf("%s", &room[slot].type);
		printf("请分别输入日租房与钟点房价格：");
		scanf("%d%d", &room[slot].price[0], &room[slot].price[1]);
		system("cls");
    }
	menu1();
}
void init()
{
	register int t;
	allmoney = '\0';
	for(t = 0; t < MAX; t++)
	{
		room[t].number = '\0';
		room[t].type[0] = '\0';
		room[t].price[0] = '\0' ;
		room[t].black[0] = 'N'; 
	}
}
void menu1()
{
	system("cls");
	int a;
    printf("\n++++++++酒店管理系统++++++++\n"); 
	printf("\t1.信息修改\n");
	printf("\t2.信息查询\n");
	printf("\t3.订房\n");
	printf("\t4.退房\n");
	printf("\t5.保存\n");
	printf("\t6.读取\n");
	printf("\t7.账单\n");
	printf("\t8.账单归零\n");
	printf("\t9.退出\n");
	printf("请输入你需要的选项前的数字:");
	scanf("%d", &a);
	system("cls");
	switch(a)
	{
		case 1:menu21();break;
		case 2:menu22();break;
		case 3:menu23();break;
		case 4:back();break;
		case 5:save();break;
		case 6:load();break;
		case 7:check();break;
		case 8:checkzero();break;
		case 9:exit(0);
		default:printf("此选项不存在");
	}
	menu1();     
}
void menu21()
{
	system("cls");
	int a;
    printf("\n++++++++酒店信息修改++++++++\n"); 
	printf("\t1.增加房间\n");
	printf("\t2.减少房间\n");
	printf("\t3.房间价格修改\n");
	printf("\t4.返回上一级\n");
	printf("\t5.退出\n");
	printf("请输入你需要的选项前的数字:");
	scanf("%d", &a);
	system("cls");
	switch(a)
	{
		case 1:ent();break;
		case 2:del();break;
		case 3:pri();break;
		case 4:menu1();break;
		case 5:exit(0);
		default:printf("此选项不存在");
	}
	menu21();
}
void ent()
{
	int slot;
	char a; 
	slot = freefind();
	if(slot == -1)
	{
		printf("数据库容量已满，请扩容！\n");
		return;
	}
	printf("请输入一个要增加房间的房间号:");
	scanf("%d",&slot);
	slot = slot - 1;
	if(slot >= MAX)
	{
		printf("数据库中无此房间位置，请扩容！\n");
		return; 
	}
	room[slot].number = slot + 1;
	printf("（A.标准房  B.单人房  C.大床房）\n");
	printf("请输入增加房间的房间类别前的大写字母：");
	scanf("%s", &room[slot].type);
	printf("请分别输入增加房间的日租房与钟点房价格：");
	scanf("%d%d", &room[slot].price[0], &room[slot].price[1]);
	printf("是否要增加其他房间(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	ent(); 
	else if(a == 'n' || a == 'N')
	menu1();
}
int freefind()
{
	register int t;
	for(t = 0; room[t].number && t < MAX; t++)
	;
	if(t == MAX)
	return -1;
	else
	return 0;
}
void del()
{
	int t;
	char a; 
	printf("请输入一个要减少房间的房间号：");
	scanf("%d", &t);
	if(t >= 0 && t <= MAX)
	{
		room[t-1].number = '\0';
		room[t-1].type[0] = '\0';
		room[t-1].price[0] = '\0' ;
		room[t-1].black[0] = 'N'; 
	}
	printf("是否要减少其他房间(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	del();
	else if(a == 'n' || a == 'N')
	menu1(); 
}
void pri()
{
	register int t;
	char n, a;
	int price[2]; 
	printf("（A.标准房  B.单人房  C.大床房）\n");
	printf("请输入需要修改价格的房间类别前的大写字母：");
	scanf("%s", &n);
	printf("请分别输入修改后的日租房与钟点房价格：");
	scanf("%d%d", &price[0], &price[1]);
	for(t = 0; t < MAX; t++)
	{
		if(n == room[t].type[0])
		{
			room[t].price[0] = price[0];
			room[t].price[1] = price[1];
		}
	} 
	printf("是否需要修改其他类别房间的价格(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	pri();
	else if(a == 'n' || a == 'N')
	menu1(); 
}
void menu22()
{
    system("cls");
	int a;
    printf("\n++++++++酒店信息查询++++++++\n"); 
	printf("\t1.全部房间信息\n");
	printf("\t2.按房间号查询\n");
	printf("\t3.按房间类别查询\n");
	printf("\t4.价格查询\n");
	printf("\t5.返回上一级\n");
	printf("\t6.退出\n");
	printf("请输入你需要的选项前的数字:");
	scanf("%d", &a);
	system("cls");
	switch(a)
	{
		case 1:list();break;
		case 2:numfind();break;
		case 3:typfind();break;
		case 4:prilist();break;
		case 5:menu1();break;
		case 6:exit(0);
		default:printf("此选项不存在");
	}
	menu22();   
}
void list()
{
	system("cls");
	register int t;
	char a; 
	printf("房间号\t房间类别\t日租房价格\t钟点房价格\t是否已租出\n");
	for(t = 0; t < MAX;t++)
	{
		if(room[t].number)
		{
			printf("%d", room[t].number);
			if(room[t].type[0] == 'A')
			printf("\t标准房");
			else if(room[t].type[0] == 'B')
			printf("\t单人房");
			else if(room[t].type[0] == 'C')
			printf("\t大床房");
			printf("\t\t%d", room[t].price[0]);
			printf("\t\t%d", room[t].price[1]);
			printf("\t\t%s\n", room[t].black);
		}
	}
	printf("是否返回上级菜单(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	menu22();
	else if(a == 'n' || a == 'N')
	menu1();
}
void numfind()
{
	int slot;
	char a; 
	printf("输入你想查找的房间号：");
	scanf("%d", &slot);
	printf("房间号\t房间类别\t日租房价格\t钟点房价格\t是否已租出\n");
	printf("%d", room[slot-1].number);
	if(room[slot-1].type[0] == 'A')
	printf("\t标准房");
	else if(room[slot-1].type[0] == 'B')
	printf("\t单人房");
	else if(room[slot-1].type[0] == 'C')
	printf("\t大床房");
	printf("\t\t%d", room[slot-1].price[0]);
	printf("\t\t%d", room[slot-1].price[1]);
	printf("\t\t%s\n", room[slot-1].black);
	printf("是否需要查找其他房间号(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	numfind();
	else if(a == 'n' || a == 'N')
	menu22();  
}
void typfind()
{
	register int t;
	char n, a; 
	printf("（A.标准房  B.单人房  C.大床房）\n");
	printf("请输入所查询的房间类别前的大写字母：");
	scanf("%s", &n);
	printf("房间号\t房间类别\t日租房价格\t钟点房价格\t是否已租出\n");
	for(t = 0; t < MAX;t++)
	{
		if(n == room[t].type[0])
		{
			printf("%d", room[t].number);
			if(room[t].type[0] == 'A')
			printf("\t标准房");
			else if(room[t].type[0] == 'B')
			printf("\t单人房");
			else if(room[t].type[0] == 'C')
			printf("\t大床房");
			printf("\t\t%d", room[t].price[0]);
			printf("\t\t%d", room[t].price[1]);
			printf("\t\t%s\n", room[t].black);
		}
	}
	printf("是否返回上级菜单(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	menu22();
	else if(a == 'n' || a == 'N')
	save();
	exit(0); 
}
void prilist()
{
	register int t;
	char n, a; 
	printf("（A.标准房  B.单人房  C.大床房）\n");
	printf("请输入所查询的房间类别前的大写字母：");
	scanf("%s", &n);
	for(t = 0; t < MAX; t++)
	{
		if(n == room[t].type[0])
		{
			printf("房间类别\t日租房价格\t钟点房价格\n");
			if(room[t].type[0] == 'A')
			printf("标准房");
			else if(room[t].type[0] == 'B')
			printf("单人房");
			else if(room[t].type[0] == 'C')
			printf("大床房");
			printf("\t\t%d", room[t].price[0]);
			printf("\t\t%d\n", room[t].price[1]);
			break;
		}
	} 
	printf("是否继续查询(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	prilist();
	else if(a == 'n' || a == 'N')
	menu22(); 
}
void menu23()
{
	system("cls");
	int a;
    printf("\n++++++++订房方式选择++++++++\n"); 
	printf("\t1.按房间号订房\n");
	printf("\t2.按房间类别订房\n");
	printf("\t3.返回上一级\n");
	printf("\t4.退出\n");
	printf("请输入你需要的选项前的数字:");
	scanf("%d", &a);
	system("cls");
	switch(a)
	{
		case 1:numget();break;
		case 2:typget();break;
		case 3:menu1();break;
		case 4:exit(0);
		default:printf("此选项不存在");
	}
	menu23();
}
void numget()
{
	int slot, n, d;
	char a; 
	printf("输入你需订房间的房间号：");
	scanf("%d", &slot);
	if(room[slot-1].black[0] == 'N')
	{
		room[slot-1].black[0] = 'Y';
		printf("1.日租房\t\t2.钟点房\n"); 
		printf("请选择你需要的租房方式前的数字：");
		scanf("%d", &n);
		if(n == 1)
		{
		    printf("请输入你要入住的天数：");
		    scanf("%d", &d);
			allmoney = allmoney + d * room[slot-1].price[n-1]; 
		} 
		else if(n==2)
		{
			printf("请输入你要入住的小时数：");
		    scanf("%d", &d);
			allmoney = allmoney + d * room[slot-1].price[n-1]; 
		}
		else
		printf("不存在这种租房方式！\n");
		save(); 		 
	}
	else if(room[slot-1].black[0] == 'Y')
	printf("此房间已租出,请选择其他房间！\n");
	else
	printf("出现未知错误，请查看数据检错！\n"); 
	printf("是否需要订其他房间(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	numget();
	else if(a == 'n' || a == 'N')
	menu23();
}
void typget()
{
	int n, d;
	char a, slot;
	register int t;
	printf("（A.标准房  B.单人房  C.大床房）\n"); 
	printf("输入你需订房间的房间类型前的大写英文：");
	scanf("%s", &slot);
	for(t = 0; t < MAX;t++)
	{
		if(slot == room[t].type[0])
		{
			if(room[t].black[0] == 'N')
	        {
		        room[t].black[0] = 'Y';
		        printf("你的房间号为：%d\n", room[t].number);
		        printf("1.日租房\t\t2.钟点房\n"); 
		        printf("请选择你需要的租房方式前的数字：");
		        scanf("%d", &n);
		        if(n == 1)
		        {
		            printf("请输入你要入住的天数：");
		            scanf("%d", &d);
			        allmoney = allmoney + d * room[t].price[n-1]; 
	            } 
		        else if(n==2)
		        {
	                printf("请输入你要入住的小时数：");
		            scanf("%d", &d);
			        allmoney = allmoney + d * room[t].price[n-1]; 
		        }
		        else
	            printf("不存在这种租房方式！\n");
	            save();
				break; 		 
            }   
            else if(room[t].black[0] == 'Y')
            continue;
	        else
	        printf("出现未知错误，请查看数据检错！\n");
			break; 
		}
	}
	printf("是否需要订其他房间(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	numget();
	else if(a == 'n' || a == 'N')
	menu23();
}
void back()
{
	int slot, n, d;
	char a; 
	printf("输入你需退房间的房间号：");
	scanf("%d", &slot);
	if(room[slot-1].black[0] == 'Y')
	room[slot-1].black[0] = 'N';
	else if(room[slot-1].black[0] == 'N')
	printf("此房间已退！\n");
	else
	printf("出现未知错误，请查看数据检错！\n");
	save(); 
	printf("是否需要退其他房间(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	numget();
	else if(a == 'n' || a == 'N')
	menu23();
} 
void save()
{          
    system("cls");    
    FILE *fp;
    register int t;
	if((fp=fopen("酒店信息","wb"))==NULL)
	{
	    printf("不能打开文件！\n");
	    return;
	}
	fwrite(&allmoney, sizeof(int), 1, fp);
	for(t = 0; t < MAX; t++)
	{
		if(*room[t].type)
		{
			if(fwrite(&room[t], sizeof(struct hotel), 1, fp) != 1)
			printf("文件中无数据写出！\n"); 
		}
	}
	fclose(fp); 
	menu1();
}
void load()
{
	system("cls");    
    FILE *fp;
    register int t;
	if((fp=fopen("酒店信息","rb"))==NULL)
	{
	    printf("不能打开文件！\n");
	    return;
	}
	init();
	fread(&allmoney,sizeof(int), 1, fp);
	for(t = 0; t < MAX; t++)
	{
	    if(fread(&room[t], sizeof(struct hotel), 1, fp) != 1)
	    {
    		if(feof(fp))
    		break;
			printf("文件中无数据读入！\n"); 
		}
	}
	fclose(fp);
	menu1();
} 
void check()
{
	char a;
	printf("\n++++++++账单++++++++\n"); 
	printf("目前收入合计：%d\n", allmoney);
	printf("是否返回上级菜单(y/n)：");
	scanf("%s", &a);
	if(a == 'y' || a == 'Y')
	menu1();
	else if(a == 'n' || a == 'N')
	exit(0);
}
void checkzero()
{
	system("cls");
	register int t;
	allmoney = '\0';
	for(t = 0; t < MAX; t++)
	{
		if(room[t].black[0] == 'Y')
		room[t].black[0] = 'N'; 
	} 
	menu1(); 
}