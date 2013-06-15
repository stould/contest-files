#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int INF = 100000000;
int i, n, m, c, k, u, v, p, ans, dist[260];
vector<pair<int, int> > graph[260];

struct MyLess {
    bool operator()(int x, int y) {
        return dist[x] < dist[y];
    }
};

int dijsktra(int start) {
    for(i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    priority_queue<int, vector<int>, MyLess> q;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()) {
        int tmp = q.top(); q.pop();
        for(i = 0; i < graph[tmp].size(); i++) {
            if(tmp <= c - 1 && (graph[tmp][i].first != tmp + 1 || graph[tmp][i].first == 0)) continue;
            int &actual = dist[graph[tmp][i].first];
            int next = dist[tmp] + graph[tmp][i].second;

            if(next < actual) {
                actual = next;
                q.push(graph[tmp][i].first);
            }
        }
    }
    return dist[c - 1];
}

int main(void) {
    while(scanf("%d%d%d%d", &n, &m, &c, &k) && !(n+m+c+k == 0)) {
        for(i = 0; i < n; i++) graph[i].clear();
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &p);
            graph[u].push_back(make_pair(v, p));
            graph[v].push_back(make_pair(u, p));
        }
        printf("%d\n", dijsktra(k));
    }
    return 0;
}
