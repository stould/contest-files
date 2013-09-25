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

const double PI = 3.1415926535897;

double A, B, C;

int main(void) {
    //freopen("i.in", "r", stdin);
    for ( ; scanf("%lf%lf%lf", &A, &B, &C) == 3; ) {
        double S = 0.5 * (A + B + C);

        double K = sqrt(S * (S - A) * (S - B) * (S - C));

        double ra = (2.0 * K) / (double) (C - A + B);
        double rb = (2.0 * K) / (double) (A - B + C);
        double rc = (2.0 * K) / (double) (B - C + A);

        double inCircle = PI * ((2.0 * K) / (2.0 * S)) * ((2.0 * K) / (2.0 * S));
        double triangle = K - inCircle;

        double outerR = (A * B * C) / (4.0 * K);

        double outer = PI * outerR * outerR - triangle - inCircle;

        cout << fixed << setprecision(4) << outer << " " << triangle << " " << inCircle << "\n";
    }
    return 0;
}
