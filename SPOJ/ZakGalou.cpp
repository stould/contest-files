#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#define REP(i, n) for(i = 0; i < (n); i++)

using namespace std;

long long INF = 100000000000LL;
int i, j, m, n, g, k, u, v;
long long dist[10010], cost[1010], dp[1015];
vector<int> graph[1010];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] > dist[y];
    }
};

void minimal_mana(vector<pair<long long, long long> >& vi) {
    for(int x = 0; x <= 1010; x++) dp[x] = INF;
    dp[0] = 0;
    int ans = INF;
    for(int x = 1; x <= 1010; x++) {
        for(int y = 0; y < m; y++) if(x - vi[y].second >= 0) {
            if(dp[x - vi[y].second] + vi[y].first < dp[x]) {
               dp[x] = dp[x - vi[y].second] + vi[y].first;
            }
        }
    }
    for(int i = 1; i <= 1010; i++) {
        for(int j = i + 1; j <= 1010; j++) {
            if(dp[j] < dp[i]) dp[i] = dp[j];
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.out", "w", stdout);
    while(scanf("%d%d%d%d", &m, &n, &g, &k) && !(n+m+g+k == 0)) {
        vector<pair<long long, long long> > vi(m);
        REP(i, m) {
            scanf("%lld%lld", &vi[i].first, &vi[i].second);
        }
        REP(i, n + 1) {
            cost[i] = 0;
            graph[i].clear();
        }
        REP(i, g) {
            scanf("%d%d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        minimal_mana(vi);
        REP(i, k) {
            scanf("%d%d", &u, &v);
            cost[u] += dp[v];
        }
        fill(dist, dist + n + 1, INF);
        priority_queue<int, vector<int>, MyLess> q;
        q.push(1);
        dist[1] = cost[1];

        while(!q.empty()) {
            int tmp = q.top(); q.pop();
            for(i = 0; i < graph[tmp].size(); i++) {
                long long &actual = dist[graph[tmp][i]];
                long long next = dist[tmp] + cost[graph[tmp][i]];

                if(next < actual) {
                    actual = next;
                    q.push(graph[tmp][i]);
                }
            }
        }
        cout << (dist[n] == INF ? -1 : dist[n]) << endl;
    }
    return 0;
}
