#ifndef CYCLEQUEUE_H
#define CYCLEQUEUE_H

#define status int
#define qelemtype int

typedef struct lnode 
{
	qelemtype *base;
	int front;
	int rear;
}squeue;

status menu(squeue q);
status initqueue(squeue *q);//初始化队列q，q为空队列 
status clearqueue(squeue *q);//将q清为空队列 
status queuelengh(squeue *q);//返回q的元素个数,即队列的长度
status enqueue(squeue *q);//插入元素e为q的新的队尾元素 
status dequeue(squeue *q, qelemtype *e);
// 若队列不空,则删除q的队头元素,用e返回其值,并返回OK;否则返回ERROR
status destroyqueue(squeue *q);//销毁队列q，q不再存在

#endif