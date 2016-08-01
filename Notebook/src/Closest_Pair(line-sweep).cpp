// if there are less than 75 points run brute force !!
// in this case a Point is (y, x) instead of (x, y)
// ex: read x and y -> Point p = Point(y, x)
double dist(Point& a, Point& b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double bruteForce(vector<Point> p) {
    double ans = 1e20;

    for (int i = 0; i < p.size(); i++) {
        for (int j = i + 1; j < p.size(); j++) {
            ans = min(ans, dist(p[i], p[j]));
        }
    }

    return ans;
}

double sweepLine(vector<Point> p) {
    double ans = 1e20;

    sort(p.begin(), p.end());

    set<Point> box;
    box.insert(p[0]);
    int lm = 0;

    for (int i = 1; i < n; i++) {
        while (lm < i && p[i].x - p[lm].x > ans) {
            box.erase(p[lm++]);
        }

        Point head(p[i].y - ans, p[i].x - ans);

        set<Point>::iterator low = box.lower_bound(head);

        for (set<Point>::iterator it = low;
             it != box.end() && p[i].y + ans >= it->y; it++) {
            ans = min(ans, dist(p[i], (*it)));
        }

        box.insert(p[i]);
    }

    return ans;
}
