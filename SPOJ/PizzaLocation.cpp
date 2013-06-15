#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>

using namespace std;

int i, j, k, l, n, r, m;

struct point {
    int x, y;
    point() {
        x = y = 0;
    }
    point(int xx, int xy) {
        x = xx;
        y = xy;
    }
};

struct table {
    point p;
    int c;
    table() {
        c = 0;
    }
    table(int cc) {
        c = cc;
    }
};

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> k >> r >> m;

    vector<point> v(m);
    for(i = 0; i < m; i++) {
        cin >> v[i].x >> v[i].y;
    }

    cin >> n;

    vector<table> t(n);
    for(i = 0; i < n; i++) {
        cin >> t[i].p.x >> t[i].p.y >> t[i].c;
    }

    int mx = 0;
    for(i = 0; i < (1 << m); i++) {
        int agreed = 0;
        for(j = 0; j < m; j++) {
            if((i >> j) & 1) {
                agreed += 1;
            }
        }
        int sum = 0;
        set<pair<int, int> > s_tmp;
        if(agreed <=- k) {
            for(j = 0; j < m; j++) {
                if((i >> j) & 1) {
                    for(l = 0; l < n; l++) {
                        int dist = (int) sqrt(((v[j].x - t[l].p.x) * (v[j].x - t[l].p.x)) +  ((v[j].y - t[l].p.y) * (v[j].y - t[l].p.y)));

                        if(dist <= r && !count(s_tmp.begin(), s_tmp.end(), make_pair(t[l].p.x, t[l].p.y))) {
                            s_tmp.insert(make_pair(t[l].p.x, t[l].p.y));
                            sum += t[l].c;
                        }
                    }
                }
            }
        }
        mx = max(mx, sum);
    }
    cout << mx << endl;
    return 0;
}
