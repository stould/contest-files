#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long int64;

struct Radiator {
    int x, y, radius;

    Radiator() { }
    Radiator(int a, int b, int c) {
        x = a, y = b; radius = c;
    }
};
//Trick to avoid sqrt()
bool dist(int xa, int ya, vector<Radiator>& v) {
    for(int a = 0; a < (int) v.size(); a++) {
        if((xa - v[a].x) * (xa - v[a].x) + (ya - v[a].y) * (ya - v[a].y) <= v[a].radius * v[a].radius) return false;
    }
    return true;
}

int i, j, k, xa, ya, xb, yb, radiators;

int main() {
    cin >> xa >> ya >> xb >> yb;

    cin >> radiators;

    vector<Radiator> v(radiators);

    for(i = 0; i < radiators; i++) {
        cin >> v[i].x >> v[i].y >> v[i].radius;
    }

    int needed = 0;

    for(i = min(xa, xb); i <= max(xa, xb); i++) {
        if(dist(i, ya, v)) needed++;
        if(dist(i, yb, v)) needed++;
    }

    for(i = min(ya, yb) + 1; i < max(ya, yb); i++) {
        if(dist(xa, i, v)) needed++;
        if(dist(xb, i, v)) needed++;
    }
    cout << needed << endl;
    return 0;
}
