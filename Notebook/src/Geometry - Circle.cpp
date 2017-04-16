struct Circle {
    Point center;
    double radius;

    Circle() {}
    Circle(double x, double y, double _radius) {
        center = Point(x, y);
        radius = _radius;
    }
    Circle(Point p1, Point p2, Point p3) {
        Line r(p1, p2), s(p2, p3);
 
        Point med1 = (p1 + p2) / 2.;
        Point med2 = (p2 + p3) / 2.;
        Line r1 = r.perpendicular(med1);
        Line s1 = s.perpendicular(med2);
 
        if(!r1.intersect(s1, center)) {
            center = Point(-1, -1);
            radius = -1;
        } else {
            radius = center.dist(p1);
        }
    }

    // theta is the central angle in degrees
    double area(double theta = 360.0) {
        return PI * radius * radius * (theta / 360.0);
    }
    double arc_length(double theta = 360.0) {
        return 2.0 * PI * radius * (theta / 360.0);
    }
    
    // region of a circle cut off by a chord or secant
    double segment_area(double theta) {
        theta = DEG_to_RAD(theta);
        return radius * radius * (theta - sin(theta)) / 2.0;
    }
    double chord_length(double theta) {
        theta = DEG_to_RAD(theta);
        return 2.0 * radius * sin(theta / 2.0);
    }
    // distance between chord and the arc, aka flecha
    double sagitta_length(double theta) {
        theta = DEG_to_RAD(theta);
        return radius * (1.0 - cos(theta / 2.0));
    }

    double area_of_intersection(Circle c) {
        double d = center.dist(c.center);

        double r1 = min(radius, c.radius);
        double r2 = max(radius, c.radius);

        if(d >= r1 + r2 - EPS) {
            return 0.0;
        } else if(r1 + d <= r2 + EPS) {
            return PI * r1 * r1;
        }
        
        double alfa = acos((r2*r2 + d*d - r1*r1)/(2*r2*d));
        double beta = acos((r1*r1 + d*d - r2*r2)/(2*r1*d));
        
        double A1 = alfa * r2*r2;
        double A2 = beta * r1*r1;

        double At1 = r2*r2 * sin(alfa) * cos(alfa);
        double At2 = r1*r1 * sin(beta) * cos(beta);
        
        return (A1 - At1) + (A2 - At2);
    }
    
    bool has_inside(Point p) {
        return hypot(p.x - center.x, p.y-center.y) < radius + EPS;
    }
};
