#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int i, n;

struct point {
    int x, y;

    point(int x, int y): x(x), y(y) {}
    point() {}

    bool operator <(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }

    bool operator==(const point &p) const {
        return x == p.x && y == p.y;
    }
};

ll cross(const point &O, const point &A, const point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<point> convex_hull(vector<point> &P) {
    int n = P.size(), k = 0;
    vector<point> H(2*n);
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
    freopen("i.in", "r", stdin);
    while(scanf("%d", &n) && n != 0) {
        vector<point> base(n);
        REP(i, n) {
            scanf("%d%d", &base[i].x, &base[i].y);
        }
        int ans = 0;
        while(!base.empty()){
            vector<point> tmp = convex_hull(base);
            ans += 1;
            REP(i, tmp.size()) {
                if(find(base.begin(), base.end(), tmp[i]) != base.end()) {
                    base.erase(find(base.begin(), base.end(), tmp[i]));
                }
            }
        }
   //     printf("%d\n", ans);
        if(ans % 2 != 0) {
            puts("Take this onion to the lab!");
        } else {
            puts("Do not take this onion to the lab!");
        }
    }
    return 0;
}

