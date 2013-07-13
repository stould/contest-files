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

const int MAXN = 110;
const int INF = 10010010;

int T, N, M, a, b, c;
int dp[MAXN][MAXN];

int main(void) {
    freopen("i.in", "r", stdin);

    int i, j, k;

    T = in();

    for ( ; T--; ) {
        N = in(), M = in();

        for (i = 0; i < MAXN; i++) {
            for (j = 0; j < MAXN; j++) {
                dp[i][j] = INF;
            }
        }

        for(i = 0; i < M; i++) {
            a = in(), b = in(), c = in();
            dp[a][b] = dp[b][a] = c;
        }

        for (k = 1; k <= N; k++) {
            for (i = 1; i <= N; i++) {
                for (j = 1; j <= N; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }

        int x = INT_MAX;

        for (i = 1; i <= N; i++) chmin(x, dp[i][i]);

        if (x == INT_MAX) {
            puts("impossivel");
        } else {
            printf("%d\n", x);
        }



    }
    return 0;
}
