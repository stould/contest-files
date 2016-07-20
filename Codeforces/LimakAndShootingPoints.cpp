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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const double EPS = 1e-7;
const double PI = acos(-1);
const double INF = 1001000001001010010.0;
 
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
 
// line of the form ax + by + c = 0
struct Line {
    double a, b, c;
 
    Line() {}
    Line(double a, double b, double c): a(a), b(b), c(c) {}
    Line(Point p1, Point p2) {
        if(p1.x == p2.x) { // vertical line treatment
            this->a = 1.;
            this->b = 0.;
            this->c = -p1.x;
        } else {
            this->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            this->b = 1.; // easier using b = 1
            this->c = -(double)(a * p1.x) - ( b * p1.y);
        }
    }
    bool operator<(const Line& other) const {
        if (fabs(a - other.a) > EPS) {
            return a < other.a;
        } else if (fabs(b - other.b) > EPS) {
            return b < other.b;
        } else {
            return c < other.c;
        }
    }
    bool contains(Point p) { // check if p is on the line
        return ( a*p.x +  b*p.y + c) < EPS;
    }
 
    bool parallel(Line r) { // checking a and b
        return (fabs( a-r.a) < EPS && fabs( b-r.b) < EPS);
    }
    bool collinear(Line r) { // now checking c
        return ( parallel(r) && fabs( c-r.c) < EPS);
    }
 
    // if there is put intersect point on p
    bool intersect(Line r, Point& p) {
        if( collinear(r)) return false; // infinite points
        if( parallel(r)) return false; // no point
       
        p.x = (double) (r.b *  c -  b * r.c) / (r.a *  b -  a * r.b);
 
        if( b > EPS) { // check if it is not a vertical line
            p.y = -(a * p.x + c) /  b;
        } else { // vertical line treatment
            p.y = -(r.a * p.x + r.c) / r.b;
        }        
        return true;
    }
};

int K, N;
Point PK[10];
Point PN[1010];
int fine[1010], alive[1010];
int se[10];

int main(void) {
    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        se[i] = i;
        cin >> PK[i].x >> PK[i].y;
    }
    for (int i = 0; i < N; i++) {
        cin >> PN[i].x >> PN[i].y;
        fine[i] = 1;
    }

    do {
        memset(alive, 1, sizeof(alive));
        
        for (int i = 0; i < K; i++) {
            map<Line, vector<int> > cnt;
            
            for (int j = 0; j < N; j++) {
                Line now(PK[se[i]], PN[j]);
                cnt[now].push_back(j);
            }
            
            for (auto& it: cnt) {
                vector<int> pos = it.second;

                if (it.first.b == 1) {
                    int best_l = -1;
                    int best_r = -1;
                    
                    double dl = INF;
                    double dr = INF;
                    
                    for (int j = 0; j < (int) pos.size(); j++) {
                        double now = PK[se[i]].dist(PN[pos[j]]);

                        if (alive[pos[j]] == 0) continue;
                        
                        if (PN[pos[j]].x > PK[se[i]].x) {                    
                            if (dr > now) {
                                dr = now;
                                best_r = pos[j];
                            }
                        } else {
                            if (dl > now) {
                                dl = now;
                                best_l = pos[j];
                            }
                        }
                    }
                    if (best_l != -1) {
                        alive[best_l] = 0;
                    }
                    if (best_r != -1) {
                        alive[best_r] = 0;
                    }
                } else {
                    int best_l = -1;
                    int best_r = -1;
                    
                    double dl = INF;
                    double dr = INF;
                    
                    for (int j = 0; j < (int) pos.size(); j++) {
                        double now = PK[se[i]].dist(PN[pos[j]]);

                        if (alive[pos[j]] == 0) continue;
                        
                        if (PN[pos[j]].y > PK[se[i]].y) {                    
                            if (dr > now) {
                                dr = now;
                                best_r = pos[j];
                            }
                        } else {
                            if (dl > now) {
                                dl = now;
                                best_l = pos[j];
                            }
                        }
                    }
                    //cout << best_l << " " << best_r << "\n";
                    if (best_l != -1) {
                        alive[best_l] = 0;
                    }
                    if (best_r != -1) {
                        alive[best_r] = 0;
                    }
                }
            }
            for (int j = 0; j < N; j++) {
                if (!alive[j]) {
                    fine[j] = 0;
                }
            }        
        }
    } while (next_permutation(se, se + K));

    int ans = 0;
        
    for (int i = 0; i < N; i++) {
        if (!fine[i]) {
            ans += 1;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
