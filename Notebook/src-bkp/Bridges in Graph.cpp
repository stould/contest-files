int dfsct, bridges, num[MAXN], low[MAXN], parent[MAXN];
 
void bridge(int atual){
    num[atual] = low[atual] = dfsct++;
    for(int i = 0; i < graph[atual].size(); i++){
        int next = graph[atual][i];
        if(num[next] == -1){
            parent[next] = atual;
            bridge(next);
            if(low[next] > num[atual]){
                bridges++;
            }
            low[atual] = min(low[atual], low[next]);
        }else if(next != parent[atual]){
            low[atual] = min(low[atual], num[next]);
        }
    }
}
 
void countBridges(){
    dfsct = bridges = 0;
    for(int i = 0; i < n; i++){
        num[i] = -1;
        parent[i] = 0;
    }
    for(int i = 0; i < n; i++){
        if(num[i] == -1) bridge(i);
    }
}
