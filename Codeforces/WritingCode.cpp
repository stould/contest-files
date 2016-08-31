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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 550;

int N, M, B;
Int MOD;
int P[MAXN];
Int dp[2][MAXN][MAXN];

int main(void) {
    cin >> N >> M >> B >> MOD;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    Int ans = 0LL;
    
    dp[0][0][0] = 1;
    
    for (int i = 1; i <= N; i++) {
        int pos = (i % 2);
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= B; k++) {
                dp[pos][j][k] = dp[pos ^ 1][j][k];
                
                if (k - P[i] >= 0 && j - 1 >= 0) {
                    dp[pos][j][k] += dp[pos][j - 1][k - P[i]] % MOD;
                }

                dp[pos][j][k] %= MOD;
            }
        }
    }

    for (int i = 0; i <= B; i++) {
        ans += dp[(N % 2)][M][i] % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
