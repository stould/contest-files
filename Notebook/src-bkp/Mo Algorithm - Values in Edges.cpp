//For the euler tour tree
int in[MAXN], out[MAXN], ID[MAXN*2], dfsCnt;
int lca[MAXN][LOGN], level[MAXN];
vector<vector<pair<int, int> > > graph(MAXN);//<next, value>
int incomingEdge[MAXN];

//Dfs to mount LCA table and do a in-order visit
//storing first and last time to visit a node
void eulerTour(int node, int parent, int cost){
    in[node] = ++dfsCnt;
    ID[dfsCnt] = node;
    incomingEdge[node] = cost;
    for(int i = 0; i < (int) graph[node].size(); i++){
        pair<int, int> next = graph[node][i];
        if(next.first != parent){
            level[next.first] = level[node] + 1;
            eulerTour(next.first, node, next.second);
        }
    }
    out[node] = ++dfsCnt;
    ID[dfsCnt] = node;
}

struct query{
    int l, r, id, lca;

    query(){}
    query(int L, int R, int ID_, int LCA){
        l = L;
        r = R;
        id = ID_;
        lca = LCA;
    }

    bool operator < (const query &o) const{
        return r < o.r;
    }
};

//For Mo's algo:
int resp[MAXN];
int seen[MAXN];
int f[MAXN], ff[MAXN], big;

//add and remove in this case gets how many times
//appears the most frequent element in a range
void add(int color){
    ff[f[color]]--;
    f[color]++;
    ff[f[color]]++;
    if(f[color] > big){
        big = f[color];
    }
}
void remove(int color){
    ff[f[color]]--;
    f[color]--;
    ff[f[color]]++;
    if(ff[big] <= 0){
        big--;
    }
}

//If a node is visited 0 or two times, then,
//this node is not part of path A and B.
void fix(int node, int color){
    if(color != 0){
        if(seen[node] == 1){
            remove(color);
        }else{
            add(color);
        }
        seen[node] ^= 1;
    }
}

void processMo(int pos, vector<vector<query> > &blocks){
    sort(blocks[pos].begin(), blocks[pos].end());
    int l = blocks[pos][0].l-1, r = blocks[pos][0].l-1, ql, qr, id, lca_;
    big = 0;
    for(int i = 0; i < (int) blocks[pos].size(); i++){
        ql = blocks[pos][i].l;
        qr = blocks[pos][i].r;
        id = blocks[pos][i].id;
        lca_ = blocks[pos][i].lca;

        while(r < qr){
            fix(ID[r], incomingEdge[ID[r]]);
            r++;
        }
        while(l < ql){
            fix(ID[l], incomingEdge[ID[l]]);
            l++;
        }
        while(l > ql){
            l--;
            fix(ID[l], incomingEdge[ID[l]]);
        }
        
        /*
          The corner case, if we the problemas asks something on edges,
          as we stored the values of the edge on the children (comming down from the root),
          the LCA will add a wrong information about the path of nodes A and B.
          So we just remove it sepparated from the query, then asnwer the query, then add again LCA.
        */
        if (ID[l] == lca_ || ID[r] == lca_) fix(lca_, incomingEdge[lca_]);
        resp[id] = big;
        if (ID[l] == lca_ || ID[r] == lca_) fix(lca_, incomingEdge[lca_]);
    }
    while(l < r){
        fix(ID[l], incomingEdge[ID[l]]);
        l++;
    }
}

int QU[MAXN], QV[MAXN], Q; //attention on array size

//fill the blocks with queries
void fillBlocks(vector<vector<query> > &blocks, const int BLOCK_SIZE){
    for(int i = 0; i < Q; i++){
        int u = QU[i], v = QV[i];
        if(u == v){
            resp[i] = 0;
            continue;
        }
        if(in[u] > in[v]) swap(u,v);
        query q(-1, -1, i, getLca(u,v));
        if(q.lca == u || q.lca == v){
            q.l = in[u], q.r = in[v];
        }else{
            q.l = out[u], q.r = in[v];
        }
        q.r++;
        blocks[q.l / BLOCK_SIZE].push_back(q);
    }
}

int N;

//build the tree -> vector graph
for(int i = 0; i < Q; i++){
    cin >> QU[i] >> QV[i];
 }

dfsCnt = 0;
eulerTour(1, -1, 0);

int BLOCK_SIZE = sqrt(N*2) + 1;
vector<vector<query> > blocks(BLOCK_SIZE);

fillBlocks(blocks, BLOCK_SIZE);//mounting blocks

for(int i = 0; i < BLOCK_SIZE; i++){
    if(blocks[i].size()){
        processMo(i, blocks);
    }
 }

