//For LCA
vector<vector<int> > graph(MAXN);
int lca[MAXN][LOGN], level[MAXN];
 
//For Euler Tour
int ID[MAXN*2], in[MAXN], out[MAXN], dfsCnt;
 
void dfs(int node, int parent){
    lca[node][0] = parent == -1 ? node : parent;
    for(int i = 1; i < LOGN; i++){
        lca[node][i] = lca[lca[node][i-1]][i-1];
    }
    in[node] = ++dfsCnt;
    ID[dfsCnt] = node;
    for(int i = 0; i < (int) graph[node].size(); i++){
        int next = graph[node][i];
        if(next != parent){
            level[next] = level[node] + 1;
            dfs(next, node);
        }
    }
    out[node] = ++dfsCnt;
    ID[dfsCnt] = node;
}
 
//For Mo's algorithm
struct query{
    int l, r, id, lca;
    query(int l_, int r_, int id_, int lca_){
        l = l_, r = r_, id = id_, lca = lca_;
    }
    query(){}
    bool operator < (const query &o) const{
        return r < o.r;
    }
};
 
const int BLOCK_SIZE = sqrt(MAXN*2) + 5;
vector<vector<query> > blocks(BLOCK_SIZE);
 
int N, U, V, Q, value[MAXN], valueTmp[MAXN];
int QU[MAXQ], QV[MAXQ], resp[MAXQ];
int seen[MAXN], cnt[MAXN], ansCnt;
 
void fillBlocks(){
    for(int i = 0; i < Q; i++){
        U = QU[i], V = QV[i];
        int l, r, lca_ = getLca(U, V);
        if(in[U] > in[V]) swap(U,V);
        if(lca_ == U || lca_ == V){
            l = in[U], r = in[V];
        }else{
            l = out[U], r = in[V];
        }
        r++;
        blocks[l / BLOCK_SIZE].push_back(query(l,r,i,lca_));
    }
}
 
void fix(int node){
    int color = value[node];//The value of node
 
    //If the node appears two ou zero times already, we need to add
    if(seen[node] == 0){
        if(cnt[color] == 0){
            ansCnt++;
        }
        cnt[color]++;
    }else{//Remove
        cnt[color]--;
        if(cnt[color] == 0){
            ansCnt--;
        }
    }
    seen[node] ^= 1;
}
 
void process(int pos){
    sort(blocks[pos].begin(), blocks[pos].end());
    int l = blocks[pos][0].l-1, r = l, ql, qr, id, lca_;
    ansCnt = 0;
    for(int i = 0; i < blocks[pos].size(); i++){
        ql = blocks[pos][i].l;
        qr = blocks[pos][i].r;
        id = blocks[pos][i].id;
        lca_ = blocks[pos][i].lca;
        while(r < qr) fix(ID[r++]);
        while(l < ql) fix(ID[l++]);
        while(l > ql) fix(ID[--l]);
 
        //The tree stores the values on the vertex,
        //so the LCA always is not in the path A, B
        //We just add, answer, remove
        if(ID[l] != lca_ && ID[r] != lca_) fix(lca_);
        resp[id] = ansCnt;
        if(ID[l] != lca_ && ID[r] != lca_) fix(lca_);
    }
    ansCnt = 0;
    memset(seen, 0, sizeof(seen));
    memset(cnt, 0, sizeof(cnt));
}

//values[i] = values of the nodes
//be careful, maybe needed to compress this values
//build tree on variable graph
for(int i = 0; i < Q; i++){
    scanf("%d%d", &QU[i], &QV[i]);
 }
dfsCnt = 0;
dfs(1, -1);
fillBlocks();
for(int i = 0; i < BLOCK_SIZE; i++){
    if((int) blocks[i].size()){
        process(i);
    }
 }
