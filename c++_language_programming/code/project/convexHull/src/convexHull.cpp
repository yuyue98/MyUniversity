#include "myheader.h"
#include "convexHull.h"

using namespace std;

extern point ch[100], p[100];

double cross(point a, point b) {
	return a.x *  b.y - a.y* b.x;
}

int convex_hull(point *p, int n){
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		while (m > 1 && cross(p[i] - ch[m - 1], ch[m - 1] - ch[m - 2]) > 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && cross(p[i] - ch[m - 1], ch[m - 1] - ch[m - 2]) > 0) m--;
		ch[m++] = p[i];	
	}		
	if (n > 1) m--;
	return m;
}