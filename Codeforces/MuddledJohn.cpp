#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60;
const int INF = 100101010;

int N, K;
string S[MAXN];
pair<int, int> P[MAXN];
int M[MAXN][MAXN];
int dist[MAXN][MAXN];
int dp[17][1 << 17];

int dx[8]  = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8]  = {0, 0, -1, 1, -1, 1, 1, -1};
int cst[8] = {2, 2, 2,  2,  3,  3, 3, 3};

bool in(int a, int b) {
    return a >= 0 && b >= 0 && a < N && b < N;
}

void dijkstra(int pos) {
    priority_queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(P[pos].first, P[pos].second)));

    memset(dist, 63, sizeof(dist));

    dist[P[pos].first][P[pos].second] = 0;

    while (!q.empty()) {
        int ds = -q.top().first;
        int pi = q.top().second.first;
        int pj = q.top().second.second;
        q.pop();

        if (ds > dist[pi][pj]) continue;
        
        for (int i = 0; i < 8; i++) {
            int ni = pi + dx[i];
            int nj = pj + dy[i];

            if (in(ni, nj)) {
                int next_cost = dist[pi][pj] + cst[i];

                if (dist[ni][nj] > next_cost) {
                    dist[ni][nj] = next_cost;
                    q.push(make_pair(-next_cost, make_pair(ni, nj)));                    
                }
            }
        }
    }
    
    for (int i = 0; i < K; i++) {
        M[pos][i] = dist[P[i].first][P[i].second];
    }
}

int func(int pos, int mask) {
    if (__builtin_popcount(mask) == K) {
        return M[pos][0];
    } else {
        int& ans = dp[pos][mask];

        if (ans == -1) {
            ans = INF;

            for (int i = 1; i < K; i++) {
                if (!(mask & (1 << i))) {
                    ans = min(ans, M[pos][i] + func(i, mask | (1 << i)));
                }
            }
        }

        return ans;
    }
}

int main() {
    while (cin >> N && N != 0) {
        K = 1;
        
        for (int i = 0; i < N; i++) {
            cin >> S[i];
            
            for (int j = 0; j < N; j++) {
                if (S[i][j] == 'D') {
                    P[0] = make_pair(i, j);
                } else if (S[i][j] == 'M') {
                    P[K++] = make_pair(i, j);
                }
            }
        }
        
        for (int i = 0; i < K; i++) {
            dijkstra(i);
        }
        
        memset(dp, -1, sizeof(dp));
        
        cout << func(0, 1) << "\n";
    }
    return 0;
}
