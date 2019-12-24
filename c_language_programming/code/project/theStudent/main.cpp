// Cod14.cpp : Defines the entry point for the console application.
//
#include "theStudent.h"
#include <conio.h>

int main(){
    int i;
    char *m1[]={"*****Student System ******",  	/*定义菜单字符串数组*/
        " 1. Init list",    						/*初始化，从学生文件中打开学生记录*/
        " 2. Scorce management",   				/*学生成绩管理*/
        " 3. Search record ",   					/*按照姓名查找记录*/
        " 4. Append a record to list",    			/*在文件中追加记录*/
        " 5. Modefiy a record to list",    			/*修改记录*/
        " 6. Delete a record from list",  				/*从表中删除记录*/
        " 7. Save the file",          				/*将单链表中记录保存到文件中*/
        " 0. exit"          						/*返回主界面*/
    };
    char *m2[]={"*****Score System *****",  		/*定义成绩管理菜单字符串数组*/
        " 1. Init list",    						/*初始化，录入学生成绩到成绩文件*/
        " 2. Average of each subject",   			/*每个学生总成绩计算*/
        " 3. Sort and order ",   					/*按照总成绩排序*/
        " 4. filter score",    						/*按照分数段分类浏览*/
        " 5. Display  number  and score",    		/*浏览学生成绩*/
        " 0. return"          					/*返回学生管理菜单*/
    };
    char *m3[]={"*****Course System *****",  		/*定义课程管理菜单字符串数组*/
        " 1. Init list",    						/*初始化，建立或者读出所学课程表单*/
        " 2. Sort of course",   					/*所有课程上课顺序*/
        " 3. Plan  ",   							/*每个学期课程安排*/
        " 0. return"          					/*返回主界面*/
    };
    Student *heads=NULL;					/*学生文件信息内存中存储为链表*/
    Course hc;							/*课程信息存储为图*/
    FILE *fps,fpc;    						/*文件指针*/
    int s1,s2,s3;     						/*保存选择结果变量*/
    char ch;     							/*保存(y,Y,n,N)*/
    //textcolor(GREEN);						/*设置屏幕前景色*/
    system("cls"); 							/*清屏*/
    do {		/*开始界面中有三个功能，可以管理学生成绩记录和课程记录以及退出界面*/

        system("cls"); ;
        //textcolor(GREEN);
        s1=print();							/*调用开始管理界面*/
        if (s1==1)
        {						/*选择1进入学生成绩管理界面*/
            do {							/*进入管理学生成绩记录的菜单界面*/
                system("cls"); ;
                s2=menu(m1,9);			/*调用界面菜单*/
                if(s2==0)  
                {
                    if(flag==1)	/*若对链表数据有修改且未进行存盘操作则此标志为1*/
                        printf("\nWhether save the modified record to file?(y/n):");
                    scanf("%c",&ch);
                    if(ch=='y'||ch=='Y')	/*如果选择了y，表示要存盘*/
                        save_s(heads);
                    printf("the student system quit.\n");
                    break;
                }

                switch(s2)
                {				/*菜单命令选择*/
                case 1:heads=init_s();break;/*可以新建或者打开文件内容到内存*/
                case 2:
                    do {				/*循环的功能是进入成绩管理界面*/
                        system("cls"); ;
                        s3=menu(m2,7);/*调用成绩管理菜单*/
                        if (s3==0)		/*输入0表示输出*/
                            break;
                        switch(s3){	/*成绩处理菜单命令选择*/
                        case 1:input_g(heads,hc);break;
                            /*录入每门课的成绩和课程信息*/
                        case 2:ave_g(heads);break;	/*计算每科平均分*/
                        case 3:sort_g(heads);break;	/*为成绩排序*/
                        case 4:filt_g(heads);break;	/*分类成绩筛选*/
                        case 5:print_g(heads);break;	/*输出成绩*/
                        }
                    }while(1);
                    break;
                case 3:sear_s(heads);break;		/*查找某个学生的成绩*/
                case 4:heads=appe_s(heads);break;	/*追加记录*/
                case 5:heads=modi_s(heads);break;	/*修改记录*/
                case 6:heads=dele_s(heads);break;	/*删除记录*/
                case 7:save_s(heads);break;		/*保存到文件*/
                }
            }while(1);
        }
        else if (s1==2)
        {						/*选择2进入课程管理界面*/
            do {							/*循环管理课程*/
                system("cls"); ;
                s2=menu(m3,5);			/*调用课程管理菜单*/
                if (s2==0) {system("cls"); ; break;}
                switch(s2){
                case 1:init_c(&hc);break;	/*录入课程信息*/
                case 2:sort_c(&hc);break;	/*课程进度安排*/
                case 3:plan_c(&hc);break;	/*每个学期课程信息*/
                }
            }while(1);
        }
        else if (s1==0)
        {						/*选择0表示退出整个系统*/
            system("cls"); ;
            gotoxy(hOut,20,15);
            //textcolor(WHITE);
            printf("Press any key to exit.");
            getch();						/*敲入任意键，退出*/
            exit(0);
        }
    }while(1);

    CloseHandle(hOut); 
}

