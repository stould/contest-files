struct Circle {
    Point center;
    double radius;

    Circle() {}
    Circle(Point _center, double _radius) {
        center = _center;
        radius = _radius;
    }

    bool has_inside(Point p) {
        return hypot(p.x - center.x, p.y-center.y) < radius + EPS;
    }
};

vector<Point> points;

double cross(Point o, Point a, Point b) {
    return ((a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x));
}

Circle make_diameter(Point p, Point q) {
    Point center((p.x + q.x) / 2., (p.y + q.y) / 2.);
    double radius = hypot(p.x - q.x, p.y - q.y) / 2.;
    return Circle(center, radius);
}

bool make_circumcircle(Circle& ans, Point a, Point b, Point c) {
    double ax = a.x, ay = a.y;
    double bx = b.x, by = b.y;
    double cx = c.x, cy = c.y;

    double d = (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) * 2.0;
    if(d == 0.0) return false;
    double xc = ((ax * ax + ay * ay) * (by - cy) + 
                 (bx * bx + by * by) * (cy - ay) + 
                 (cx * cx + cy * cy) * (ay - by)) / d;
    double yc = ((ax * ax + ay * ay) * (cx - bx) + 
                 (bx * bx + by * by) * (ax - cx) + 
                 (cx * cx + cy * cy) * (bx - ax)) / d;
    ans = Circle(Point(xc, yc), hypot(xc - ax, yc - ay));
    return true;
}

Circle make_circle_two_points(int right, Point p, Point q) {
    Circle diameter = make_diameter(p, q);
    
    bool ok = true;
    for(int i=0; i<=right; i++) {
        if(!diameter.has_inside(points[i])) {
            ok = false;
            break;
        }
    }

    if(ok) return diameter;

    Circle l, r;
    bool nonel = true, noner = true;
    for(int i=0; i<=right; i++) {
        double cr = cross(p, q, points[i]);
        Circle c;
        if(!make_circumcircle(c, p, q, points[i])) continue;

        if(cr > 0.0 && 
           (nonel || cross(p, q, c.center) > cross(p, q, l.center))) {
            l = c;
            nonel = false;
        } 
        else if(cr < 0.0 && 
                (noner || cross(p, q, c.center) < cross(p, q, r.center))) {
            r = c;
            noner = false;
        }
    }
    if(noner || (!nonel && l.radius <= r.radius)) return l;
    return r;
} 

Circle make_circle_one_point(int right, Point p) {
    Circle ans(p, 0.0);
    for(int i=0; i<=right; i++) {
        if(!ans.has_inside(points[i])) {
            if(ans.radius == 0.0) {
                ans = make_diameter(p, points[i]);
            } else {
                ans = make_circle_two_points(i, p, points[i]);
            }
        }
    }
    return ans;
}

Circle make_circle(vector<Point> points) {
    Circle ans;
    bool none = true;

    for(int i=0; i<points.size(); i++) {
        if(none || !ans.has_inside(points[i])) {
            ans = make_circle_one_point(i, points[i]);
            none = false;
        }
    }
    return ans;
}
