void dfs(int x) {
    vis[x] = 1;
    for(int u = 0; u < n; u++) {
        if(vis[u] == 1 && graph[x][u] == 1) has = true;
        if(vis[u] == 0 && graph[x][u] == 1) {
            dfs(u);
        }
    }
    vis[x] = 2;
    order.push_back(x);
}
