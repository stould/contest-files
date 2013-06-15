#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

const int INF = 10000000;
int a, b, p, l, init, high[200], dist[200], test = 1;
vector<int> graph[200];

int bfs(int x) {
    for(int i = 1; i <= p; i++) { dist[i] = 0; }
    int ans = 0;
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    while(!q.empty()) {
        int ac = q.front(); q.pop();
        for(int i = 0; i < graph[ac].size(); i++) {
            if(high[graph[ac][i]] < high[ac] && dist[graph[ac][i]] < dist[ac] + 1) {
                dist[graph[ac][i]] = max(dist[graph[ac][i]], dist[ac] + 1);
                if(dist[graph[ac][i]] > ans) ans = dist[graph[ac][i]];
                q.push(graph[ac][i]);
            }
        }
    }
    return ans;
}

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> p >> l >> init) {
        if(!p && !l && !init) break;
        for(int i = 0; i <= p; i++) graph[i].clear();
        for(int i = 1; i <= p; i++) cin >> high[i];
        for(int i = 0; i < l; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
        }
        cout << "Teste " << (test++) << endl;
        cout << bfs(init) << "\n\n";
    }
    return 0;
}
