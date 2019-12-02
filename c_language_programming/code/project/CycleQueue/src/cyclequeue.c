#include "myheader.h"
#include "cyclequeue.h"

status menu(squeue q)
{
	system("cls");
	int b;
	qelemtype e;
	int i;
	printf("当前队列为："); 
	for(i = 0;i < 6;i++)
	{
		printf("%d ", q.base[i]);
	}
	printf("\n"); 
	printf("1.将队列清为空队列\n");
	printf("2.求队列的的长度\n");
	printf("3.在队尾插入元素\n");
	printf("4.删除队头元素\n");
	printf("5.销毁此队列并退出\n");
	printf("请输入你要选择的操作前的序号：");
	scanf("%d", &b);
	getchar();
	switch(b)
	{
	    case 1:clearqueue(&q);break;
		case 2:printf("%d", queuelengh(&q));break;
		case 3:enqueue(&q);break;
		case 4:dequeue(&q,&e);break;
		case 5:destroyqueue(&q);break;
		default:printf("不存在此选项！");break;
	} 
	return OK;
}

status initqueue(squeue *q)
{//初始化队列q，q为空队列
    int i;
	(*q).base = (qelemtype *)malloc(MAX * sizeof(qelemtype));
	if (!(*q).base) 
	{
		printf("分配内存失败！\n"); 
	    exit(OVERFLOW);
	}//储存分配失败 
	(*q).front = (*q).rear = 0;
    (*q).base[(*q).rear] = BLANK;
	return OK;
}

status clearqueue(squeue *q)
{//将q清为空队列
    if((*q).base[(*q).rear] == BLANK)
    {
	    printf("此为空队列无需清空！\n");
		char b;
		printf("此队列为空，是否返回主菜单(y/n):");
		scanf("%c", &b);
		getchar(); 
		if(b == 'y' || b == 'Y')
		menu(*q);
		else
		return ERROR;
    }
	(*q).front = (*q).rear = 0; 
	(*q).base[(*q).rear] = BLANK;
	return OK;
}

status queuelengh(squeue *q)
{// 返回Q的元素个数,即队列的长度 
	return ((*q).rear - (*q).front + MAX) % MAX;
}

status enqueue(squeue *q)
{// 插入元素e为Q的新的队尾元素
    qelemtype e;
	if (((*q).rear % MAX == (*q).front) && (*q).base[(*q).front] != BLANK)// 队列满
	{
		char b;
		printf("此队列已满，是否返回主菜单(y/n):");
		scanf("%c", &b);
		getchar();
		if(b == 'y' || b == 'Y')
		menu(*q);
		else
		return ERROR;
	}
	
	printf("请输入数据：");
	scanf("%d", &e);
	(*q).base[(*q).rear] = e;
	(*q).rear = ((*q).rear + 1) % MAX;
	menu(*q);
	return OK;
}

status dequeue(squeue *q, qelemtype *e)
{// 若队列不空,则删除Q的队头元素,用e返回其值,并返回OK;否则返回ERROR 
	if (((*q).rear % MAX == (*q).front) && (*q).base[(*q).front] == BLANK)// 队列空
	{
		char b;
		printf("此队列为空，是否返回主菜单(y/n):");
		scanf("%c", &b);
		getchar();
		if(b == 'y' || b == 'Y')
		menu(*q);
		else
		return ERROR;
	}
	*e = (*q).base[(*q).front];
	(*q).front = ((*q).front + 1) % MAX;
	if ((*q).front == (*q).rear)
	(*q).base[(*q).rear] = BLANK;
	menu(*q);
	return OK;
}

status destroyqueue(squeue *q)
{//销毁队列q，q不再存在
    if ((*q).base)
    free((*q).base);
    (*q).base = NULL;
    (*q).front = (*q).rear = 0;
    char b;
    printf("此队列已销毁，是否初始化队列(y/n):");
    scanf("%c", &b);
	getchar();
	if(b == 'y' || b == 'Y')
	{
		initqueue(q); 
	    menu(*q);
    } 
	else
	return ERROR;
}