const double INF = 1e20;
const double EPS = 1e-9;
const double PI = acos(-1);

double DEG_to_RAD(double theta) {
    return theta * PI / 180.0;
}

double RAD_to_DEG(double theta) {
    return theta * 180.0 / PI;
}

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y): x(x), y(y) {}

    void read() { scanf("%lf %lf", &x, &y); }
    
    // vector (0, 0) -> (x, y)
    double mod() { return hypot(x, y); }
    double angle() { return atan2(y, x); }
    Point operator + (const Point& r) const { return Point(x+r.x, y+r.y); }
    Point operator - (const Point& r) const { return Point(x-r.x, y-r.y); }
    Point operator / (const double& t) const { return Point(x / t, y / t); }
    
    double dist(Point p) {
        return hypot(x - p.x, y - p.y);
    }

    // rotate point by theta degrees CCW r.t. origin
    void rotate(double theta) {
        theta = DEG_to_RAD(theta);
        double x1 = x * cos(theta) - y * sin(theta);
        double y1 = x * sin(theta) + y * cos(theta);
        x = x1;
        y = y1;
    }
    // rotate point by theta degrees CCW r.t. point p
    void rotate(double theta, Point p) {
        Point q(x - p.x, y - p.y);
        q.rotate(theta);
        q = q + p;        
        x = q.x;
        y = q.y;
    }

    bool operator<(const Point& r) const {
        if(fabs(x-r.x) < EPS) return y < r.y;
        return x < r.x;
    }
    
    bool operator==(const Point& r) const {
        return (fabs(x-r.x) < EPS && fabs(y-r.y) < EPS);
    }
};
