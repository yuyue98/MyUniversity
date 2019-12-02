#ifndef ARCTU_H
#define ARCTU_H

typedef struct arcnode
{
    int adjvex;
    int weight;
    struct arcnode *nextart;
}arcnode;

typedef struct vnode
{
    int degree;
    char data;
    arcnode *firstarc;
}vnode, *adjlist;

typedef struct algraph
{
    adjlist vertices;
    int dinnum, biannum;
}algraph;

int initgraph(algraph *G);
int initadjlist(adjlist V);
int buildbian(adjlist V, int dinnum);
int outputljlist(algraph *G);
int dfstraverse(algraph *G);
int bfstraverse(algraph *G);

#endif