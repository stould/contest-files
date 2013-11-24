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

const int MAXN = 10010;

int N, M;
string A, B;

int dp[MAXN][MAXN];

int main(void) {
    int i, j;
    for ( ; cin >> N >> A >> M >> B; ) {
        for (i = 0; i <= N; i++) dp[i][0] = i;
        for (i = 0; i <= M; i++) dp[0][i] = i;

        for (i = 1; i <= N; i++) {
            for (j = 1; j <= M; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = max(i, j);
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    if (A[i - 1] == B[j - 1]) {
                        chmin(dp[i][j], dp[i - 1][j - 1]);
                    }
                }
            }
        }
        printf("%d\n", dp[N][M]);
    }
    return 0;
}
