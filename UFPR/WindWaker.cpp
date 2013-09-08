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
#include <numeric>
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

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

int xa, ya, x2, y2;
char buff[20];

int main(void) {
    int i;

    for ( ; scanf("%d%d%d%d", &xa, &ya, &x2, &y2) == 4; ) {
        double walk = 0.0;

        vector<string> ans;

        int q = 0;

        if (xa != x2 && ya != y2) {
            if (y2 > 0) {
                if (x2 > 0) q = 1;
                else q = 2;
            } else {
                if (x2 < 0) q = 3;
                else q = 4;
            }

            if (q == 1) {
                ans.push_back("0.00 0.00 NE");
            } else if (q == 2) {
                ans.push_back("0.00 0.00 NW");
            } else if (q == 3) {
                ans.push_back("0.00 0.00 SW");
            } else {
                ans.push_back("0.00 0.00 SE");
            }

            walk += hypot(xa - min(x2, y2), ya - min(x2, y2));

            xa = min(x2, y2);
            ya = min(x2, y2);
        }

        if (ya < y2) {
            sprintf(buff, "%.2lf %.2lf N", x2, y2);
            ans.push_back(string(buff));
            walk += abs(ya - y2);
        } else if (ya > y2) {
            sprintf(buff, "%.2lf %.2lf S", x2, y2);
            ans.push_back(string(buff));
            walk += abs(ya - y2);
        } else if (xa < x2) {
            sprintf(buff, "%.2lf %.2lf E", x2, y2);
            ans.push_back(string(buff));
            walk += abs(xa - x2);
        } else {
            sprintf(buff, "%.2lf %.2lf W", x2, y2);
            ans.push_back(string(buff));
            walk += abs(xa - x2);
        }

        printf("%d\n", ans.size());

        for (i = 0; i < (int) ans.size(); i++) {
            cout << ans[i] << "\n";
        }

        printf("%.3lf\n\n", walk);
    }
    return 0;
}
