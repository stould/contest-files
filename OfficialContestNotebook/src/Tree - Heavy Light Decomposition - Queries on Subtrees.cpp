int max_color[MAXN], sz[MAXN];
ll sum, bigger, ans[MAXN];
vector<vector<int> > graph(MAXN);
int n, color[MAXN];
bool heavy[MAXN];
 
 
//get the size of each subtree
void getSz(int u, int parent){
    sz[u] = 1;
    for(int i = 0; i < (int) graph[u].size(); i++){
        int v = graph[u][i];
        if(v == parent) continue;
        getSz(v, u);
        sz[u] += sz[v];
    }
}
 
 
//just update the asnwer
void reval(int col){
    max_color[col]++;
    if(bigger < max_color[col]){
        bigger = max_color[col];
        sum = col;
    }else if(bigger == max_color[col]){
        sum += col;
    }
}
 
 
//Goes through the light childs and add all nodes to the answer
void add(int u, int parent){
    reval(color[u]);
    for(int i = 0; i < (int)graph[u].size(); i++){
        int v = graph[u][i];
        if(!heavy[v] && v != parent){
            add(v, u);
        }
    }
}
 
 
//remove from the answer all nodes in the subtree (only light nodes)
void remove(int u, int parent){
    max_color[color[u]]--;
    for(int i = 0; i < (int)graph[u].size(); i++){
        int v = graph[u][i];
        if(!heavy[v] && v != parent){
            remove(v, u);
        }
    }    
}
 
//This dfs asnwer all querys of the type:
//How many noes in subtree of V are black.. or something like that
void dfs(int u, int parent, bool keep){
    int bigChild = -1, cnt = -1;
    for(int i = 0; i < (int)graph[u].size(); i++){
        int v = graph[u][i];
        if(sz[v] > cnt && v != parent){
            cnt = sz[v];
            bigChild = v;
        }
    }
    for(int i = 0; i < (int)graph[u].size(); i++){
        int v = graph[u][i];
        if(v != parent && v != bigChild){//goes down the light nodes
            dfs(v, u, 0);
        }
    }
    if(bigChild != -1){//goes down the heavy node only once
        dfs(bigChild, u, 1);
        heavy[bigChild] = 1;
    }
    add(u, parent);
    ans[u] = sum;
    if(bigChild != -1){
        heavy[bigChild] = 0;
    }
    if(keep == 0){
        remove(u, parent);
        bigger = 0;
        sum = 0;
    }
}
 
// on main:
getSz(1,-1);
dfs(1, -1, 0);
