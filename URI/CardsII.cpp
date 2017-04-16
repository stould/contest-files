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

const int MAXN = 10005;
const Int INF = 100001010010100101LL;

int N;
int P[MAXN];
Int dp[2][MAXN];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            cin >> P[i];

            dp[0][i] = P[i];

            if (i > 0) {
                dp[1][i - 1] = max(P[i - 1], P[i]);
            }
        }

        for (int i = 3; i < N; i += 2) {
            int parity = i % 2;

            for (int j = 0; j + i < N; j++) {
                dp[parity ^ 1][j] = -INF;
                dp[parity ^ 1][j] = max(dp[parity ^ 1][j], P[j] + max(dp[parity][j + 2], dp[parity][j + 1]));
                dp[parity ^ 1][j] = max(dp[parity ^ 1][j], P[j + i] + max(dp[parity][j], dp[parity][j + 1]));
            }

            for (int j = 0; j < N; j++) {
                dp[parity][j] = dp[parity ^ 1][j];
            }
        }

        Int ans = max(dp[0][0], dp[1][0]);

        cout << ans << "\n";
    }
    return 0;
}
