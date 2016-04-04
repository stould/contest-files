
struct node{
    vector<int> sortedLabel;
    int label;
    int pos;
    int quem;
    node(){label = 0;}
    node( int pos_, int quem_):  pos(pos_), quem(quem_){label = 0;}
    bool operator < (const node &o) const{
        return sortedLabel < o.sortedLabel;
    }
 
    void clear(){
        sortedLabel.clear();
        label = 0;
    }
 
};
 
vector<vector<node> > level(MAXN);
 
int bfs(int center){
    queue<pair<int, int> > q;
    for(int i = 0; i < MAXN; i++){
        dist[i] = INF;
        vis[i] = 0;
    }
    int maxLevel = 0;
    dist[center] = 0;// or level = 0
    q.push(make_pair(center, -1));
    vis[center] = 1;
    while(!q.empty()){
        int top = q.front().first;
        int pos_parent = q.front().second;
        q.pop();
        level[dist[top]].push_back(node(pos_parent, top));
        for(int i = 0; i < graph[top].size(); i++){
            int next = graph[top][i];
            if(!vis[next]){
                dist[next] = dist[top] + 1;
                vis[next] = 1;
                maxLevel = max(maxLevel, dist[next]);
                q.push(make_pair(next, level[dist[top]].size() - 1));
            }
        }
    }
    return maxLevel;
}
 
bool rootedTreeIsomorphic(int r1, int r2){
    for(int i = 0; i < MAXN; i++) level[i].clear();
    int h1 = bfs(r1);
    int h2 = bfs(r2);
    if(h1 != h2){
        return false;
    }
    for(int i = h1-1; i >= 0; i--){
        for(int j = 0; j < level[i+1].size(); j++){
            node v = level[i+1][j];
            level[i][v.pos].sortedLabel.push_back(v.label);
        }
 
        for(int j = 0; j < level[i].size(); j++){
            sort(level[i][j].sortedLabel.begin(), level[i][j].sortedLabel.end());
        }
        sort(level[i].begin(), level[i].end());
        int cnt = 0;
        for(int j = 0; j < level[i].size(); j++){
            if(j > 0 && level[i][j].sortedLabel != level[i][j-1].sortedLabel) {
                cnt++;
            }
            level[i][j].label = cnt;
        }
    }
    return level[0][0].sortedLabel == level[0][1].sortedLabel;
}
 
bool isIsomorphic(){
    vector<int> r2 = findCenter(n);
    vector<int> r1 = findCenter(0);
    if(r1.size() != r2.size()){
        return false;
    }else{
        if(r1.size() == 1){
            return rootedTreeIsomorphic(r1[0], r2[0]);
        }else {
            return rootedTreeIsomorphic(r1[0], r2[0]) || rootedTreeIsomorphic(r1[0], r2[1]) || rootedTreeIsomorphic(r1[1], r2[0]) || rootedTreeIsomorphic(r1[1], r2[1]);
        }
    }
}
