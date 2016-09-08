vector<int> G[MAXN], R[MAXN];
vector<int> order;
int vis[MAXN], cmp[MAXN];
stack<int> topo;

void dfs1(int node) {
    vis[node] = true;

    for (int i = 0; i < (int) G[node].size(); i++) {
        int next = G[node][i];

        if (!vis[next]) {
            dfs1(next);
        }
    }
    topo.push(node);
    order.push_back(node);
}

void dfs2(int node, int curr_comp) {
    vis[node] = true;
    cmp[node] = curr_comp;

    for (int i = 0; i < (int) R[node].size(); i++) {
        int next = R[node][i];

        if (!vis[next]) {
            dfs2(next, curr_comp);
        }
    }
}

void retrieve() {
    for (int i = 2; i <= 2 * N + 1; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    memset(vis, false, sizeof(vis));

    int cp = 1;
    
    while (!topo.empty()) {
        int now = topo.top();
        topo.pop();
        
        if (!vis[now]) {
            dfs2(now, cp++);
        }
    }
    
    bool fine = true;
    
    for (int i = 2; i <= 2 * N + 1; i++) {
        if (cmp[i] == cmp[i ^ 1]) {
            fine = false;
        }
    }

    if (!fine) {
        cout << "Impossible" << endl;
    } else {
        vector<int> ans;
        
        memset(vis, false, sizeof(vis));
        
        for (int i = 0; i < (int) order.size(); i++) {
            int now = order[i];
            
            if (!vis[now / 2]) {
                if (now % 2 == 0) {
                    ans.push_back(now / 2);
                }
            }
            vis[now / 2] = 1;
        }

    }
}
