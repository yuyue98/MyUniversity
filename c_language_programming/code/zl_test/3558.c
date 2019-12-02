#include<stdio.h>
#include<string.h>
int ttt(int n);
int main()
{
	int a, s;
	while (scanf("%d",&a) != EOF)
	{
	    s = ttt(a);
	    printf("%d",s);
	}
   	return 0;
}
int ttt(int n)
{
	int a, b, t, i;
	char s[100];
	i = 0;
	do
	{
		a = n % 2;
		n = n / 2;
		s[i] = a;
	}while(n >= 1);
	t = strlen(s) -1;
	for (i = t;i >= 0;i--)
	printf("%d\n",s[i]);
	return t;
}