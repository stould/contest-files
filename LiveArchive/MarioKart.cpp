#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX / 5;
const int MAXN = 101;

int T, N, M, L;
int dp[MAXN];
int C[MAXN], V[MAXN], P[MAXN];
int helper_dp[MAXN][1010][1010];
int sub[110][1010];

int helper(int pos, int diff, int cst) {
    if (cst > L || diff < 0) {
        return 0;
    } else if (diff == 0) {
        return 1;
    } else if (pos >= M) {
        return 0;
    } else {
        int& ans = helper_dp[pos][diff][cst];
        
        if (ans == -1) {
            ans = 0;
            
            if (diff - V[pos] >= 0 && sub[diff - V[pos]]) {
                ans = helper(pos + 1, diff - V[pos], cst + C[pos]);
            }
            if (ans == 0) {
                if (sub[diff]) {
                    ans = helper(pos + 1, diff, cst);
                }
            }
        }        
        return ans;
    }
}

int main() {
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> L;

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }
        
        sort(P, P + N);

        for (int i = 1; i <= M; i++) {
            cin >> C[i] >> V[i];
        }
        
        memset(sub, 63, sizeof(sub));

        for (int i = 0; i <= L; i++) {
            sub[0][i] = 0;
        }
        
        for (int i = 1; i <= M; i++) {
            for (int j = 0; j <= L; j++) {
                if (V[i] - j >= 0) {
                    sub[i][j] = min(sub[i][j], sub[i - 1][j - V[i]] + C[i]);
                } else {
                    sub[i][j] = sub[i - 1][j];
                }
            }      
        } 
        
        memset(dp, 63, sizeof(dp));
        
        dp[0] = 0;
        
        priority_queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        
        while (!q.empty()) {
            int dist = -q.top().first;
            int node = q.top().second;
            q.pop();

            if (dp[node] < dist) continue;
            
            if (node == N - 1) break;
            
            for (int i = 0; i < N; i++) {
                int diff = abs(P[node] - P[i]);
                int cost = INF;
                
                for (int j = 1; j <= M; j++) {
                    cost = min(cost, sub[j][diff]);
                }
                
                if (cost <= L) {
                    if (i != node && dp[i] > dp[node] + 1) {
                        dp[i] = dp[node] + 1;
                        q.push(make_pair(-dp[i], i));
                    }   
                }
            }            
        }   
        
        
        int ans = dp[N-1];
        
        if (ans >= INF) ans = -1;
        
        cout << ans << "\n";
    }
    return 0;
}
