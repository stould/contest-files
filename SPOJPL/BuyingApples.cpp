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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 110;
const int INF = INT_MAX / 5;

int T, N, K;
int P[MAXN];
int dp[MAXN][MAXN];

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N >> K;

        for (int i = 0; i < K; i++) {
            cin >> P[i];
        }

        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                dp[i][j] = INF;                
            }
        }

        int ans = INF;

        dp[0][0] = 0;
        
        for (int i = 1; i <= K; i++) {
            for (int k = 0; k <= K; k++) {
                for (int a = 0; a < K; a++) {
                    if (k - (a + 1) < 0 || P[a] == -1) continue;
                    dp[i][k] = min(dp[i][k], dp[i - 1][k - (a + 1)] + P[a]);
                }
                if (k == K) {
                    ans = min(ans, dp[i][K]);
                }
            }
        }
        
        if (ans == INF) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}
