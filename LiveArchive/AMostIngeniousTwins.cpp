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

using namespace std;

typedef long long ll;
typedef unsigned uint;

const double L = 299792458.;
double te, tr;

double gamma(double v) {
    return sqrt(1.0 - ((v / L) * (v / L)));
}

int main(void) {
    freopen("i.in", "r", stdin);
    int i;
    for ( ; scanf("%lf%lf", &te, &tr) == 2 && (te + tr != 0.0); ) {
        double low = 0.0, high = 299792458.0, mid;

        for (i = 0; i < 100; i++) {
            mid = (low + high) / 2;

            double v = gamma(mid);

            printf("%.3lf %.3lf\n", (double) te * v, v);

            if (te * v <= tr) {
                high = mid;
            } else {
                low = mid;
            }
        }

        printf("%.3lf\n", gamma(mid));
    }
    return 0;
}
