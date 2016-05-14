#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>

#define INF 1000000000

using namespace std;

typedef long long ll;

ll a, b, c, n, m, dist[10010];
vector<pair<int, int> > graph[10010];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] < dist[y];
    }
};

void dijkstra(int a, int b) {
    fill(dist, dist + n + 1, INF);
    dist[a] = 0;
    priority_queue<ll, vector<ll>, MyLess> q;
    q.push(a);
    while(!q.empty()) {
        int tmp = q.top(); q.pop();
        for(int i = 0; i < graph[tmp].size(); i++) {
            ll &actual = dist[graph[tmp][i].first];
            ll nova = dist[tmp] + graph[tmp][i].second;
            if(nova < actual) {
                actual = nova;
                q.push(graph[tmp][i].first);
            }
        }
    }
    if(dist[b] == INF) {
        cout << "NO\n";
    } else {
        cout << dist[b] << "\n";
    }
}

int main(void) {
    int test;
    cin >> test;
    for( ; test-- > 0; ) {
        cin >> n >> m;
        for(int i = 0; i <= n; i++) graph[i].clear();
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            graph[a].push_back(make_pair(b, c));
        }
        cin >> a >> b;
        dijkstra(a, b);
    }
    return 0;
}


