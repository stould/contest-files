#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
const int MAX_V = 5010;
const int INF = INT_MAX / 5;

int T;
int N, M;
int P[MAXN][MAXN];
int dp1[MAX_V][MAXN];
int dp2[MAX_V][MAXN];
vector<pair<int, int> > G[MAX_V];

int max_path(int node, int len) {
    if (len == 0) {
        return 0;
    } else {
        int& ans = dp1[node][len];

        if (ans == -1) {
            for (int i = 0; i < (int) G[node].size(); i++) {
                ans = max(ans, G[node][i].second + max_path(G[node][i].first, len - 1));
            }
        }
    
        return ans;
    }
}

int min_path(int node, int len) {
    if (len == 0) {
        return 0;
    } else {
        int& ans = dp2[node][len];

        if (ans == -1) {
            ans = INF;
            for (int i = 0; i < (int) G[node].size(); i++) {
                ans = min(ans, G[node][i].second + min_path(G[node][i].first, len - 1));
            }
        }
    
        return ans;
    }
}

int main() {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        for (int i = 0; i < MAX_V; i++) {
            G[i].clear();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> P[i][j];
                G[0].push_back(make_pair((i + 1) * N + j, P[i][j]));
            }
        }
    
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int a = i + 1; a < N; a++) {
                    for (int b = j + 1; b < M; b++) {
                        G[(i + 1) * N + j].push_back(make_pair((a + 1) * N + b, P[a][b]));
                    }
                }
            }
        }

        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));

        int ans = 0;

        for (int m = 1; m <= N; m++) {
            int pa = max_path(0, m);
            int pb = min_path(0, 2 * m);
      
            //cout << m << " " << pa << " " << pb << "\n";
            int profit = max(0, pa - pb);
      
            if (profit > ans) {
                ans = profit;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
