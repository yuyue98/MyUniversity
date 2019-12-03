#ifndef CONVEXHULL_H
#define CONVEXHULL_H

struct point {
	double x, y;
	point (double x = 0, double y = 0) :x(x),y(y) {
	}
	point operator + (const point &rhs) const {
		return point(x + rhs.x, y + rhs.y);
	}
	point operator - (const point &rhs) const {
		return point(x - rhs.x, y - rhs.y);
	}
	bool operator < (const point &rhs) const {
		if (x == rhs.x) return y < rhs.y;
		return x < rhs.x;  
	}
};

double cross(point a, point b);
int convex_hull(point *p, int n);

#endif