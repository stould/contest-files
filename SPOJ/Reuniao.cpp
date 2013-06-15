#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int INF = 100000000;
int i, j, k, n, m, dp[110][110], u, v, w;

int main(void) {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 0; i <= n; i++) {
        for(j = 0; j <= n; j++) {
            dp[i][j] = INF;
            if(i == j) dp[i][j] = 0;
        }
    }
    for(i = 0; i < m; i++) {
        cin >> u >> v >> w;
        if(dp[u][v] > w) {
            dp[u][v] = w;
        }
        if(dp[v][u] > w) {
            dp[v][u] = w;
        }
    }
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int cnt = INF;
    for(i = 0; i < n; i++) {
        int all = 0;
        for(j = 0; j < n; j++) {
            if(i != j && dp[j][i] != INF) {
                all = max(all, dp[j][i]);
            }
        }
        if(all < cnt) {
            cnt = all;
        }
    }
    cout << cnt << endl;
    return 0;
}
