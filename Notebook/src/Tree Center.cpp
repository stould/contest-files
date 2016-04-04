vector<int> findCenter(int offset){
    queue<int> q;
    //pushing the leaves
    for(int i = 0; i < n; i++){
        vis[i] = 0;
        dist[i] = 0;
        if(deg[i] == 1){
            q.push(i);
        }
    }
    int bigger = 0;
    while(!q.empty()){
        int top = q.front(); q.pop();
        for(int i = 0; i < graph[top].size(); i++){
            int next = graph[top][i];
            deg[next]--;
            if(deg[next] == 1){
                q.push(next);
                dist[next] = dist[top] + 1;
                bigger = max(dist[next], bigger);
            }
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(dist[i] == bigger){
            ans.push_back(i);
        }
    }
    return ans;
}
