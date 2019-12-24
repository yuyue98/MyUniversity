#include <stdio.h>					/*I/O函数*/
#include <stdlib.h>				/*其他说明*/
//#include <alloc.h>  					/*动态地址分配函数*/
#include <string.h>   				/*字符串函数*/
#include <conio.h>   				/*屏幕操作函数*/
#include <Windows.h>
#define M 3						/*定义共有的课程数目*/
#define FORMAT "|%6d|%15s|%.2f|%.2f|%.2f|%.2f|%d|\n"
#define DATA p->snum,p->name,p->score[0].sc,p->score[1].sc,p->score[2].sc,p->sum, p->rank
int flag=0;
typedef struct cnode{				/*定义选课先决条件结点*/
    int num;						/*选课前应先学习的课程顺序*/
    struct cnode *next				;/*下一个结点*/
    }Cnode;						/*定义结点数据结构*/
typedef struct{ 						/*定义课程项目*/
    int cnum;						/*课程号*/
    char cname[20];				/*课程名称*/
    int credit;						/*学分*/
    int indegree;
    Cnode *first;					/*表结点的头结点*/
    }Cour;						/*定义课程项目数据结构*/
typedef Cour Course[M];
typedef struct {						/*定义成绩数据结构*/
    Cour *cp;						/*指向课程的指针*/
    float sc;						/*该课程的成绩*/
    }Score						;/*成绩数据结构*/
typedef struct snode{				/*定义表示学生结点*/
    int snum;						/*学号*/
    char name[20];					/*姓名*/
    Score score[M];				/*成绩*/
    float sum;						/*总分*/
    float average;					/*平均分*/
    int rank;						/*名次*/
    struct snode *next;				/*下一个结点地址*/
    }Student;						/*学生成绩结点的数据结构定义*/
/*课程管理中实现*/
void init_c(Course *);	/*课程数据结构建立以及课程录入或者打开，保存课程原始记录到文件*/
void sort_c(Course *);				/*所有课程的上课顺序*/
void plan_c(Course *);				/*每学期课程上课安排*/
/*成绩管理系统实现*/
void input_g(Student *,Cour *);			/*成绩录入*/
void ave_g(Student*);				/*成绩总和计算*/
void sort_g(Student*);				/*成绩排序，同时保存排序文件*/
void filt_g(Student*);					/*成绩分类搜索*/
void print_g(Student*);				/*成绩输出*/
/*学生管理系统实现*/
Student * init_s();					/*学生记录初始化，第一次建立保存，也可以打开*/
void manag_s();					/*学生成绩管理*/
int sear_s(Student *);				/*学生记录查询*/
Student *appe_s(Student *);			/*学生记录添加*/
Student *modi_s(Student *);			/*学生记录修改*/
Student *dele_s(Student *);			/*学生记录删除*/
void save_s(Student *);				/*学生记录保存*/

void gotoxy(HANDLE hOut, int x, int y);
int  print();
int  menu(char *m[],int n);
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);