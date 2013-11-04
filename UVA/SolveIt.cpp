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

int p, q, r, s, t, u;

double EPS = 1e-7;

bool cmp(double a, double b) {
    return fabs(a - b) <= EPS;
}

int main(void) {
    for ( ; cin >> p >> q >> r >> s >> t >> u; ) {
        double l = 0.0, h = 1.0, m;

        int x, ok = 0;

        for (x = 0; x < 100; x++) {
            m = (l + h) / 2.0;

            double oc = p * exp(-m) + q * sin(m) + r * cos(m) + s * tan(m) + t * m * m + u;

            if (cmp(oc, 0.0)) {
                printf("%.4lf\n", m);
                ok = 1; break;
            } else if (oc > 0.0) {
                l = m;
            } else {
                h = m;
            }
        }

        if (!ok) {
            printf("No solution\n");
        }
    }
    return 0;
}
