#include "stdio.h"

int main(int argc, char* argv[]) {
    /**
     * The c language main program
     */
    int m, n;
	int i;
	printf("请分别输入m，n：");
	scanf("%d%d", &m, &n);
	if (m>n)
	printf("错误提示：m大于n\n");
	for (i=m;i<=n;i++)
	printf("第%d个值为：%d^2+1/%d=%f\n", i-m+1, i, i, i*i+1.0/i);

    system("pause");
    return 0;
}
