#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX / 5;
const int MAXN = 101;

int T, N, M, L;
int dp[MAXN];
int C[MAXN], V[MAXN], P[MAXN];
int helper_dp[MAXN][1010];

int helper(int pos, int diff) {
    if (diff < 0) {
        return INF;
    } else if (diff == 0) {
        return 0;
    } else if (pos >= M) {
        return INF;
    } else {
        int& ans = helper_dp[pos][diff];
        
        if (ans == -1) {			
            ans = C[pos] + helper(pos + 1, diff - V[pos]);
			ans = min(ans, helper(pos + 1, diff));
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

        for (int i = 0; i < M; i++) {
            cin >> C[i] >> V[i];
        }
        
        memset(dp, 63, sizeof(dp));
        
        dp[0] = 0;
				memset(helper_dp, -1, sizeof(helper_dp));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {

				int check = helper(0, abs(P[i] - P[j]));

				if (check <= L) {
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}
        /*
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
        
        */
        int ans = dp[N-1];
        
        if (ans >= INF) ans = -1;
        
        cout << ans << "\n";
    }
    return 0;
}
