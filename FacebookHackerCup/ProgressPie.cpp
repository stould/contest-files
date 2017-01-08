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
typedef unsigned long long uInt;
typedef unsigned uint;

const double EPS = 1e-5;
int T, P, X, Y;

const double PI = acos(-1);

double DEG_to_RAD(double theta) {
    return theta*PI/180.;
}

double RAD_to_DEG(double theta) {
    return theta*180. / PI;
}

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y): x(x), y(y) {}
    
    // vector (0, 0) -> (x, y)
    double mod() { return hypot(x, y); }
    double angle() { return atan2(y, x); }
    double dist(Point p) {
        return hypot(x - p.x, y - p.y);
    }
    // rotate point by theta degrees CCW r.t. origin
    void rotate(double theta) {
        theta = DEG_to_RAD(theta);
        x = x * cos(theta) - y * sin(theta);
        y = x * sin(theta) + y * cos(theta);
    }

    bool operator<(const Point& r) const {
        if(fabs(x-r.x) < EPS) return y < r.y;
        return x < r.x;
    }
    
    bool operator==(const Point& r) const {
        return (fabs(x-r.x) < EPS && fabs(y-r.y) < EPS);
    }

    Point operator-(const Point& r) const {
        return Point(x-r.x, y-r.y);
    }
};

struct Vector {
    double x, y;

    Vector() {}
    Vector(double x, double y): x(x), y(y) {}
    Vector(Point p1, Point p2) { // vector p1 -> p2
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }

    double mod() { return hypot(x, y); }
    double angle(Vector v) {
        return acos(dot(v) / (mod() * v.mod()));
    }
    void scale(double s) {
        x *= s;
        y *= s;
    }    
    // translate p in the direction of this vector
    void translate(Point& p) { 
        p.x += x;
        p.y += y;
    }
    double dot(Vector v) {
        return (x * v.x + y * v.y);
    }
    double cross(Vector v) {
        return (x * v.y - y * v.x);
    }
};


int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> P >> X >> Y;

        double ds = hypot(X, Y);

        cout << "Case #" << t << ": ";
        if (P == 0) {
            cout << "white" << endl;
        } else if (ds + EPS > 100) {
            cout << "white" << endl;
        } else {
            Vector a(0, 50);
            Vector b(X - 50, Y - 50);

            double ang = RAD_to_DEG(b.angle(a));
            
            if (ang <= P * 360 / 100.0) {
                cout << "black" << endl;
            } else {
                cout << "white" << endl;
            }
        }
    }
    return 0;
}
