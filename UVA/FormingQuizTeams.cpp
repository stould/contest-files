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

int N;

double dp[(1 << 20)];

bool mark[(1 << 20)];

int x[10], y[10];

double func(int mask) {
    if (mask == ((1 << (2 * N)) - 1)) {
        return 0.0;
    }

    double& ans = dp[mask];

    if (mark[mask]) {
        return ans;
    }

    mark[mask] = true;

    ans = 101010010.0;

    int i, j;

    for (i = 0; i < 2 * N; i++) {
        if (!(mask & (1 << i))) {
            for (j = 0; j < 2 * N; j++) if (i != j && (!(mask & (1 << j)))) {
                int n_mask = (mask | (1 << i)) | (1 << j);

                double d = hypot(x[i] - x[j], y[i] - y[j]);

                chmin(ans, d + func(n_mask));
            }
        }
    }

    return ans;
}

int main(void) {
    int i, T = 1;
    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        for (i = 0; i < 2 * N; i++) {
            scanf("%*s%d%d", &x[i], &y[i]);
        }

        memset(mark, false, sizeof(mark));

        cout << fixed << setprecision(2) << "Case " << T++ << ": " << func(0) << "\n";
    }
    return 0;
}
