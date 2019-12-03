#include "myheader.h"
#include "convexHull.h"

using namespace std;

point ch[100], p[100];

int main(int argc, char* argv[]) {
    /**
     * The c++ language project main program
     */
    int n=5;
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	int m = convex_hull(p, n);
	cout<<m<<endl;
	for (int i = 0; i < m; i++) {
		printf("x %f y %f\n", ch[i].x, ch[i].y);
	}
    system("pause");
    return 0;
}