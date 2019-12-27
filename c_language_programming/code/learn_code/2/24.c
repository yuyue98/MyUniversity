#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mysql.h>
#pragma  comment(lib,"libmysql.lib")

/*定义数据库相关操作变量*/
MYSQL mysql;          //
MYSQL_RES *result;    //定义结果集变量
MYSQL_ROW row;        //定义行变量
char ch[2];

void ShowAll();       /*显示所有的图书信息*/
void AddBook();       /*添加图书信息*/
void ModifyBook();    /*修改图书信息*/
void DeleteBook();    /*删除图书信息*/
void QueryBook();     /*查询图书信息*/

/*显示菜单*/
void showmenu()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t╔══════════════════════════════════════════════════════╗\n");
    printf("\t║            Welcome To Lemon Books System             ║\n");
    printf("\t╠══════════════════════════════════════════════════════╣\n");
    printf("\t║            1 - show all                              ║\n");
    printf("\t║            2 - add book                              ║\n");
    printf("\t║            3 - modify book                           ║\n");
    printf("\t║            4 - delete book                           ║\n");
    printf("\t║            5 - query book                            ║\n");
    printf("\t║            6 - exit                                  ║\n");
    printf("\t╚══════════════════════════════════════════════════════╝\n");
    printf("\n              ENTER YOUR CHOICE(1-6):");
    
}

void inquire()  /*询问用户是否显示主菜单*/
{
    printf("\t Show Main Meun?(y/n):");
    scanf("%s",ch);
    if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要显示查找到的信息*/
    {
        showmenu();   /*显示菜单*/ 
    }
    else
    {
        exit(0);
    }
}

/*显示主菜单，连接数据库*/
int main()
{
    int n ;   //定义变量  存储用户输入的编号
    
    mysql_init(&mysql);  //初始化mysql结构
    
    showmenu();   /*显示菜单*/ 
    
    scanf("%d",&n);/*输入选择功能的编号*/
    
    while(n)
    { 
        switch(n)
        {
            case 1: 
                ShowAll();    /*调用显示所有图书数据的过程*/
                break;
            case 2: 
                AddBook();   /*添加图书信息*/
                break;
            case 3: 
                ModifyBook();     /*修改图书信息*/
                break;
            case 4:
                DeleteBook();   /*删除图书信息*/
                break;
            case 5:
                QueryBook();   /*查询图书信息*/
                break;
            case 6:
                exit(0);       /*退出*/
            default:break;
        }
        scanf("%d",&n);
    }
}



void ShowAll()    /*调用显示所有图书数据的过程*/
{
    /*连接数据库*/
    if(!mysql_real_connect(&mysql,"127.0.0.1","root","","db_books",0,NULL,0))
    { 
        printf("\n\t Can not connect db_books!\n");
    }
    else
    {
        /*数据库连接成功*/
        if(mysql_query(&mysql,"select * from tb_book"))
        {   //如果查询失败
            printf("\n\t Query tb_book failed !\n");
        }
        else
        {
            result=mysql_store_result(&mysql); //获得结果集
            if(mysql_num_rows(result)!=(my_ulonglong)0)
            {  //有记录的情况,只有有记录取数据才有意义
                printf("\t ════════════════════════════ \n");
                printf("\t                 Show All The Books                       \n");
                printf("\t ════════════════════════════ \n");
                printf("\t    ID     BookName         Author        Bookconcern     \n");
                printf("\t -------------------------------------------------------- \n");
                while((row=mysql_fetch_row(result)))
                {   //取出结果集中记录
                    fprintf(stdout,"\t   %s        %s          %s            %s   \n",row[0],row[1],row[2],row[3]);  //输出这行记录
                }
                printf("\t ════════════════════════════ \n");
            }
            else
            {
                printf("\n\t No record !\n");
            }
            mysql_free_result(result);    //释放结果集
        }
        mysql_close(&mysql);          //释放连接
    }
    inquire();   /*询问是否显示主菜单*/
}

void AddBook()    /*添加图书信息*/
{
    int rowcount;   /*结果集中的行数*/
    
    char id[10];       /*编号*/
    char *bookname;
    char *author;
    char *bookconcern;
    
    char *sql;    
    char dest[500] ={"  "};    
    
    /*连接数据库*/
    if(!mysql_real_connect(&mysql,"127.0.0.1","root","","db_books",0,NULL,0))
    { 
        printf("\n\t Can not connect db_books!\n");
    }
    else
    {
        /*数据库连接成功，插入数据*/   
        printf("\t ════════════════════════════ \n");
        printf("\t                        Add  Books                        \n");
        printf("\t ════════════════════════════ \n");
        if(mysql_query(&mysql,"select * from tb_book"))
        {   //如果查询失败
            printf("\n\t Query tb_book failed!\n");
        }
        else
        {
            result=mysql_store_result(&mysql); //获得结果集
            rowcount=mysql_num_rows(result) ;  //获得行数
            row=mysql_fetch_row(result);       //获取结果集的行  
            
            printf("\t ID:");
            scanf("%s",id);   /*输入图书编号*/    
            
            sql="insert into tb_book (ID,bookname,author,bookconcern) values (";
            strcat(dest,sql);
            strcat(dest,"'");
            strcat(dest,id);
            strcat(dest,"', '");


            if(mysql_num_rows(result)!=(my_ulonglong)0)
            {                
                /*判断输入的编号是否存在*/
                do
                {   //存在相同编号
                    if(!strcmp(id,row[0]))
                    {
                      //  printf("%s",row[0]);
                        printf("\n\t the record is existing,press any to continue!\n");
                        getch();
                        mysql_free_result(result);   /*释放结果集*/ 
                        mysql_close(&mysql);         /*释放连接*/  
                        inquire();   /*询问是否显示主菜单*/
                        return;
                    }
                }while(row=mysql_fetch_row(result));  
            }
            
            bookname = (char*)malloc(50);
            author = (char*)malloc(50);
            bookconcern = (char*)malloc(50);

            
            //不存在相同的编号            
            printf("\t BookName:");
            scanf("%s",bookname);   /*输入图书名*/
            strcat(dest,bookname);    /*将图书编号追加到sql语句后面*/
            
            printf("\t Author:");
            scanf("%s",author);    /*输入作者*/
            strcat(dest,"', '");
            strcat(dest,author);
            
            printf("\t Bookconcern:");
            scanf("%s",bookconcern);    /*输入出版社*/
            strcat(dest,"', '");
            strcat(dest,bookconcern);
            strcat(dest,"')");
            //printf("%s",dest);
            
            if ( mysql_query(&mysql,dest)!=0)   
            {
                fprintf(stderr,"\t Can not insert record!",mysql_error(&mysql));
            }
            else
            {
                printf("\t Insert success!\n");                
            }
            mysql_free_result(result);    //释放结果集
        }
        mysql_close(&mysql);          //释放连接
    }
    inquire();   /*询问是否显示主菜单*/
}   

void ModifyBook()   /*修改图书信息*/
{
    char id[10];   /*结果集中的行数*/
    char *sql;    
    char dest[500] ={"  "};
    char dest1[500] ={"  "};
    
    char *bookname;
    char *author;
    char *bookconcern;
    
    if (!mysql_real_connect(&mysql,"127.0.0.1","root","","db_books",0,NULL,0))
    {
        printf("\t Can not connect db_books!\n");
    }
    else
    {
        /*数据库连接成功*/
        // printf("连接成功");
        printf("\t please input ID which record you want to modify.");
        
        scanf("%s",id);   /*输入图书编号*/
        sql = "select * from tb_book where id=";
        strcat(dest,sql);
        strcat(dest,id);    /*将图书编号追加到sql语句后面*/
        
        //printf("%s\n",dest);
        
        /*查询该图书信息是否存在*/
        if(mysql_query(&mysql,dest))
        {   //如果查询失败
            printf("\n  Query tb_book failed! \n");
        }
        else
        {
            result=mysql_store_result(&mysql); //获得结果集
            if(mysql_num_rows(result)!=(my_ulonglong)0)
            {
                //有记录的情况,只有有记录取数据才有意义
                printf("\t find the record,show?(y/n) ");
                scanf("%s",ch);
                if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要显示查找到的信息*/
                {
                    printf("\t ════════════════════════════ \n");
                    printf("\t                 ***** Show  Book *****                   \n");
                    printf("\t ════════════════════════════ \n");
                    printf("\t    ID     BookName         Author        Bookconcern     \n");
                    printf("\t -------------------------------------------------------- \n");
                    while((row=mysql_fetch_row(result)))
                    {   //取出结果集中记录
                        fprintf(stdout,"\t   %s        %s          %s            %s   \n",row[0],row[1],row[2],row[3]);  //输出这行记录
                    }
                    printf("\t ════════════════════════════ \n");
                }
                
                
                printf("\t Modify?(y/n)");
                scanf("%s",ch);
                if (strcmp(ch,"Y")==0||strcmp(ch,"y")==0)    /*判断是否需要录入*/
                {

 
                    sql = "update tb_book set bookname= '";
                    strcat(dest1,sql);
                    //   printf("%s",sql);
                    bookname = (char*)malloc(20);
                    author = (char*)malloc(20);
                    bookconcern = (char*)malloc(20);

                    printf("\t BookName:");
                    scanf("%s",bookname);   /*输入图书名*/
                    
                    strcat(dest1,bookname); 
                    //  printf("%s",&bookname);

                    printf("\t Author:");
                    scanf("%s",author);    /*输入作者*/
                    strcat(dest1,"', author= '");
                    strcat(dest1,author);    /*追加sql语句*/                        
                    
                    printf("\t Bookconcern:");
                    scanf("%s",bookconcern);    /*输入图书单价*/
                    strcat(dest1,"', bookconcern = '");
                    strcat(dest1,bookconcern);    /*追加sql语句*/
                    
                    strcat(dest1,"' where id= ");
                    strcat(dest1,id);                        
                    
                    //printf("%s",dest1);

                    if(mysql_query(&mysql,dest1)!=0)
                    {   
                        fprintf(stderr,"\t Can not modify record!\n",mysql_error(&mysql));                            
                    }
                    else
                    {
                        printf("\t Modify success!\n");
                    }
                }
                
            }
            else
            {
                printf("\t can not find!\n");
            }
        }
        mysql_free_result(result);          //释放结果集
    }
    mysql_close(&mysql);     //释放连接
    inquire();   /*询问是否显示主菜单*/
}

void DeleteBook()   /*删除图书信息*/
{
    char id[10];   /*结果集中的行数*/
    char *sql;
    char dest[100] ={"  "};
    char dest1[100] ={"  "};
    if(!mysql_real_connect(&mysql,"127.0.0.1","root","","db_books",0,NULL,0))
    {
        printf("\t Can not connect db_books!\n");
    }
    else
    {
        printf("\t please input ID which record you want to delete. ");        
        scanf("%s",id);   /*输入图书编号*/
        sql = "select * from tb_book where id=";
        strcat(dest,sql);
        strcat(dest,id);    /*将图书编号追加到sql语句后面*/        
        //printf("%s\n",dest);
        
        /*查询该图书信息是否存在*/
        if(mysql_query(&mysql,dest))
        {   //如果查询失败
            printf("\n Query tb_book failed! \n");
        }
        else
        { 
            result=mysql_store_result(&mysql); //获得结果集
            if(mysql_num_rows(result)!=(my_ulonglong)0)
            {  //有记录的情况,只有有记录取数据才有意义
                printf("\t find the record,show?(y/n) ");
                scanf("%s",ch);
                if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要显示查找到的信息*/
                {
                    printf("\t ════════════════════════════ \n");
                    printf("\t                 ***** Show  Book *****                   \n");
                    printf("\t ════════════════════════════ \n");
                    printf("\t    ID     BookName         Author        Bookconcern     \n");
                    printf("\t -------------------------------------------------------- \n");
                    while((row=mysql_fetch_row(result)))
                    {   //取出结果集中记录
                        fprintf(stdout,"\t   %s        %s          %s            %s   \n",row[0],row[1],row[2],row[3]);  //输出这行记录
                    }
                    printf("\t ════════════════════════════ \n");
                }
                                    
                    printf("\t Delete ?(y/n) ");
                    scanf("%s",ch);
                    if (strcmp(ch,"Y")==0||strcmp(ch,"y")==0)    /*判断是否需要录入*/
                    {
                        sql = "delete from tb_book where ID= ";
                        printf("%s",dest1);
                        strcat(dest1,sql);
                        strcat(dest1,id);
                       // printf("%s",dest1);
                        
                        if(mysql_query(&mysql,dest1)!=0)
                        {
                            fprintf(stderr,"\t Can not delete \n",mysql_error(&mysql));
                        }
                        else
                        {
                            printf("\t Delete success!\n");
                        }
                    }
            }
            else
            {
                printf("\t Can not find the record!\n");
            }
        }
        mysql_free_result(result);    //释放结果集
    }
    mysql_close(&mysql);
    inquire();   /*询问是否显示主菜单*/
}

void QueryBook()   /*查询图书信息*/
{     
    char id[10];   /*结果集中的行数*/
    char *sql;
    char dest[100] ={"  "};
    
    if(!mysql_real_connect(&mysql,"127.0.0.1","root","","db_books",0,NULL,0))
    {
        printf("\t Can not connect db_books!\n");
    }
    else
    {  
        printf("\t please input ID which record you want to query:");        
        scanf("%s",id);   /*输入图书编号*/
        sql = "select * from tb_book where id=";
        strcat(dest,sql);
        strcat(dest,id);    /*将图书编号追加到sql语句后面*/        
        
        if(mysql_query(&mysql,dest))
        {   //如果查询失败
            printf("\n Query tb_book failed!\n");
        }
        else
        {
            result=mysql_store_result(&mysql); //获得结果集
            if(mysql_num_rows(result)!=(my_ulonglong)0)
            {  //有记录的情况,只有有记录取数据才有意义
                printf("\t ════════════════════════════ \n");
                printf("\t                          Show  Book                      \n");
                printf("\t ════════════════════════════ \n");
                printf("\t    ID     BookName         Author        Bookconcern     \n");
                printf("\t -------------------------------------------------------- \n");
                while((row=mysql_fetch_row(result)))
                {   //取出结果集中记录
                    fprintf(stdout,"\t   %s        %s          %s            %s   \n",row[0],row[1],row[2],row[3]);  //输出这行记录
                }
                printf("\t ════════════════════════════ \n");                
            }
            else
            {
                printf("\t Can not find the record!\n");
            }
            mysql_free_result(result);    //释放结果集
        }
        mysql_close(&mysql);          //释放连接
    }
    inquire();   /*询问是否显示主菜单*/
}