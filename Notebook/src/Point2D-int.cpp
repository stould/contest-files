const double EPS = 1e-9;
const double PI = acos(-1);

double DEG_to_RAD(double theta) {
    return theta*PI/180.;
}

double RAD_to_DEG(double theta) {
    return theta*180. / PI;
}

struct Point {
    int x, y;

    Point() {}
    Point(int x, int y): x(x), y(y) {}
    
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
        if(x == r.x) return y < r.y;
        return x < r.x;
    }
    
    bool operator==(const Point& r) const {
        return (x == r.x && y == r.y);
    }

    Point operator-(const Point& r) const {
        return Point(x-r.x, y-r.y);
    }
};
