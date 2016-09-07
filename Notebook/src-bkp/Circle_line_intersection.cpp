#include <bits/stdc++.h>
using namespace std;

/*
  Given a circle with center C(x0, y0) and radius r,
  a line determined by the equation y = mx + b, check if there is 
  a intersection then get the intersection points;;  
*/

const double EPS = 1e-9;
const double PI = acos(-1);

struct point {
    double x, y;

    point() {}
    point(double x, double y): x(x), y(y) {}

    bool operator<(const point& r) const {
        if(abs(x - r.x) < EPS) return y < r.y;
        return x < r.x;
    }
    
    bool operator==(const point& r) const {
        return abs(x - r.x) < EPS &&
               abs(y - r.y) < EPS;
    }
    
    point operator-(const point& r) const {
        return point(x - r.x, y - r.y);
    }
};

vector<point> cl_intersection(point& P, double r, double m, double b) {
    double p = P.x, q = P.y;
    
    double A = m*m + 1;
    double B = 2*(m*b - m*q - p);
    double C = (q*q - r*r + p*p - 2*b*q + b*b);

    double delta = B*B - 4*A*C;

    vector<point> ans;
    if(delta > 0) {
        double ax = (-B + sqrt(delta)) / (2*A);
        double bx = (-B - sqrt(delta)) / (2*A);

        ans.push_back(point(ax, m*ax + b));
        ans.push_back(point(bx, m*bx + b));
    } else if(delta == 0) {
        double ax = (-B) / (2*A);

        ans.push_back(point(ax, m*ax + b));
    }

    return ans;
}

int main(void) {
    point c = point(0, 0);
    vector<point> p = cl_intersection(c, 5, 1, 1);

    for(int i=0; i<p.size(); i++) {
        cout << p[i].x << " " << p[i].y << "\n";
    }
    
    return 0;
}
