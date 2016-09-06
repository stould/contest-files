typedef long double ld;

const ld PI = acos(-1.);
const ld EPS = 1e-8;

ld dist(Point& a, Point& b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

ld get_area(Point& c1, Point& c2, ld r1, ld r2) {
    ld d = dist(c1, c2), ans;

    if(r1 > r2) {
        ld aux = r1;
        r1 = r2;
        r2 = aux;
    }

    if(d >= r1 + r2 - EPS) {
        ans = 0.;
    } else if(r1 + d <= r2 + EPS) {
        ans = PI * r1*r1;
    } else {
        ld alfa = acos((r2*r2 + d*d - r1*r1)/(2*r2*d));
        ld beta = acos((r1*r1 + d*d - r2*r2)/(2*r1*d));
        
        ld A1 = alfa * r2*r2;
        ld A2 = beta * r1*r1;

        ld At1 = r2*r2 * sin(alfa) * cos(alfa);
        ld At2 = r1*r1 * sin(beta) * cos(beta);
        
        ans = (A1 - At1) + (A2 - At2);
    }

    return ans;
}
