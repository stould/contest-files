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

const int INF = INT_MAX / 3;

struct Point {
    int x;
    int y;
};
 
bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
 
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0; 
 
    return (val > 0)? 1: 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
	
	if (o1 != o2 && o3 != o4) {
		if (!o4) {
			return false;
		}
		if (!o3) {
			if (o4 != 1) {
				return false;
			}
		}
		return true;
	}
 
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; 
}

 // Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(vector<Point> polygon, int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;

    // Create a point for line segment from p to infinite
    Point extreme = {INF, p.y};

    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        if (doIntersect(polygon[i], polygon[(i+1)%n], p, extreme))
        {
            if (onSegment(polygon[i], p, polygon[(i+1)%n]))
                return true;
            count++;
        }
        i = (i + 1)%n;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}
 
int T;
vector<Point> P;
Point R;

int main(void) {
	scanf("%d", &T);
	for ( ; T--; ) {
		P.resize(4);
		for (int i = 0; i < 4; i++) {
			scanf("%d%d", &P[i].x, &P[i].y);
		}
		scanf("%d%d", &R.x, &R.y);
		printf("%d\n", isInside(P, 4, R) ? 1 : 0);
	}
    return 0;
}
