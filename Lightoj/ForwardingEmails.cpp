#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int i, t, n, a, b, test, ind, vis[50010], order[50000];

void dfs(vector<int> graph[], int x) {
    vis[x] = true;
    for(int u = 0; u < graph[x].size(); u++) {
        if(!vis[graph[x][u]]) dfs(graph, graph[x][u]);
    }
    order[ind++] = x;
}

int main(void) {
    scanf("%d", &t); test = 1;
    for(; t > 0; t--) {
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis)); ind = 0;
        vector<int> graph[n+1];
        for(i = 0; i < n; i++) {
            scanf("%d%d", &a, &b); graph[a].push_back(b);
        }
        for(i = 1; i <= n; i++) {
            if(!vis[i]) dfs(graph, i);
        }
        printf("Case %d: %d\n", test++, order[n-1]);
    }
    return 0;
}
