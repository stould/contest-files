#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a, b, n, m, ans, graph[1005][1005], vis[1005];

void dfs(int x) {
    vis[x] = true;
    for(int i = 1; i <= n; i++) {
        if(!vis[i] && graph[x][i]) dfs(i);
    }
}

int main(void) {
    while(scanf("%d%d", &n, &m) == 2) {
        memset(graph, 0, sizeof(graph));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b); graph[a][b] = graph[b][a] = 1;
        }
        ans = 0;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                ans += 1; dfs(i);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
