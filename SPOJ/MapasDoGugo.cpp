#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

struct mapa {
    int id, x1, y1, x2, y2, area, center_x, center_y, x, y, dist;
    bool has;
    mapa(){}
    mapa(int _id, int _x1, int _y1, int _x2, int _y2) {
        id = _id;
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
        area = abs(x2 - x1) * abs(y2 - y1);
        center_x = (int) ((x1 + x2) / 2);
        center_y = (int) ((y1 + y2) / 2);
        has = false;
    }

    void md() {
        dist = (double) hypot(x - center_x, y - center_y);
        has = contains();
    }

    bool contains() {
        if(x >= x1 and x <= x2 and y >= y1 and y <= y2)
            return true;
        return false;
    }
    bool operator<(const mapa& m) const {
        if(area != m.area) return area < m.area;
        if(dist != m.dist) return dist < m.dist;
        return id < m.id;
    }
};

int m, r, id, xa, ya, xb, yb, x, y, test = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.in", "w", stdout);
    while(cin >> m >> r && !(m == 0 && r == 0)) {
        vector<mapa> v;
        for(int i = 0; i < m; i++) {
            cin >> id >> xa >> ya >> xb >> yb;
            v.push_back(mapa(id, xa, ya, xb, yb));
        }
        cout << "Teste " << (test++) << endl;
        sort(v.begin(), v.end());
        for(int i = 0; i < r; i++) {
            cin >> x >> y;
            vector<mapa> helper = v;
            bool ok = false;
            for(int j = 0; j < m; j++) {
                helper[j].x = x; helper[j].y = y; helper[j].md(); if(helper[j].has) ok = true;
            }
            if(!ok) {
                cout << 0 << endl;
            } else {
                sort(helper.begin(), helper.end());
                int base = 0;
                while(base < m && helper[base].has == false) base++;
                cout << helper[base].id << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
