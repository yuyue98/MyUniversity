#include<iostream>
using namespace std;
int main()
{
	int i,j,k,n,m,a[100][100],b[100][100],c[100][100],d[100][100];
	cout<<"请输入矩阵阶数:";
	cin>>n;
	cout<<"请输入邻接矩阵a:"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	}
/*0 1 0 1 0
0 0 0 0 1
0 1 0 1 0
0 0 0 0 1
1 0 1 0 0*/
    for(i=0;i<n;i++)  //矩阵d为零矩阵
	{
		for(j=0;j<n;j++)
			d[i][j]=0;
	}
	for(m=0;m<n;m++)
	{
		for(i=0;i<n;i++)  //矩阵c为零矩阵
		{
			for(j=0;j<n;j++)
				c[i][j]=0;
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
					c[k][i] += b[k][j]*a[j][i];  //矩阵的乘法运算
				}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				b[i][j]=c[i][j];
				d[i][j]=d[i][j]+b[i][j];
			}
		}
		cout<<"m为"<<m+1<<",矩阵b为:"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<b[i][j]<<"  ";
			cout<<endl;
		} 
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(d[i][j]!=0)
				d[i][j]=1;
	}
	cout<<"可达矩阵d为:"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<d[i][j]<<"  ";
		cout<<endl;
	} 
	system("pause");
	return 0;
}
