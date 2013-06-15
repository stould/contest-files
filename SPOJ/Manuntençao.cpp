#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int f, to, i, j, k, n, m, graph[500][500], vis[500], t = 1;

void dfs(int n, int s) {
    vis[n] = true;
    for(int tmp = 1; tmp <= n; tmp++) {
        if(graph[n][tmp] && tmp != s) {
            dfs(tmp, s);
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(cin >> n >> m && n > 0 && m > 0) {
        memset(graph, 0, sizeof(graph));
        for(i = 0; i < m; i++) {
            cin >> f >> to;
            graph[f][to] = graph[to][f] = 1;
        }
        int count = 0;
        printf("Teste %d\n", (t++));
        for(i = 1; i <= n; i++) {
            bool ok = true;
            for(j = 1; j <= n; j++) if(i != j) {
                memset(vis, 0, sizeof(vis));
                dfs(j, i);
                for(k = 1; k <= n; k++) {
                    if(!vis[k] && k != i) {
                        ok = false;
                        break;
                    }
                }
            }
            if(!ok) {
                printf("%d ", i);
                count += 1;
            }
        }
        if(!count) {
            printf("nenhum");
        }
        printf("\n\n");
    }
    return 0;
}
