#include<stdio.h>
int main()
{
	int y, m, d, n;
	scanf ("%d-%d-%d", &y, &m, &d);
	n = (m - 1) * 30 + d;
	if ((y % 4== 0 && y % 100 != 0)||(y % 400 == 0))
	{
	     if (m == 1) 
	     n = n;
	     else if (m == 2)   
	     n = n + 1;
	     else if (m == 3) 
	     n = n;
	     else if (m == 4)   
	     n = n + 1;
	     else if (m == 5) 
	     n = n + 1;
	     else if (m == 6)   
	     n = n + 2;
	     else if (m == 7) 
	     n = n + 2;
	     else if (m == 8)   
	     n = n + 3;
	     else if (m == 9) 
	     n = n + 4;
	    else if (m == 10)   
	     n = n + 4;
	     else if (m == 11) 
	     n = n + 5;
	     else if (m== 12)   
	     n = n + 5;   	
	}
	else
	{
		 if (m == 1) 
	     n = n;
	     else if (m == 2)   
	     n = n + 1;
	     else if (m == 3) 
	     n = n - 1;
	     else if (m == 4)   
	     n = n;
	     else if (m == 5) 
	     n = n;
	     else if (m == 6)   
	     n = n + 1;
	     else if (m == 7) 
	     n = n + 1;
	     else if (m == 8)   
	     n = n + 2;
	     else if (m== 9) 
	     n = n + 3;
	    else if (m== 10)   
	     n = n + 3;
	     else if (m == 11) 
	     n = n + 4;
	     else if (m == 12)   
	     n = n + 4;
	}
	printf ("%d\n",n);
    return 0;
}