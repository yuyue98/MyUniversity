#ifndef KUAIPAI_H
#define KUAIPAI_H

typedef struct cjnode
{
    int number;
    char xuehao[14];
    char xingming[8];
    int chengji;
}cjnode;

typedef struct cjlist
{
    cjnode *student;
    int length;
}cjlist;

void init_cjlist(cjlist *S);
void dg_kuaipai(cjlist *S, int low, int high, int (*paixu)(cjlist*,int,int));
int paixu_cj(cjlist *S, int low, int high);
int paixu_xh(cjlist *S, int low, int high);

#endif