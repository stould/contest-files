#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef pair<double, double> point;

double x1, x2, x3, y1, y2, y3, xp, yp;

double pabs(double a) {
    return a < 0 ? -a : a;
}

double tarea(point p1, point p2, point p3) {
    double miny = min(p1.second, min(p2.second, p3.second));
    double maxy = max(p1.second, max(p2.second, p3.second));

    double lx = min(p1.first, min(p2.first, p3.first));
    double rx = max(p1.first, max(p2.first, p3.first));

    double h = maxy - miny;

    return 0.5 * pabs(lx - rx) * pabs(miny - maxy);
}

int main(void) {
    while(~scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &xp, &yp)) {
        point p1 = make_pair(x1, y1);
        point p2 = make_pair(x2, y2);
        point p3 = make_pair(x3, y3);

        point pp = make_pair(xp, yp);

        double area1 = tarea(p1, p2, pp);
        double area2 = tarea(p1, p3, pp);
        double area3 = tarea(p2, p3, pp);

        if(area1 == area2 && area2 == area3 && area1 == area3) {
            printf("%d", area1);
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
