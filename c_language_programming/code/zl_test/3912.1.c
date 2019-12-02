#include <stdio.h>
int main()
{
char s[80];
int i,count=0;
while (gets(s)!=NULL)
{
count=0;
if(s[0]>='a'&&s[0]<='z'||s[0]>='A'&&s[0]<='Z')
count++;
for(i=0;s[i]!='\0';i++)
{
if(s[i]==' '&&s[i+1]>='a'&&s[i+1]<='z')
count++;
if(s[i]==' '&&s[i+1]>='A'&&s[i+1]<='Z')
count++;
}
printf("%d\n",count);
}
return 0;
}