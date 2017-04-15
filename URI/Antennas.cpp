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

const int MAXN = 1010;
const int MAXK   = 100000;
const int MIDDLE = 50000;
const int INF = 101010010;

int N;
int P[MAXN];
int dp[2][MAXK + 5];

int main(void) {
    while (cin >> N && N != 0) {
        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        memset(dp, -63, sizeof(dp));
        dp[N % 2][MIDDLE] = 0;

        
        for (int i = N - 1; i >= 0; i--) {
            int now = i % 2;
            int bef = now ^ 1;

            memset(dp[now], -63, sizeof(dp[now]));
            dp[now][MIDDLE] = max(0, dp[bef][MIDDLE]);

            for (int j = 0; j <= MAXK; j++) {
                dp[now][j] = dp[bef][j];

                if (j + P[i] <= MAXK) {
                    chmax(dp[now][j], P[i] + dp[bef][j + P[i]]);
                }
                if (j - P[i] >= 0) {
                    chmax(dp[now][j], dp[bef][j - P[i]]);
                }
            }
        }

        cout << dp[0][MIDDLE] << "\n";
    }
    return 0;
}
