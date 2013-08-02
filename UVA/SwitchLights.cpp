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

const int MAXN = 110;
const int INF = 100000100;

int T, N, M;
int digit;
int V[MAXN];

int dp[MAXN][(1 << 15)];

int func(int index, int mask) {
    if (mask == 0) return 0;
    if (index == M) return INF;

    int& ret = dp[index][mask];

    if (ret != -1) return ret;

    ret = func(index + 1, mask);

    return ret = min(ret, 1 + func(index + 1, mask ^ V[index]));
}

int main(void) {
    T = in();

    int i, j, test = 1;;

    for ( ; T--; ) {
        N = in(), M = in();

        for (i = 0; i < M; i++) {
            V[i] = 0;
            for (j = 0; j < N; j++) {
                digit = in();

                if (digit) V[i] |= (1 << (N - j - 1));
            }
        }

        memset(dp, -1, sizeof(dp));

        int ans = func(0, (1 << N) - 1);

        printf("Case %d: ", test++);

        if (ans == INF) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
