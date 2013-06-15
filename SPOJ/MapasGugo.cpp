#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

struct mapa {
    int id, x1, y1, x2, y2, area, center_x, center_y;
    mapa(){}
    mapa(int _id, int _x1, int _y1, int _x2, int _y2) {
        id = _id;
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
        area = abs(max(x1, x2) - min(x1, x2)) * abs(max(y1, y2) - min(y1, y2));
        center_x = (int) ((x1 + x2) / 2);
        center_y = (int) ((y1 + y2) / 2);
    }
    bool contains(int x, int y) {
        if(x >= min(x1, x2) and x <= max(x1, x2) and y <= max(y1, y2) and y >= min(y1, y2))
            return true;
        return false;
    }
    double dist(int x, int y) {
        return sqrt(abs(((center_x - x) * (center_x - x)) - ((center_y - y) * (center_y - y))));
    }
    bool operator==(const mapa& m) const {
        if(x1 == m.x1 && y1 == m.y1) return true;
        if(x1 == m.x2 && y1 == m.y2) return true;
        if(x2 == m.x1 && y2 == m.y1) return true;
        if(x2 == m.x2 && y2 == m.y2) return true;
        return false;
    }
    bool operator<(const mapa& m) const {
        if(area != m.area) return area > m.area;
        return id > m.id;
    }
};

int m, r, id, xa, ya, xb, yb, x, y, test = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    while(cin >> m >> r && !(m == 0 && r == 0)) {
        vector<mapa> v;
        vector<mapa>::iterator it;
        for(int i = 0; i < m; i++) {
            cin >> id >> xa >> ya >> xb >> yb;
            mapa tmp = mapa(id, xa, ya, xb, yb);
            it = find(v.begin(), v.end(), tmp);
            if(it != v.end()) {
                if(it-> area < tmp.area) {
                    v.erase(it);
                    v.push_back(tmp);
                }
            } else {
                v.push_back(tmp);
            }
        }
        cout << "Teste " << (test++) << endl;
        sort(v.begin(), v.end());
        for(int i = 0; i < r; i++) {
            cin >> x >> y;
            int ans = 0;
            double dist = 10000000000000.0;
            for(int j = 0; j < m; j++) {
                if(v[j].contains(x, y) && dist > v[j].dist(x, y)) {
                    ans = v[j].id;
                    dist = v[j].dist(x, y);
                }
            }
            cout << ans << endl;
        }
        cout << endl;
    }
    return 0;
}
