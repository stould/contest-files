#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
const int LIMIT = 250;
const int INF = 10000010;

int N, M;
int P[MAXN], W[MAXN], D[MAXN];
int dp[MAXN][1000][3];

int func(int pos, int weight, int used) {
    if (weight > M + (2 - used) * 100) {
        return -INF;
    } else if (pos == N) {
        return weight <= M ? 0 : -INF;
    } else {
        int& ans = dp[pos][weight + LIMIT][used];

        if (ans == -1) {
            ans = func(pos + 1, weight, used);      
            ans = max(ans, P[pos] + func(pos + 1, weight + W[pos], used));
      
            if (used + 1 <= 2) {
                ans = max(ans, P[pos] + func(pos + 1, weight + W[pos] - D[pos], used + 1));
            }      
        }

        return ans;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> P[i] >> W[i] >> D[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << max(0, func(0, 0, 0)) << "\n";
    return 0;
}

