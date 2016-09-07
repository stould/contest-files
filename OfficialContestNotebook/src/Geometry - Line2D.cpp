struct Line {
    double a, b, c;

    Line() {}
    Line(double a, double b, double c): a(a), b(b), c(c) {}
    Line(Point p1, Point p2) {
        if(p1.x == p2.x) { // vertical line treatment
            a = 1.;
            b = 0.;
            c = -p1.x;
        } else { 
            a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
            b = 1.; // easier using b = 1
            c = -(double)(a * p1.x) - ( b * p1.y);
        }
    }

    bool contains(Point p) { // check if p is on the line
        return (a*p.x +  b*p.y + c) < EPS;
    }

    bool parallel(Line r) { // checking a and b
        return (fabs( a-r.a) < EPS && fabs( b-r.b) < EPS);
    }
    bool collinear(Line r) { // now checking c
        return (parallel(r) && fabs( c-r.c) < EPS);
    }

    // if there is put intersect point on p
    bool intersect(Line r, Point& p) { 
        if(collinear(r)) return false; // infinite points
        if(parallel(r)) return false; // no point
        
        p.x = (double) (r.b *  c -  b * r.c) / (r.a *  b -  a * r.b);

        if(b > EPS) { // check if it is not a vertical line
            p.y = -(a * p.x + c) /  b;
        } else { // vertical line treatment
            p.y = -(r.a * p.x + r.c) / r.b;
        }        
        return true;
    }
};
