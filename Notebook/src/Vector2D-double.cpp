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
