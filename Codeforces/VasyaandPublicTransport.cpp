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

const int INF = INT_MAX / 3;
const int MAXN = 1010;

int c[5];

int dp[MAXN][MAXN];

int N, M;

int B[MAXN];
int T[MAXN];

int func(int a, int b) {
    if (a == N && b == M) {
        return 0;
    }

    int& ans = dp[a][b];

    if (ans != -1) {
        return ans;
    }

    ans = INF;

    chmin(ans, B[a] * c[0] + func(a + 1, b));
    chmin(ans, T[b] * c[0] + func(a, b + 1));

    chmin(ans, (B[a] + T[b]) * c[0] + func(a + 1, b + 1));

    chmin(ans, c[1] + func(a + 1, b));
    chmin(ans, c[1] + func(a, b + 1));

    chmin(ans, 2 * c[1] + func(a + 1, b + 1));

    return ans;
}

int main(void) {
    int i;

    for (i = 0; i < 4; i++) {
        c[i] = in();
    }

    N = in();
    M = in();

    int bus = 0, tro = 0;

    for (i = 0; i < N; i++) {
        B[i] = in();
    }

    for (i = 0; i < M; i++) {
        T[i] = in();
    }

    memset(dp, -1, sizeof(dp));

    ans = func(0, 0);

    int ac_a = accumulate(B, B + N, 0);
    int ac_b = accumulate(T, T + N, 0);

    chmin(ac * c[2])

    return 0;
}
