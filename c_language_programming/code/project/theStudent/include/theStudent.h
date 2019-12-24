#include"theStudentHead.h"

int  print() {									/*开始界面设计*/
    int n;
    system("cls");           							/*清屏*/
    printf("\n\n");
    printf("\t*************************************************************\n");
    printf("\t*                                                           *\n");
    printf("\t*                                                           *\n");
    printf("\t*                                                           *\n");
    printf("\t*----------------WELCOME TO ACADEMIC SYSTEM !---------------*\n");
    printf("\t*                                                           *\n");
    printf("\t*                 1:STUDENT MANAGEMENT                      *\n");
    printf("\t*                 2:COURSE  MANAGEMENT                      *\n");
    printf("\t*                 0:Exit  MANAGEMENT                        *\n");
    printf("\t*                                                           *\n");
    printf("\t*************************************************************\n");
    printf("\t\tNow please select 1,2 or 0: ");
    scanf("%d",&n);getchar();
    return n;
}
int  menu(char *m[],int n) {
    int i;
    int select;
    system("cls"); 									/*清屏幕*/
    gotoxy(hOut,1,1);             					/*移动光标*/
    //textcolor(WHITE);   						/*设置文本显示颜色为白色*/
    //textbackground(BLUE);   					/*设置背景颜色为蓝色*/
    gotoxy(hOut,19,2);          						/*移动光标*/
    putch(0xc9);        						/*输出左上角边框┏*/
    for(i=1;i<44;i++)
        putch(0xcd);    					/*输出上边框水平线*/
    putch(0xbb);            						/*输出右上角边框  ┓*/
    for(i=3;i<20;i++){
        gotoxy(hOut,19,i);
        putch(0xba);   						/*输出左垂直线*/
        gotoxy(hOut,63,i);
        putch(0xba);							/*输出右垂直线*/
    }  
    gotoxy(hOut,19,20);
    putch(0xc8);  					/*输出左下角边框┗*/
    for(i=1;i<44;i++)
        putch(0xcd);      						/*输出下边框水平线*/
    putch(0xbc);                 				/*输出右下角边框┛*/
    //window(20,3,62,19);       /*制作显示菜单的窗口，大小根据菜单条数设计*/
    system("cls");              						/*清屏*/
    for(i=0;i<n;i++){       						/*输出主菜单数组*/
        gotoxy(hOut,8,i+4);
        printf("%s",m[i]);
    }
    //textbackground(BLACK);   					/*设置背景颜色为黑色*/
    //window(1,1,80,25);       					/*恢复原窗口大小*/
    gotoxy(hOut,10,21);           					/*移动光标*/
    do{
        printf("\n\t\t     Enter your choice(0~%d) to continue...",n-2);
        scanf("%d",&select); getchar();          		/*输入选择项*/
    }while(select<0||select>n);    				/*选择项不在0~13之间重输*/
    return select;	              	/*返回选择项，主程序根据该数调用相应的函数*/
}
Student *init_s(){			/*学生记录初始化，第一次建立文件，也可以从文件中打开*/
    Student *head,*p,*last;	/*定义建立链表的工作指针*/
    Student s;
    char c;				/*选择变量*/
    FILE *fp;
    char fname[20];
    for(int i = 0; i < 20; i++)
    {
        fname[i] = 0;
    }
    int i;
    system("cls"); 
    printf("do you creat  new file (y/n)?");
    c=getchar();getchar();	/*选择是否建立新的文件*/
    if (c=='Y'|| c=='y') {		/*输入y那么新建文件*/
        printf("input new student filename:");
        gets(fname);		/*输入文件名*/
        if ((fp=fopen(fname,"wb"))==NULL) {/*文件打开失败*/
            printf("can not open file.\n");
            return NULL;	/*返回主调函数*/
        }
        do {		/*输入多个学生信息存入磁盘，当输入编号为-1的时候，结束录入*/
            printf("input the student number:");
            scanf("%d",&s.snum); getchar();
            if (s.snum!=-1) {				/*输入学号不是-1*/
                printf("input the  name :");
                gets(s.name);getchar();		/*输入姓名*/
                for (i=0;i<M;i++){			/*成绩指针初始化*/
                    s.score[i].cp=NULL;
                    s.score[i].sc=0;
                }
                s.sum=0;					/*总成绩清空*/
                s.rank=-1;
                s.next=NULL;
                fwrite(&s,sizeof(Student),1,fp);/*写入文件*/
            }
            else break;					/*退出循环*/
        }while ( 1);
        fclose (fp);						/*关闭文件*/
    }
    head=(Student *)malloc(sizeof(Student)) ;		/*建立单链表头结点*/
    head->next=NULL;
    last=head;								/*last指向链表头结点地址*/
    printf("\nopen the student file,input the filename:");
    gets(fname);							/*输入姓名信息*/
    fp=fopen(fname,"rb") ; 					/*以读的方式打开文件*/
    if(fp==NULL)  {
        printf("\ncan not open file!\n");
        return NULL;
    }
    while(!feof(fp)){						 	/*从文件中读出记录放到链表中存放*/
        p=( Student*)malloc(sizeof(Student));		/*建立结点*/
            if(fread(p,sizeof(Student),1,fp)==1) { 	/*一次从文件中读取一条学生的记录*/
                p->next=NULL;					/*尾插法建立链表*/
                last->next=p;
                last=p;
            }
    }
    fclose (fp);
    last->next=NULL						;/*最后一个结点指针为空*/
    return  head;  						/*返回读出的数据库文件的指针*/
}
/*成绩管理系统实现*/
void input_g(Student *head,Cour *hg){		/*成绩录入*/
    Student *p;
    float x1,x2,x3;
    p=head->next;						/*指向首元结点*/
    system("cls"); 
    while (p){							/*单链表不空*/
        printf("input the first term score:");
        scanf("%f%f%f",&x1,&x2,&x3);		/*录入每个学生的学期成绩*/
        p->score[0].sc=x1;
        p->score[1].sc=x2;
        p->score[2].sc=x3;
        p->sum=x1+x2+x3				;/*计算成绩和*/
        p->score[0].cp=hg;				/*该门课程的课程信息*/
        p->score[1].cp=hg+1;
        p->score[2].cp=hg+2;
        p=p->next;					/*指针后移*/
    }
    save_s(head);
    getch();
}

void ave_g(Student*head){			/*计算某一科的平均成绩*/
    Student *p,*q;
    int i,n=0;						/*设定变量n计算每门课参考的人数*/
    float sa=0;						/*设定变量sa计算课程的平均值*/
    system("cls"); 
    q=head->next;					/*保存首元结点的信息*/
    for (i=0;i<M;i++){				/*访问M门课程*/
        sa=0;n=0;					/*每一门课程计算前变量初始化*/
        p=head->next;				/*p指向首元结点*/
        while(p){					/*访问每个学生的该门课程*/
            n++;					/*统计*/
            sa+=p->score[i].sc;		/*课程值累加*/
            p=p->next;
        }
        sa=sa/n;					/*计算平均值*/
        printf(" %6s average %.2f\n",q->score[i].cp->cname,sa);/*输出课程平均成绩*/
    }
    getch();
}
void sort_g(Student *head){			/*成绩排序*/
    Student *p,*q,*r,*u;				/*定义排序的工作指针*/
    int re=1;
    p=head->next;					/*指向首元结点*/
    head->next=NULL;				/*置空链表,然后将原链表结点逐个插入到有序表中*/
    while (p) {						/*当链表尚未到尾，p为工作指针*/
        r=head;					/*保存头结点地址*/
        q=head->next;
        while (q && q->sum>=p->sum){	/*查p结点在链表中的插入位置， q是工作指针*/
            r=q;
            q=q->next;
        }
        u=p->next;
        p->next=r->next;			/*将p结点链入链表中*/
        r->next=p;					/*r是q的前驱，u是下个待插入结点的指针*/
        p=u;
    }
    p=head->next;					/*指向首元结点*/
    while(p){						/*访问链表中的每个结点*/
        p->rank=re++;				/*给出学生记录的名次*/
        p=p->next;
    }
    print_g(head);					/*输出信息*/
        flag=1;
    save_s(head);
    getch();
}
void  class1(Student *h){					 /*大于等于80分的记录*/
    Student *p;						/*定义工作指针*/
    int i;
    p=h->next;						/*指向首元结点*/
    system("cls"); 
    printf("|--number--|--name--  -|----subjuec----- -|---score----|\n");/*输出界面头*/
    while(p!=NULL)    {					/*结点访问不空*/
        for(i=0;i<M;i++) {				/*访问每个学生每门课的成绩*/
            if (p->score[i].sc>=80){		/*成绩大于80*/
                printf("|%4d|%15s|%15s|%.2f\n\n",p->snum,p->name,p->score[i].cp->cname,p->score[i].sc);
            }
        }
        p=p->next;						/*指向下一个记录*/
    }
    printf("\n\npress any key ...");
    getch();
}
void  class2(Student *h){ 				/*成绩大于等于60小于80分的记录*/
    Student *p;						/*定义工作指针*/
    int i;
    p=h->next;						/*指向首元结点*/
    system("cls"); 
    printf("|--number--|--name--  -|----subjuec----- -|---score----|\n");/*输出标题头*/
    while(p!=NULL)    {					/*单链表不空*/
        for(int i=0;i<M;i++) {				/*访问每门课成绩*/
            if (p->score[i].sc>=60 &&p->score[i].sc<=79 ){/*成绩大于等于60小于80*/
                printf("|%4d|%15s|%15s|%.2f\n\n",p->snum,p->name,p->score[i].cp->cname,p->score[i].sc);
            }
        }
        p=p->next;						/*访问下一个记录*/
    }
    printf("\n\n press any key ...");
    getch();
}
void  class3(Student *h){					 /*成绩小于60分的记录*/
    Student *p;
    int i;
    p=h->next;
    system("cls"); 
    printf("|--number--|----------name---------|--------subjuec-------- -|-------score-------|\n");
    while(p!=NULL)    {
        for(i=0;i<M;i++) {
            if (p->score[i].sc<60 )			/*成绩小于60*/
                printf("|%4d|%15s|%15s|%.2f\n\n",p->snum,p->name,p->score[i].cp->cname,p->score[i].sc);
        }
        p=p->next;
    }
    printf("\n\npress any key...");
    getch();
}
void filt_g(Student*head){					/*成绩分类搜索*/
    int select;
    char *m4[]={"************Display*********",  /*定义菜单字符串数组*/
        " 1. ....80=< Record <=100....",		/*成绩大于等于80小于等于100*/
        " 2. ....60=<  Record  <80....",		/*成绩大于等于60小于80*/
        " 3. ....No pass....",				/*成绩小于60*/
        " 0. ....return....",
    };
    while(1)    {						/*进入分类筛选界面*/
        system("cls"); 
        select=menu(m4,5);				/*调用分类筛选菜单*/
        if (select==0)
            break;
        switch(select) {      			 /*调用子菜单函数*/
        case 1:class1(head);break;/*筛选在大于等于80小于等于100之间的数据*/
        case 2:class2(head);break;
        case 3:class3(head);break;
        }
    }
}

void print_g(Student*head){		/*成绩输出*/
    Student *p;
    system("cls"); 
    p=head->next;/*指向首元结点*/
    printf("\n\n\n**********************************STUDENT***************************************\n");
    /*输出标题头*/
    printf("|No    |      name     |sc1|sc2|sc3| sum  |rank|\n");
    printf("|------|---------------|---|---|---|------|----|\n\n");
    while(p!=NULL){				/*链表中的结点不空*/
        printf(FORMAT,DATA);		/*输出相应的信息*/
        p=p->next;				/*指针后移*/
    }
    printf("************************************end*****************************************\n");
    getchar();
}
void save_s(Student *head)					/*学生记录保存*/
{
    FILE* fp;
    Student  *p;
    char   bname[30];
    printf("input the saving file name:");
    fflush(stdin);
    gets(bname);
    fp=fopen(bname,"wb");					/*以只写方式打开二进制文件*/
    if(fp==NULL){ /*打开文件失败*/
        printf("\n open file error!\n");
        return;
    }
    p=head->next;							 /*当前链表中所有数据写入内存*/
    while(p){
        fwrite(p,sizeof(Student),1,fp)			;/*每次写一条记录或一个节点至文件*/
        p=p->next;
    }
    fclose(fp); 								/*关闭此文件*/
}
int sear_s(Student *head){			/*学生记录查询*/
    int select;						/*1:按学号查，2：按姓名查，其他：返回*/
    Student *p;
    int num;
    char str[30];
    int f=0;
    if(!head->next)  {       			/*若链表为空*/
        system("cls");   				/*调用清屏函数清屏*/
        printf("\nThe student not exist!\n");
        getchar();
        return  NULL;
    }
    system("cls"); 
    printf("\n    1. Search by student number   2. Search by student name  \n");
    printf("      please choice[1,2]:  ");	/*选择信息*/
    scanf("%d",&select);  getchar();
    switch  (select) {		/*按姓名查询，可以查询同名记录，查询结果输出到屏幕上*/
    case 1:
        printf("input the student number:");
        scanf("%d",&num);
        p=head->next;
        while(p)     {
            if(p->snum==num) {	/*若找到输入的学号的地址*/
                printf("\n");
                printf(FORMAT,DATA);		/*输出信息*/
                getchar();
                f=1;						/*更改条件*/
                break;					/*结束循环*/
            }
            p=p->next;					/*访问下一个结点*/
        }
        getchar();
        break;							/*结束case分支*/
    case  2:			/*按照学号进行查询，查到所有姓名相同的学生信息，输出*/
        printf("input the student name:");
        gets(str);
        p=head->next;						/*指向首元结点*/
        while(p)     {
            if (strcmp(p->name,str)==0){		/*姓名比较*/
                f=1;					/*更改标志*/
                printf(FORMAT,DATA);
            }
            p=p->next;					/*结点后移*/
        }
        break;							/*结束case分支*/
    }
    getch();
    return f;
}
int check(Student *head,int num){		/*简单查询查找文件中是否有num学号相同的记录*/
    Student *p;
    p=head->next;
    while(p && p->snum!=num)		/*如果结点不空，依次比较条件*/
        p=p->next;				/*指针后移*/
    if (p) return 1;
    else return 0;
}
Student *appe_s(Student *head){		/*学生记录添加*/
    Student  *p,*r;   				/*实现添加操作的临时的结构体指针变量*/
    int num;
    float x1,x2,x3;
    system("cls"); 
    r=head;
    while(r->next!=NULL)
        r=r->next; 				/*将指针移至于链表最末尾，准备添加记录*/
    while(1) {
        /*一次可输入多条记录，直至输入学号为-1时结束记录结点添加操作*/
        /*输入学号，保证该学号没有被使用，若输入学号为-1，则退出添加记录操作*/
        printf("input the student num:");
        p=(Student *) malloc(sizeof(Student));
        scanf("%d",&p->snum); getchar();
        while ( check(head,p->snum) && p->snum!=-1){
            /*如果学号不存在同时学号不空，那么继续查询*/
            printf("the student already exist.input again:\n");
            scanf("%d",&p->snum);  getchar();
        }
        if (p->snum==-1){ 						/*输入为-1，则退出添加操作*/
            printf("the insert is over,press any key .... \n");
            getchar();
            break;
        }
        else {    								/*插入结点*/
            printf("input the student name :");
            gets(p->name);
            printf("input the first term score:");
            scanf("%f%f%f",&x1,&x2,&x3);
            p->score[0].sc=x1;p->score[1].sc=x2;	/*输入结点信息*/
            p->score[2].sc=x3;
            p->sum=x1+x2+x3;
            p->next=NULL;
            r->next =p;						/*插入单链表中*/
            r=p;
        }
    }
    flag=1;									/*更改标记*/
    system("cls"); 
    print_g (head);								/*输出*/
    save_s(head);
    return  head;
}
Student *dele_s(Student *head){			/*学生记录删除*/
    int select;
    Student *p,*r;
    char str[30];
    int num;
    if(!head->next){						/*如果链表无法打开*/
        system("cls"); 
        printf("\n No student record!\n");
        return   NULL;
    }
    system("cls"); 
    printf("\n           1 Delete by number       2 Delete by name\n");
    printf("       please choice[1,2]: ");
    scanf("%d",&select);   getchar();		/*输入选择标记*/
    if(select==1){						/*选择1，按照学号查找*/
        printf("input the student num:");
        scanf("%d",&num);
        r=head,p=head->next;			/*r为中间变量，保存头结点*/
        while(p && p->snum!=num)    {	/*循环查找*/
            r=p;						/*保存结点地址*/
            p=p->next;				/*结点指针后移*/
        }
        if (p) {						/*找到删除结点*/
            r->next=p->next;    		/*将p所指节点从链表中去除*/
            flag=1;
            free(p); 					/*释放内存空间*/
            printf("\ndelete success!\n");
            getchar();
        }
        else  {
            printf("\n no find.\n");
            getchar();
        }
    }
    else if(select==2){ 					/*先按姓名查询到该记录*/
        printf("input the book  name:");
        gets (str);						/*输入姓名信息*/
        r=head;	p=head->next;			/*查找初始化*/
        while(p && strcmp(p->name,str)!=0){	/*比较查找记录*/
            r=p;
            p=p->next;
        }
        if (p) {
            r->next=p->next;    		/*将p所指节点从链表中去除*/
            flag=1;
            free(p); 					/*释放内存空间*/
            printf("\ndelete success!\n");
            getchar();
        }
        else
            printf("\n no find.\n");
    }
    print_g(head);						/*输出修改信息*/
    getchar();
    return head;
}
Student *modi_s(Student *head){					/*学生记录修改*/
    Student  *p;
    int num;
    float x1,x2,x3;
    system("cls"); 
    printf("modify student recorder...\n");   			/*首先输出修改之前的所有记录*/
    printf("input the modify student number:");
    scanf("%d",&num);  getchar();
    p=head->next;								/*指向首元结点*/
    while(p && p->snum!=num)					/*查找是否存在*/
        p=p->next;
    if(p) {									/*若p!=NULL表明已经找到节点*/
        printf("input the  modify student name :");
        gets(p->name);							/*输入姓名*/
        printf("input the modify first term score:");
        scanf("%f%f%f",&x1,&x2,&x3);
        p->score[0].sc=x1;p->score[1].sc=x2;
        p->score[2].sc=x3;
        p->sum=x1+x2+x3;
        print_g(head);   						/*修改以后程序显示*/
        flag=1;								/*改变记录，更改标记*/
        getchar();
    }
    else
        printf("no find record.\n");
    getchar();
    return p;
}
void init_c(Course *g){ /*课程数据结构建立以及课程录入或者打开，保存课程原始记录到文件*/
    FILE *fp; 							/*设定指针保存课程信息文件地址*/
    char fname[20];
    int i,j,k,n;
    Cnode *s=NULL;
    system("cls"); 
    printf("input the course information.\n");
    printf("|no. |course |credit|\n");
    for(i=0;i<M;i++){					/*输入顶点*/
        scanf("%d %s",&(g[i]->cnum),g[i]->cname);
        scanf("%d",&g[i]->credit);
        g[i]->indegree=0;				/*顶点入度初始化*/
        g[i]->first=NULL; 				/*顶点单链表指针清空*/
    }
    printf("input number of course information : ");
    scanf("%d",&n);getchar();				/*读入边数*/
    printf("\ninput information of course:\n");	/*建立每个顶点的边的单链表*/
    for(k=0;k<n;k++) {
        scanf("%d%d",&i,&j);getchar();
        s=(Cnode *) malloc(sizeof(Cnode));	/*为单链表中结点分配空间*/
        s->num=j; 					/*保存课程先决条件的下标*/
        s->next=g[i]->first;				/*头插法建立单链表*/
        g[i]->first=s;
    }
    printf("save the course to file,open the file.\n");
    gets(fname);getchar();
    if ((fp=fopen(fname,"wb"))==NULL) {		/*打开文件*/
        printf("the  file can not open.\n");
        exit (0);
    }
    for(i=0;i<M;i++)
        fwrite(g+i,sizeof(Cour),1,fp); 		/*保存记录到文件*/
    fclose(fp);
}
int topsort[M];
int ts=0;
void sort_c(Course *g){					/*所有课程的上课顺序*/
    int i,j,top=-1;						/*设定top描述栈顶元素的下标*/
    Cnode *p;
    system("cls"); 
    for (i=0;i<M;i++){					/*计算图中每个顶点的入度*/
        p=g[i]->first;
        while (p) {						/*访问每个顶点的邻接链表,计算入度*/
            g[p->num]->indegree++;
            p=p->next;
        }
    }
    for (i=0;i<M;i++) {		/*如果某个顶点的入度为0,那么把顶点的入度域更改为栈*/
        if (g[i]->indegree==0) {
            g[i]->indegree=top;
            top=i;
        }
    }
    printf("the course arrange :\n");
    while (top!=-1) {						/*如果栈中的元素不空*/
        j=top;
        top=g[top]->indegree;
        printf("   %s \n",g[j]->cname);		/*访问入度为0的点*/
        topsort[ts++]=j;
        p=g[j]->first;
        while (p) {						/*更改此顶点所有相关边的入度*/
            i=p->num;
            g[i]->indegree--;
            if (g[i]->indegree==0) {		/*入度为0,继续进栈*/
                g[i]->indegree=top;
                top=i;
            }
            p=p->next;
        }
    }
    getch();
}
void plan_c(Course *g){					/*每学期课程上课安排*/
    int s=0; 							/*定义变量计算总学分*/
    char fname[20];
    FILE *fp;
    int i,j,k=0;
    system("cls"); 
    printf("open the course,input the filename \n");
    gets(fname);
    if ((fp=fopen(fname,"rb"))==NULL) {		/*打开文件*/
        printf("the  file can not open.\n");
        return;
    }
    for (i=0;i<M;i++)
        fread(g+i,sizeof(Cour),1,fp); 		/*从文件中读出课程信息*/
    sort_c(g);							/*排序*/
    for (i=0;i<M;i++)
        s+=g[i]->credit;					/*计算学分的和*/
    s=s/4; 							/*计算学分和的平均值*/
    j=1;
    for (i=0;i<M;i++) { 					/*平均分配各个学科*/
        k+=g[topsort[i]]->credit; 			/*计算读出课程的学分*/
        if (k<=s) {
            printf("the %d term course:",j);	/*选中学期的课程*/
            printf("   %d  %s\n   ",g[topsort[i]]->cnum,g[topsort[i]]->cname);
        }
        else { 						/*学分大于平均值*/
            j++; 						/*为下一个学期的学期课程*/
            k=0;
        }
    }
    getch();getch();
    fclose(fp);
}

void gotoxy(HANDLE hOut, int x, int y)
{ 
    COORD pos; 
    pos.X = x;  
    pos.Y = y; 
    SetConsoleCursorPosition(hOut, pos); /* 设置光标位置 */
}