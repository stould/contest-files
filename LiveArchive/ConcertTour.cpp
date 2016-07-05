#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

int T;
int N, C;
int P[MAXN][MAXN];
int G[MAXN][MAXN];
int dp[MAXN][MAXN];

int func(int pos, int len) {
    if (len == C) {
        return 0;
    } else {
        int& ans = dp[pos][len];

        if (ans == -1) {
            if (pos != 0) {
                ans = func(pos, len + 1) + P[pos][len + 1];
            }

            for (int i = 1; i <= N; i++) {
                if (i != pos) {
                    ans = max(ans, P[i][len + 1] - G[pos][i] + func(i, len + 1));
                }
            }
        }
        return ans;
    }
}

int main() {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> C;
    
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= C; j++) {
                cin >> P[i][j];
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> G[i][j];
            }
        }

        memset(dp, -1, sizeof(dp));
    
        int ans = func(0, 0);

        cout << ans << "\n";
    }
    return 0;
}
