#include<stdio.h>
int main()
{
        float r,h,v;
        float pi=3.1415926;
        scanf("%f%f",&r,&h);
        v=2*pi*r*r+2*pi*r*h;
        printf ("Area=%.3f\n",v);
}