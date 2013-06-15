#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n, m, a, b;
bool cycle;
vector<int> graph[10010], vis;

void dfs(int x) {
    vis[x] = 1;
    for(int i = 0; i < graph[x].size(); i++) {
        if(vis[graph[x][i]] == 2) cycle = true;
        if(!vis[graph[x][i]]) dfs(graph[x][i]);
    }
    vis[x] = 2;
}

int main(void) {
    scanf("%d%d", &n, &m);
    vis.assign(n + 1, 0);
    cycle = false;
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    int many = 0;
    for(int i = 1; i <= n; i++) if(vis[i] == 2) many++;
    if(many == n && !cycle) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
