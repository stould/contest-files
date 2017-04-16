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

const int MAXN = 100005;

int N, K;
Int P[MAXN];
Int C[MAXN];
Int dp[2][MAXN];

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = 1; i < N; i++) {
        cin >> C[i];
    }

    Int ans = 0;

    for (int k = 0; k < K; k++) {
        int pos = k % 2;
        Int now = dp[pos ^ 1][0] - P[0];
        
        for (int i = 1; i < N; i++) {
            dp[pos][i] = max(dp[pos][i], dp[pos][i - 1]);
            dp[pos][i] = max(dp[pos][i], now + P[i] + C[i]);
            //cout << dp[pos][i] << " ";
            now = max(now, dp[pos ^ 1][i] - P[i]);

            if (k == K - 1) {
                ans = max(ans, dp[pos][i]);
            }
        }   
        //cout << endl;
    }

    cout << ans << endl;
    return 0;
}
