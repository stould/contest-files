#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int cost, n, p, to, dist[1010], vis[1010];
vector<pair<int, int> > graph[1010];

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &n) && n != 0) {
        for(int i = 0; i <= n + 1; i++) {
            graph[i].clear();
            vis[i] = dist[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            scanf("%d", &cost);
            graph[0].push_back(make_pair(i, cost));
            graph[i].push_back(make_pair(n+1, cost));
            scanf("%d", &p);
            for(int j = 0; j < p; j++) {
                scanf("%d", &to);
                graph[i].push_back(make_pair(to, cost));
            }
        }
        queue<int> q; q.push(0);

        while(!q.empty()) {
            int tmp = q.front(); q.pop(); vis[tmp] = true;
            for(int i = 0; i < graph[tmp].size(); i++) {
                int &actual = dist[graph[tmp][i].first];
                int next = dist[tmp] + graph[tmp][i].second;

                if(next > actual) {
                    actual = next;
                    q.push(graph[tmp][i].first);
                }
            }
        }
        cout << dist[n+1] << endl;
    }
    return 0;
}
