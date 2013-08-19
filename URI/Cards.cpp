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

const int MAXN = 10007;
int N;

Int dp[MAXN][MAXN];
int V[MAXN];

Int func(int i, int j) {
    if (i > j) return 0LL;
    if (i + 1 == j) return max(V[i], V[j]);

    Int& ans = dp[i][j];

    if (ans != -1) return ans;

    Int l = V[i] + min(func(i + 2, j), func(i + 1, j - 1));
    Int r = V[j] + min(func(i, j - 2), func(i + 1, j - 1));

    return ans = max(l, r);
}

int main(void) {
    freopen("i.in", "r", stdin);
    int i;
    for ( ; scanf("%d", &N) == 1; ) {
        for (i = 0; i < N; i++) {
            V[i] = in();
        }
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", func(0, N - 1));
    }
    return 0;
}
