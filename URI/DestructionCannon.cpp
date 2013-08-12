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

const int MAXN = 60;
const int INF = 100010010;

int T, N, K, R;
int d[MAXN], w[MAXN];
int dp[MAXN][110];

int main(void) {
    T = in();

    int i, j;

    for ( ; T--; ) {
        N = in();

        for (i = 1; i <= N; i++) {
            d[i] = in();
            w[i] = in();
        }

        K = in(), R = in();

        memset(dp, 0, sizeof(dp));

        for (i = 1; i <= N; i++) {
            for (j = 0; j <= K; j++) {
                if (j >= w[i]) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + d[i]);
                } else {
                    chmax(dp[i][j], dp[i - 1][j]);
                }
            }
        }

        if (dp[N][K] >= R) {
            puts("Missao completada com sucesso");
        } else {
            puts("Falha na missao");
        }
    }
    return 0;
}
