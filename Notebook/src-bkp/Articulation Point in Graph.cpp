vector<int> graph[410];
set<int> ans;
set<int>::iterator it;

int dfs(int u){
    int less = vis[u] = times++;
    int filhos = 0;
    for(int i = 0; i< graph[u].size(); i++){
       if(vis[graph[u][i]]==0){
          filhos++;
          int m = dfs(graph[u][i]);
          less = min(less,m);
          if(vis[u] <= m && (u != 0 || filhos >= 2)){
              ans.insert(u);
          }
       }else{
          less = min(less, vis[graph[u][i]]);
       }
    }
    return less;
}
times = 1;
ans.clear();
dfs(0);
