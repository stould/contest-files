// center = (p1 + p2 + ... + pk) / k
bool cmp(Point a, Point b) {
    if (a.x - center.x >= 0 && b.x - center.x < 0)
        return true;
    if (a.x - center.x < 0 && b.x - center.x >= 0)
        return false;
    if (fabs(a.x - center.x) < EPS && fabs(b.x - center.x) < EPS) {
        if (a.y - center.y >= 0 || b.y - center.y >= 0)
            return a.y > b.y;
        return b.y > a.y;
    }

    // compute the cross product of vectors (center -> a) x (center -> b)
    double det = (a.x - center.x) * (b.y - center.y) - 
        (b.x - center.x) * (a.y - center.y);
    if (det < 0)
        return true;
    if (det > 0)
        return false;

    // points a and b are on the same line from the center
    // check which point is closer to the center
    double d1 = (a.x - center.x) * (a.x - center.x) +
        (a.y - center.y) * (a.y - center.y);
    double d2 = (b.x - center.x) * (b.x - center.x) +
        (b.y - center.y) * (b.y - center.y);
    return d1 > d2;
}

bool cmp(Point a, Point b) {
    return atan2(a.y-center.y, a.x - center.x) < atan2(b.y-center.y, b.x-center.x);
}

// all algorithms below need the polygon points to be sorted 
// and the last point of the polygon needs to be the same as the first

bool ccw(Point o, Point a, Point b) {
    Vector oa = Vector(o, a);
    Vector ob = Vector(o, b);
    return oa.cross(ob) > 0;
}

// check if point is inside polygon
bool in_polygon(Point pt, vector<Point> &P) {
    double sum = 0;
    for (int i = 0; i < (int)P.size()-1; i++) {
        if(pt == P[i] || pt == P[i+1]) return true;
        if (ccw(pt, P[i], P[i+1]))
            sum += angle(P[i], pt, P[i+1]);
        else sum -= angle(P[i], pt, P[i+1]);
    }         

    return fabs(fabs(sum) - 2*PI) < EPS; 
}

// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++) // remember that P[0] = P[n-1]
        result += P[i].dist(P[i+1]);
    return result; 
}

// returns the area of the polygon
double area(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0; 
}

bool isConvex(const vector<point> &P) {
    int sz = (int)P.size(); 
    if (sz <= 3) return false;
    bool isLeft = ccw(P[0], P[1], P[2]);
    for (int i = 1; i < sz-1; i++)
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false; 
    return true; 
}
