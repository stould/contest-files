vector<pair<int, Int> > tree[MAXN];
int lca[MAXN][MAX_LOG];
Int dist[MAXN];
int height[MAXN];

void dfs(int node, Int curr_cost, int p) {
    dist[node] = curr_cost;
    lca[node][0] = p;
    
    for (int i = 1; i < MAX_LOG; i++) {
        lca[node][i] = lca[lca[node][i - 1]][i - 1];        
    }

       
    for (int i = 0; i < (int) tree[node].size(); i++) {
        int next = tree[node][i].first;
        Int cost = tree[node][i].second;

        if (next == p) continue;

        height[next] = height[node] + 1;

        dfs(next, curr_cost + cost, node);
    }
}

int getLca(int p, int q) {
    if (height[q] > height[p]) {
        swap(p, q);
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (height[p] - (1 << i) >= height[q]) {
            p = lca[p][i];
        }
    }
    
    if (p == q) return p;

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (lca[p][i] != -1 && lca[p][i] != lca[q][i]) {
            p = lca[p][i];
            q = lca[q][i];
        }
    }
    return lca[p][0];
}

Int getCost(int p, int q) {
    return dist[p] + dist[q] - 2 * dist[getLca(p, q)];
}
