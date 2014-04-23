#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

double EPS = 1e-7;
double PI = acos(-1.0);

int N;
double xx1, xx2, xx3, yy1, yy2, yy3;

struct point {
	double x, y;
	
	point() {}
	point(double x, double y): x(x), y(y) {}
	
	bool operator<(const point& p) const {
		return (fabs(x - p.x) > EPS) ? x < p.x : y < p.y;
	}
};

struct vec {
	double xp, yp;

	vec() {}

	vec(point p1, point p2) {
		xp = p2.x - p1.x;
		yp = p2.y - p1.y;
	}

	double norm(void) {
		return sqrt(xp * xp + yp * yp);
	}
	
	double dot(const vec& v) {
		return xp * v.xp + yp * v.yp;
	}

	double angle(vec& v) {
		return acos(dot(v) / norm() * v.norm());
	}
};

struct line {
	double m, b;
	bool vert, hori;

	line() {}

	line(double mm, double bb, bool vvert, bool hhori) {
		m = mm;
		b = bb;
		vert = vvert;
		hori = hhori;
	}
	
	line(const point& p1, const point& p2) {
		m = (p2.y - p1.y) / (p2.x - p1.x);
		
		if (p2.x - p1.x == 0) {
			vert = true;
		} else {
			vert = false;
		}

		if (p2.y - p1.y == 0) {
			hori = true;
		} else {
			hori = false;
		}

		b = p1.y - m * p1.x;
	}

	pair<bool, pair<double, double> > intersect(line& l) {
		if ((vert && l.ver) || (hori && l.hori)) {
			return make_pair(false, make_pair(0.0, 0.0));
		} else {
			if (vert) {
				return make_pair(true, make_pair(x, l.m * x + l.b));				
			} else if (l.vert) {

			}

			double x = (l.b - b) / (m - l.m);
			double y = m * x + b;
			
			return make_pair(true, make_pair(x, y));				
		}
	}
};


int main(void) {
	cin >> N;

	for ( ; N--; ) {
		point p1, p2, p3;

        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

		vec v1(p1, p2), v2(p2, p3), v3(p1, p3);

		double ansx = -1.0, ansy = -1.0, dist = -1.0;

		if (v1.angle(v2) == PI / 2.0) {
			ansx = (p1.x + p3.x) / 2.0;
			ansy = (p1.y + p3.y) / 2.0;
		} else if (v2.angle(v3) == PI / 2.0) {
			ansx = (p1.x + p2.x) / 2.0;
			ansy = (p1.y + p2.y) / 2.0;
		} else if (v1.angle(v3) == PI / 2.0) {
			ansx = (p2.x + p3.x) / 2.0;
			ansy = (p2.y + p3.y) / 2.0;
		} else {
			double xm1 = (xx1 + xx2) / 2.0, ym1 = (yy1 + yy2) / 2.0;
			double xm2 = (xx2 + xx3) / 2.0, ym2 = (yy2 + yy3) / 2.0;
			
			if (xx1 + xx2 == 0.0) xm1 = 0.0;
			if (xx2 + xx3 == 0.0) xm2 = 0.0;
			if (yy1 + yy2 == 0.0) ym1 = 0.0;
			if (yy2 + yy3 == 0.0) ym2 = 0.0;
			
			double slope1 = -1.0 / ((yy2 - yy1) / (xx2 - xx1));
			double slope2 = -1.0 / ((yy3 - yy2) / (xx3 - xx2));
		
			double b1 = ym1 - slope1 * xm1;
			double b2 = ym2 - slope2 * xm2;
			
			ansx = (b2 - b1) / (slope1 - slope2);
			ansy = ansx * slope1 + b1;
		}
		dist = hypot(ansx - p1.x, ansy - p1.y);
		printf("%.3lf %.3lf %.3lf\n", ansx, ansy, dist);   
    }

    return 0;
}

