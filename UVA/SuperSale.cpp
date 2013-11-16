#include <bits/stdc++.h>

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

const int MAXN = 1010;

int T;
int N, G;

int P[MAXN];
int W[MAXN];

int dp[MAXN][MAXN];

int main(void) {
    T = in();

    int i;
    int j;

    for ( ; T--; ) {
        N = in();

        for (i = 1; i <= N; i++) {
            P[i] = in();
            W[i] = in();
        }

        memset(dp, 0, sizeof(dp));

        for (i = 1; i <= N; i++) {
            for (j = 0; j <= 1000; j++) {
                dp[i][j] = dp[i - 1][j];

                if (j - W[i] >= 0) {
                    chmax(dp[i][j], P[i] + dp[i - 1][j - W[i]]);
                }
            }
        }

        G = in();

        int ans = 0;

        for (i = 0; i < G; i++) {
            int curr = in();

            ans += dp[N][curr];
        }

        printf("%d\n", ans);
    }

    return 0;
}
