#include <stdio.h>
#define PI 3.141592654 
 
void menu();
void ball_cal();
void cylind_cal();
void cone_cal();

int main(int argc, char *argv[])
{
	int number;
	while(1)
	{
		menu();
		printf("请输入计算命令：");
		number=getchar();
		getchar();
		switch(number)
		{
			case '1':ball_cal();break;
			case '2':cylind_cal();break;
			case '3':cone_cal();break;
			default:exit(0);
		}
	}
	return 0;
}

void menu()
{
	printf("1-计算球体体积 2-计算圆柱体体积 3-计算圆锥体体积 其他-退出运行\n");
}

void ball_cal()
{
	float r;
	printf("请输入球体的半径：");
	scanf("%f", &r);
	getchar();
	printf("球体体积为：%.2f\n", 4.0/3.0*PI*r*r*r);
}

void cylind_cal()
{
	float r, h;
	printf("请分别输入圆柱体的底圆半径r和高h：");
	scanf("%f%f", &r, &h);
	getchar();
	printf("圆锥体体积为：%.2f\n", PI*r*r*h);
}

void cone_cal()
{
	float r, h;
	printf("请分别输入圆锥体的底圆半径r和高h：");
	scanf("%f%f", &r, &h);
	getchar();
	printf("圆锥体体积为：%.2f\n", PI*r*r*h/3.0);
}
