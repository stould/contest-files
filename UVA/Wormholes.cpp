#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int INF = 1 << 23;

int c, n, m, s, t, b, ok, dist[1010], inQ[1010];
vector<pair<int, int> > graph[1010];

#define LOCAL

int main(void) {
#ifdef LOCAL
    freopen("i.in","r", stdin);
#endif
    cin >> c;
    for( ; c-- > 0; ) {
        cin >> n >> m;
        for(int i = 0; i <= n; i++) {
            dist[i] = INF;
            graph[i].clear();
            inQ[i] = 0;
        }
        for(int i = 0; i < m; i++) {
            cin >> s >> t >> b;
            graph[s].push_back(make_pair(t, b));
            graph[t].push_back(make_pair(s, b));
        }
        dist[0] = ok = 0;
        inQ[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int tmp = q.front(); q.pop();
            inQ[tmp] = 0;
            for(int i = 0; i < graph[tmp].size(); i++) {
                if(dist[graph[tmp][i].first] > dist[tmp] + graph[tmp][i].second) {
                    dist[graph[tmp][i].first] = dist[tmp] + graph[tmp][i].second;
                    if(!inQ[graph[tmp][i].first]) {
                        inQ[graph[tmp][i].first] += 1;
                        q.push(graph[tmp][i].first);
                    }
                }
            }
        }
        cout << (!ok ? "not possible\n" : "possible\n");
    }
    return 0;
}

