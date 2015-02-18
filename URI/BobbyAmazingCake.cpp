#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int EPS = 1e-7;

int N;

struct point {
    int x, y;
    point(int x, int y): x(x), y(y){}
    point(){}
    bool operator <(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator==(const point &p) const {
        return x == p.x && y == p.y;
    }
};

struct line {
	point a, b;
	bool v, h;
	double ca, cl;

	line(const point _a, const point _b) {
		a = _a;
		b = _b;

		if (a.x == b.x) {
			h = true;
		} else {
			h = false;
		}
		if (a.y == b.y) {
			v = true;
		} else {
			v = false;
		}
		
		if (!h) {
			ca = (b.y - a.y) / (double) (b.x - a.x);
			cl = b.y - ca * b.x;
		}
	}	

	double lie(double x) {
		return x * ca + cl;
	}

	bool upper(point p) {
		double y_cord = p.x * ca + cl;
		if (y_cord >= p.y) {
			return true;
		} else {
			return false;
		}
	}
};

double dot(point &A, point &B, point &C) {
    return (double) (B.x - A.x) * (C.x - B.x) + (B.y - A.y) * (C.y - B.y);
}

double cross(point &A, point &B, point &C) {
    return (double) (B.x-A.x) * (C.y-A.y) - (B.y-A.y) * (C.x-A.x);
}

double _distance(point A, point B) {
    int d1 = A.x - B.x;
    int d2 = A.y - B.y;
    return sqrt(d1*d1+d2*d2);
}

double linePointDist(point A, point B, point C, bool isSegment) {
    double dist = cross(A,B,C) / _distance(A,B);
    if(isSegment) {
        int dot1 = dot(A,B,C);
        if(dot1 > 0)return _distance(B,C);
        int dot2 = dot(B,A,C);
        if(dot2 > 0)return _distance(A,C);
    }
    return abs(dist);
}


point P[110];

int main(void) {
	for ( ; cin >> N && N != 0; ) {
		for (int i = 0; i < N; i++) {
			cin >> P[i].x >> P[i].y;
		}
		
		double ans = 100101001001001010.0;
		
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				line lin = line(P[i], P[j]);
			
				if (fabs(lin.lie(0.0)) < EPS) {
					continue;
				}
				
				double l = 0.0, r = 0.0;
				
				for (int k = 0; k < N; k++) {
					if (i != k && j != k) {
						if (lin.upper(P[k])) {
							l += linePointDist(P[i], P[j], P[k], false);
						} else {
							r += linePointDist(P[i], P[j], P[k], false);
						}
					}
				}
				
				ans = min(ans, fabs(l - r));
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
