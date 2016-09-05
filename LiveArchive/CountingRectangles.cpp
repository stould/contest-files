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

const int MAXN = 110;

int N, M;
string S[MAXN];
Int dp[MAXN][MAXN];
Int V[MAXN][MAXN], H[MAXN][MAXN];

int main(void) {
    while (cin >> N >> M) {
        memset(dp, 0, sizeof(dp));
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        
        for (int i = 0; i < N; i++) {
            cin >> S[i];

            for (int j = 0; j < N; j++) {
                if (S[i][j] == '1') {
                    dp[i][j] = 1;

                    V[i][j] = 1;
                    H[i][j] = 1;
                }
                if (j - 1 >= 0 && S[i][j - 1] == '1') {
                    H[i][j] += H[i][j - 1];
                }
                if (i - 1 >= 0 && S[i - 1][j] == '1') {
                    V[i][j] += V[i - 1][j];
                }
                if (i - 1 >= 0 && j - 1 >= 0 && S[i - 1][j - 1] == '1' && S[i - 1][j] == '1' ) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        Int ans = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (S[i][j] == '1') {
                    cout << i << " " << j << " " << V[i][j] << " " << H[i][j] << " " << dp[i][j] << endl;
                    ans += V[i][j];
                    ans += V[i][j];
                    ans += dp[i][j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
