#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

const int MAXN = 3030;

int T, N, M, Q;
vector<pair<int, int> > adj[MAXN];
int parent[MAXN], parentCost[MAXN], L[MAXN], vis[MAXN];
vector<int> level[MAXN];
int P[MAXN][20];
Int dist[MAXN];


struct UnionFind {
    int N, *id, *sz;

    UnionFind(int _N) {
        id = new int[_N];
        sz = new int[_N];
        for(int i = 0; i < _N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        N = _N;
    }
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        if(i == j) return;
        if(sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
    }
};

struct edge {
    int from, to, cost;
    edge() {}
    edge(int from, int to, int cost): from(from), to(to), cost(cost) {};

    bool operator<(const edge& e) const {
        return cost < e.cost;
    }
};


void dfs(int pos, int par){
    if(parent[pos] == -1){
        parent[pos] = par;

        for(int i = adj[pos].size() - 1,to;i >= 0;--i){
            to = adj[pos][i].first;
            if(to != par) {
                dist[to] = dist[pos] + adj[pos][i].second;
                parentCost[to] = adj[pos][i].second;
                dfs(to,pos);
            }
        }
    }
}

int get_level(int u){
    if(L[u]!=-1) return L[u];
    else if(parent[u]==-1) return 0;
    return 1+get_level(parent[u]);
}

void init(){
  for(int i = 0;i<N;++i) L[i] = get_level(i);

  for(int i = 0;i < N;++i) level[L[i]].push_back(i);

  memset(P,-1,sizeof(P));

  for(int i = 0;i<N;++i) P[i][0] = parent[i];

  for(int j = 1;(1<<j)<N;++j)
      for(int i = 0;i<N;++i)
        if(P[i][j-1]!=-1)
          P[i][j] = P[P[i][j-1]][j-1];
}

int LCA(int p, int q){
    if(L[p]<L[q]) swap(p,q);

    int log = 1;
    while((1<<log)<=L[p]) ++log;
    --log;

    for(int i = log;i>=0;--i)
        if(L[p]-(1<<i)>=L[q])
            p = P[p][i];

    if(p==q) return p;

    for(int i = log;i>=0;--i){
        if(P[p][i]!=-1 && P[p][i]!=P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }

    return parent[p];
}

int getMax(int curr, int goal, int now) {
    if (curr == goal) {
        return now;
    } else {
        return getMax(parent[curr], goal, max(now, parentCost[curr]));
    }
}


int main() {
    cin >> T;
   
    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
       
        for (int i = 0; i <= N; i++) {
            vis[i] = 0;
            L[i] = parent[i] = -1;
            dist[i] = 0LL;
            adj[i].clear();
        }

        vector<edge> ve;
       
        for (int i = 0; i < M; i++) {
            int A, B, C;           
            cin >> A >> B >> C;
           
            A -= 1;
            B -= 1;
           
            ve.push_back(edge(A, B, C));
        }
               
        sort(ve.begin(), ve.end());   
       
        UnionFind uf(N + 1);
       
        for (int i = 0; i < M; i++) {
            if (!uf.find(ve[i].from, ve[i].to)) {
                uf.unite(ve[i].from, ve[i].to);                   
                adj[ve[i].from].push_back(make_pair(ve[i].to, ve[i].cost));
                adj[ve[i].to].push_back(make_pair(ve[i].from, ve[i].cost));
            }
        }
       
        dfs(0, -2);
        parent[0] = -1;
        init();
       
        cout << "Case " << t << "\n";

        cin >> Q;                       
        for (int i = 0; i < Q; i++) {
            int A, B;
            cin >> A >> B;
           
            A -= 1;
            B -= 1;
           
            int r = LCA(A, B);
           
            cout << max(getMax(A, r, 0), getMax(B, r, 0)) << "\n";
        }   
        cout << "\n";
    }   
   
    return 0;
}
	
