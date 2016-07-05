void addEdge(int U_, int V_){
    graph[U_].push_back(V_);
    graph[V_].push_back(U_);
    deg[U_]++;
    deg[V_]++;
}
 
vector<int> findCenter(){
    queue<int> q;
    //pushing the leaves
    for(int i = 0; i < n; i++){
        dist[i] = 0;
        if(deg[i] == 1){
            q.push(i);
        }
    }
    int further = 0;
    while(!q.empty()){
        int top = q.front(); q.pop();
        for(int i = 0; i < graph[top].size(); i++){
            int next = graph[top][i];
            deg[next]--;
            if(deg[next] == 1){
                q.push(next);
                dist[next] = dist[top] + 1;
                further = max(further, dist[next]);
            }
        }
    }
    vector<int> ans;
    //all reachable nodes with the maximum distance, belong to the center
    for(int i = 0; i < n; i++){
        if(dist[i] == further){
            ans.push_back(i);
        }
    }
    return ans;
}
