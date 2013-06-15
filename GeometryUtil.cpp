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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

template<typename T>
struct point {
    T x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(T _x, T _y) {
        x = _x;
        y = _y;
    }
    point operator+(const point& p) {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point& p) {
        return point(x - p.x, y - p.y);
    }
    bool operator<(point b) {
        return x < b.x || (x == b.x && y < b.y);
    }
};

static int cross(point<int> a, point<int> b, point<int> c) {

}

vector<point<int> > ConvexHull(vector<point<int> > P) {
    int n = P.size(), k = 0;
    vector<point<int> > H(2*n);
    sort(P.begin(), P.end());
    for (int i = 0; i < n; i++) {
    while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k);
    return H;
}

int main(void) {

    return 0;
}

