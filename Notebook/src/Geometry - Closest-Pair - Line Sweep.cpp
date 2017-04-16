#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> point;

#define x second
#define y first

int n;
point p[10010];

bool cmp(const point& a, const point& b) {
    return a.x < b.x;
}

double dist(point a, point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double bruteForce() {
    double ans = 1e20;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ans = min(ans, dist(p[i], p[j]));
        }
    }

    return ans;
}

double sweepLine() {
    double ans = 1e20;

    sort(p, p + n, cmp);

    set<point> box;
    box.insert(p[0]);
    int lm = 0;

    for (int i = 1; i < n; i++) {
        while (lm < i && p[i].x - p[lm].x > ans) {
            box.erase(p[lm++]);
        }

        point head(p[i].y - ans, p[i].x - ans);

        auto low = box.lower_bound(head);

        for (auto it = low; it != box.end() && p[i].y + ans >= it->y; it++) {
            ans = min(ans, dist(p[i], (*it)));
        }

        box.insert(p[i]);
    }

    return ans;
}

int main(void) {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }

        double ans;

        if (n < 75) {
            ans = bruteForce();
        }
        else {
            ans = sweepLine();
        }

        if (ans >= 10000.) {
            printf("INFINITY\n");
        }
        else {
            printf("%.4lf\n", ans);
        }
    }

    return 0;
}
