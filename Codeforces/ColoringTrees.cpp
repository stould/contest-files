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

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 110;
const Int INF = 10100100000010LL;

int N, M, K;
int C[MAXN];
Int P[MAXN][MAXN];
Int dp[MAXN][MAXN][MAXN];
int memo[MAXN][MAXN][MAXN];

Int func(int pos, int k, int last) {
    if (pos == N) {
        return k == K ? 0 : INF;
    } else {
        Int& ans = dp[pos][k][last];
        
        if (!memo[pos][k][last]) {
            memo[pos][k][last] = 1;

            ans = INF;

            if (C[pos] != 0) {
                ans = func(pos + 1, k + (C[pos] != last), C[pos]);
            } else {
                for (int i = 1; i <= M; i++) {
                    ans = min(ans, P[pos][i] + func(pos + 1, k + (i != last), i));
                }
            }
        }

        return ans;
    }
}

int main(void) {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> P[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    Int ans = func(0, 0, 0);

    if (ans >= INF) {
        ans = -1;
    }
    cout << ans <<"\n";
    return 0;
}
