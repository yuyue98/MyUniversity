#include <iostream>
#include <iomanip> 
#include <cmath>
#include <string.h>
#include "student.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main (int argc, char** argv) {
//	水仙花数 
	int sum, num, s;
	for (int i=100;i<=999;i++) {
		sum = 0;
		num = i;
		while (num) {
			s = num%10;
			num = num/10;
			sum += s*s*s;
		}	
		if (sum==i) {
			cout<<sum<<' ';
		}
	} 
	cout<<endl;
	system("pause");
//	韩信点兵 
//	int a, b, c;
//	int x, y, z;
//	while (true) {
//		cin>>a>>b>>c;
//		if (a>=3||b>=5||c>=7) continue;
//		for (int i=10;i<=100;i++) {
//			x = (i-a)%3==0;
//			y = (i-b)%5==0;
//			z = (i-c)%7==0;
//			if (x&&y&&z) {
//				cout<<i<<endl;
//				break; 
//			} else if (i==100) {
//				cout<<"No answer"<<endl;
//			}
//		}
//	}
//	倒三角形
//	int num, gum;
//	int n;
//	while (true) {
//		cin>>n;
//		for (int i=n;i>0;i--) {
//			gum = 2*i-1;
//			num = n-i;
//			while(num--) {
//				cout<<' ';
//			}
//			while(gum--) {
//				cout<<'#';
//			}
//			cout<<endl;
//		}
//	}
//	子序列的和
//	double sum;
//	int n, m;
//	while (true) {
//		sum = 0;
//		cin>>n>>m;
//		if (n==0&&m==0) break;
//		for (int i=n;i<=m;i++) sum += 1.0/pow(i,2);
//		cout<<setprecision(5)<<sum<<endl;
//	}
//	分数化小数
//	int a, b, c;
//	while (true) {
//		cin>>a>>b>>c;
//		if (!a&&!b&&!c) break;
//		cout<<setprecision(c)<<1.0*a/b<<endl;
//	}
//	排列
//	写法一 
//	int abc, def, ghi, num;
//	int a[10];
//	int flag;
//	for (int i=123;i<330;i++) {
//		flag = true;
//		for (int j=0;j<10;j++) a[j] = 0;
//		abc = i;
//		def = 2*i;
//		ghi = 3*i;
//		while (abc||def||ghi) {
//			if (abc) {
//				num = abc%10;
//				abc /= 10;
//				if (num&&!a[num]) a[num]++;
//				else flag = false;	
//			} else if (def) {
//				num = def%10;
//				def /= 10;
//				if (num&&!a[num]) a[num]++;
//				else flag = false;
//			} else if (ghi) {
//				num = ghi%10;
//				ghi /= 10;
//				if (num&&!a[num]) a[num]++;
//				else flag = false;
//			}
//			if (!flag) {
//				break;
//			}
//		}
//		if (flag) {
//			cout<<i<<' '<<2*i<<' '<<3*i<<endl;
//		}
//	}
//	写法二 
//	int n, i, j;
//    char a[10];
//	for(n = 123; n < 330; n++){
//		sprintf(a, "%d", n * 1000000 + n * 2 * 1000 + n * 3);
//
//		for(j = 0, i = '1'; i <= '9'; memchr(a, i++, 9) && j++);
//
//		if (j == 9) {
//			printf("%d %d %d \n", n, n * 2, n * 3);
//		}
//	}
//	结果 
//192 384 576
//219 438 657
//273 546 819
//327 654 981

	return 0;
}
