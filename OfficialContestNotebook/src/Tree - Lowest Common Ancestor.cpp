struct LCA{
   
    LCA(){
        build();
    }
 
    void build(){
        int base = 1;
        int pot = 0;
        for(int i = 0; i < 2*MAXN; i++){
            if(i >= base * 2){
                pot++;
                base *= 2;
            }
            pre[i] = pot;
            dp[i][0] = i;
        }
        base = 2;
        pot = 1;
        while(base <= 2*n){
            for(int i = 0; i + base / 2 < 2*n; i++){
                int before = base / 2;
                if(L[dp[i][pot-1]] < L[dp[i + before][pot-1]]){
                    dp[i][pot] = dp[i][pot-1];
                }else{
                    dp[i][pot] = dp[i + before][pot-1];
                }
            }
            base *= 2;
            pot++;
        }
    }
 
    int getLca(int u, int v){
        int l = H[u];
        int r = H[v];
        if(l > r){
            swap(l,r);
        }
        int len = r-l+1;
        if(len == 1){
            return E[dp[r][0]];
        }else{
            int base = (1 << pre[len]);
            int pot = pre[len];
            if(L[dp[l][pot]] < L[dp[r-base+1][pot]]){
                return E[dp[l][pot]];
            }else{
                return E[dp[r-base+1][pot]];
            }
        }
    }
 
};
 
void dfs(int x, int depth){
    vis[x] = 1;
    if(H[x] == -1) H[x] = idx;
    L[idx] = depth;
    E[idx++] = x;
    for(int i = 0; i < g[x].size(); i++){
        int next = g[x][i].first;
        int cost = g[x][i].second;
        if(!vis[next]){
            dfs(next, depth+1);
            L[idx] = depth;
            E[idx++] = x;
        }
    }
}
