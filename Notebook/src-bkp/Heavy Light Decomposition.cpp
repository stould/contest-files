vector<vector<pair<int,int> > > g(MAXN);
int cnt[MAXN], prev[MAXN], chainNode[MAXN], chainHead[MAXN], posInChain[MAXN], base[MAXN], level[MAXN], chainIdx, idxSegTree;
int H[MAXN], L[MAXN << 1], E[MAXN << 1], idx;
 
struct LCA{        
    int tree[MAXN * 8];
    LCA(int root, int n){
        build(1, 0, 2*n-1);
    }
 
    //NlogN build the segtree and minimize the height of the I'th visited node
    void build(int node, int l, int r){
        if(l > r) return;
        if(l == r){
            tree[node] = l;
        }else{
            int mid = (l+r) >> 1;
            build(node*2, l, mid);
            build(node*2+1, mid+1, r);
            int A = tree[node*2];
            int B = tree[node*2+1];
            if(L[A] <= L[B]){
                tree[node] = A;
            }else{
                tree[node] = B;
            }
        }
    }
 
    //Get the vertex with the minimum height, then it will be the LCA of A and B.
    int rmq(int node, int l, int r, int ra, int rb){
        if(l > rb || r < ra){
            return -1;
        }else if(l >= ra && r <= rb){
            return tree[node];
        }else{
            int mid = (l+r) >> 1;
            int q1 = rmq(node*2, l, mid, ra, rb);
            int q2 = rmq(node*2+1, mid+1, r, ra, rb);
            if(q1 == -1){
                return q2;
            }else if(q2 == -1){
                return q1;
            }else{
                if(L[q1] <= L[q2]){
                    return q1;
                }else{
                    return q2;
                }
            }
        }
    }
 
    int getLCA(int u, int v, int n){
        int goFrom = H[u];
        int goTo = H[v];
        if(goFrom > goTo){
            swap(goFrom, goTo);
        }
        return E[rmq(1, 0, 2*n-1, goFrom, goTo)]; //is the LCA of A and B;
    }
};
 
struct SegTree{
 
    int tree[MAXN*4];
 
    SegTree(){
        memset(tree,0,sizeof(tree));
    }
       
 
    void build(int node, int l, int r){
        if(l > r) return;
        if(l == r){
            tree[node] = l;
        }else{
            int mid = (l+r) >> 1;
            build(node*2, l, mid);
            build(node*2+1, mid+1, r);
            int A = tree[node*2];
            int B = tree[node*2+1];
            tree[node] = base[A] > base[B] ? A : B;
        }
    }
 
    int rmq(int node, int l, int r, int ra, int rb){
        if(l > rb || r < ra){
            return -1;
        }else if(l >= ra && r <= rb){
            return tree[node];
        }else{
            int mid = (l+r) >> 1;
            int q1 = rmq(node*2, l, mid, ra, rb);
            int q2 = rmq(node*2+1, mid+1, r, ra, rb);
            if(q1 == -1){
                return q2;
            }else if(q2 == -1){
                return q1;
            }else{
                return base[q1] > base[q2] ? q1 : q2;
            }
        }
    }
       
    void update(int node, int l, int r, int pos, int value) {
        if (l > r) return;     
        if (l == r) {
            base[pos] = value;
        } else {
            int m = (l + r) >> 1;
            if (pos <= m) {
                update(2 * node, l, m, pos, value);
            } else {
                update(2 * node + 1, m + 1, r, pos, value);
            }
            tree[node] = base[tree[2 * node]] > base[tree[2 * node + 1]] ? tree[2 * node] : tree[2 * node + 1];
        }
    }
};
 
//Decompose the tree into chains
void HLD(int node, int cost, int parent){
    if(chainHead[chainIdx] == -1){
        chainHead[chainIdx] = node;
    }
    chainNode[node] = chainIdx;
    posInChain[node] = idxSegTree;
    base[idxSegTree++] = cost;
    int nodeHeavy = -1, nextCost;
    //seeking the special child (the one with most childs on the subtrees)
    for(int i = 0; i < g[node].size(); i++){
        int next = g[node][i].first;
        if(next != parent && (nodeHeavy == -1 || cnt[next] > cnt[nodeHeavy])){
            nodeHeavy = next;
            nextCost = g[node][i].second;
        }
    }
    if(nodeHeavy > -1){
        //expanding the current chain
        HLD(nodeHeavy, nextCost, node);
    }
       
    for(int i = 0; i < g[node].size(); i++){
        int next = g[node][i].first;
        if(next != nodeHeavy && next != parent){
            chainIdx++;
            HLD(next, g[node][i].second, node);
        }
    }
 
}
 
void dfsCnt(int node, int parent, int depth = 0){
    if(H[node] == -1) H[node] = idx;//mark first time the i'th node is visited
    L[idx] = depth;//when you visit a node you should mark the the depth you have found it.
    E[idx++] = node;//the i'th recursion, global variable
    level[node] = depth;
    cnt[node] = 1;
    for(int i = 0; i < g[node].size(); i++){
        int next = g[node][i].first;
        if(next != parent){
            prev[next] = node;
            dfsCnt(next, node, depth + 1);
            cnt[node] += cnt[next];
            L[idx] = depth;
            E[idx++] = node;
        }
    }      
}
 
int walkChain(int U, int V, SegTree &q, int n){
    if(U == V) return 0;
    int ans = 0;
    while(chainNode[U] != chainNode[V]){
        int Left = posInChain[chainHead[chainNode[U]]];
        int Right = posInChain[U];
        int val = base[q.rmq(1, 0, n-1, Left, Right)];
        if(val > ans) ans = val;
        U = prev[chainHead[chainNode[U]]];
    }
    if(U == V) return ans;
    int val = base[q.rmq(1, 0, n-1, posInChain[V]+1, posInChain[U])];
    if(val > ans) ans = val;
    return ans;
}
 
int getMax(int U, int V, LCA &ref, SegTree &q, int n){
    int lca = ref.getLCA(U, V, n),a=0,b=0;
    if(lca != U)
        a = walkChain(U, lca, q, n);
    if(lca != V)
        b = walkChain(V, lca, q, n);
    return max(a,b);
}
 
void update(int a, int b, int c, SegTree &q, int n){
    if(level[a] < level[b]){//update b
        q.update(1,0,n-1,posInChain[b], c);
    }else{//update a
        q.update(1,0,n-1,posInChain[a], c);
    }
}
void add(int a, int b, int c){
    g[a].push_back(make_pair(b,c));
    g[b].push_back(make_pair(a,c));
}
 
int n, t, from[MAXN], to[MAXN], cost[MAXN], A, B;
char TYPE[20];
 
int main(void){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        chainIdx = idxSegTree = idx = 0;
        for(int i = 0; i <= n; i++){
            cnt[i] = prev[i] = chainNode[i] = base[i] = level[i] = 0;
            chainHead[i] = posInChain[i] = H[i] = -1;
            g[i].clear();
        }
        memset(L,0,sizeof(L));
        memset(E,0,sizeof(E));
        for(int i = 0; i < n - 1; i++){
            scanf("%d%d%d", &from[i], &to[i], &cost[i]);
            from[i]--;
            to[i]--;
            add(from[i], to[i], cost[i]);
        }
        dfsCnt(0,-1);
        LCA lca(0,n);
        HLD(0,-1, -1);
        SegTree query;
        query.build(1,0,n-1);
        while(1){
            scanf("%s", TYPE);
            if(TYPE[0] == 'D') break;
            scanf("%d%d", &A, &B);
            A--;
            if(TYPE[0] == 'Q'){    
                B--;
                printf("%d\n", getMax(A, B, lca, query, n));
            }else if(TYPE[0] == 'C'){
                update(from[A], to[A], B, query, n);
            }
        }
    }
    return 0;
}
