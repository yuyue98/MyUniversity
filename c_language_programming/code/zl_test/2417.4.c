#include<stdio.h>
int main(){
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31},x,i,y,m,d;
	scanf("%d-%d-%d", &y, &m, &d);
	if(y%400==0||(y%4==0&&y%100!=0)){
		a[1]=29;
	}
	x=0;
	for(i=0;i<m-1;i++){
		x = x + a[i];
	}
	x = x + d;
	printf("%d\n", x);
	return 0;
}