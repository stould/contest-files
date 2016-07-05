#include <vector>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int a, b, n, m, cont, ct, vis[1010], nivel[1010], menor[1010], pai[1010];
vector<int> graph[1010];

void dfs(int x) {
    vis[x] = 1;
    nivel[x] = menor[x] = cont++;
    int sons = 0;
    for(int i = 0; i < graph[x].size(); i++) {
        if(vis[graph[x][i]] == 0) {
            sons += 1;
            pai[graph[x][i]] = x;
            dfs(graph[x][i]);
            if(menor[graph[x][i]] < menor[x]) menor[x] = menor[graph[x][i]];
            if(menor[graph[x][i]] == nivel[graph[x][i]]) {
                ct++;
            }
        } else if(vis[graph[x][i]] == 1 && pai[x] != graph[x][i]) {
            if(nivel[graph[x][i]] < menor[x]) menor[x] = nivel[graph[x][i]];
        }
    }
    vis[x] = 2;
}


int main(void) {
    for( ; scanf("%d%d", &n, &m) && !(n == 0 && m == 0); ) {
        for(int i = 0; i <= n; i++) graph[i].clear();
        cont = 0;
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i = 1; i <= n; i++) {
            vis[i] = 0;
            pai[i] = i;
        }
        ct = 0;
        dfs(1);
        if(ct == 0) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}
