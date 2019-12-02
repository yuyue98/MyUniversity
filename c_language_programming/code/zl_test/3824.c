#include<stdio.h>
#include<math.h>
int main()
{
	float x1, y1, x2, y2, x, y, a;
	scanf ("%f %f %f %f", &x1 , &y1, &x2, &y2);
	x = x1 - x2;
	y = y1 - y2;
	if (x < 0)
	x = -x ;
	if (y < 0)
	y = -y;
	a = sqrt(pow(x,2) + pow(y,2));
	printf ("%.2f", a);
	return 0;
}