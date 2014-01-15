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

const int INF = 1010101001;

int N;
int dp[(1 << 12)];

int F[10][10][10];

int func(int mask) {
    if (mask == (1 << 9) - 1) {
        return 0;
    } else {
        int& ans = dp[mask];

        if (ans == -1) {
            ans = -INF;
            for (int i = 0; i < 9; i++) if (!(mask & (1 << i))) {
                for (int j = i + 1; j < 9; j++) if (!(mask & (1 << j))) {
                    for (int k = j + 1; k < 9; k++) if (!(mask & (1 << k))) {
                        if (F[i][j][k]) {
                            chmax(ans, F[i][j][k] + func(mask | (1 << i) | (1 << j) | (1 << k)));
                        }
                    }
                }
            }
        }

        return ans;
    }
}

int main(void) {
    int test = 1;
    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        memset(F, 0, sizeof(F));
        for (int i = 0; i < N; i++) {
            int a = in() - 1;
            int b = in() - 1;
            int c = in() - 1;
            int s = in();

            F[a][b][c] = F[a][c][b] = F[b][a][c] = F[b][c][a] = F[c][a][b] = F[c][b][a] = s;
        }

        memset(dp, -1, sizeof(dp));

        int ans = func(0);

        printf("Case %d: %d\n", test++, ans <= 0 ? -1 : ans);
    }

    return 0;
}
