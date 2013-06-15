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

using namespace std;

typedef long long ll;
typedef long double ld;

int N, M, x[100009], y[100009], now_x, now_y;

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &N, &M);
    REP(i, N) scanf("%d%d", &x[i], &y[i]);

    REP(i, M) {
        double ma = x[N - 1] * y[0], mb = x[0] * y[N - 1];

        for (int i = 0; i < N - 1; i++) {
            ma += (x[i] * y[i + 1]);
            mb += (x[i + 1] * y[i]);
        }

        scanf("%d%d", &now_x, &now_y);

        int to_add_ma = (x[N-1] * now_y);
        int to_add_mb = (now_x * y[N-1]);

        printf("%.1lf\n", abs(((ma + to_add_ma) - (mb + to_add_mb)) * 0.5));
    }
    return 0;
}
