//LCA O(<Nlog(N)>, <log(N)>)
int N, Q, A, B;
vector<pair<int, int> > adj[MAXN];
int parent[MAXN], L[MAXN], vis[MAXN];
vector<int> level[MAXN];
int P[MAXN][20];
Int dist[MAXN];

void dfs(int pos, int par){
    if(parent[pos] == -1){
        parent[pos] = par;
		
        for(int i = adj[pos].size() - 1,to;i >= 0;--i){
            to = adj[pos][i].first;
            if(to != par) {
                dist[to] = dist[pos] + adj[pos][i].second;
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

void init() {
	for(int i = 0;i<N;++i) {
		L[i] = get_level(i);
	}

	for(int i = 0;i < N;++i) {
		level[L[i]].push_back(i);
	}

	memset(P,-1,sizeof(P));
	
	for(int i = 0; i < N; ++i) {
		P[i][0] = parent[i];
	}
	
	for(int j = 1; (1<<j) < N; ++j) {
		for(int i = 0; i < N; ++i) {
			if(P[i][j-1]!=-1) {
				P[i][j] = P[P[i][j-1]][j-1];
			}
		}
	}
}

int LCA(int p, int q) {
    if(L[p] < L[q]) {
		swap(p,q);
	}

    int log = 1;
    while((1<<log)<=L[p]) ++log;
    --log;

    for(int i = log;i>=0;--i)
        if(L[p]-(1<<i)>=L[q])
            p = P[p][i];

    if (p==q) return p;

    for(int i = log;i>=0;--i){
        if(P[p][i]!=-1 && P[p][i]!=P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }

    return parent[p];
}

for (i = 0; i <= N; i++) {
	vis[i] = 0;
	L[i] = parent[i] = -1;
	dist[i] = 0LL;
	adj[i].clear();
 }
for (i = 1; i < N; i++) {
	scanf("%d%d", &t, &l);
	adj[i].push_back(make_pair(t, l));
	adj[t].push_back(make_pair(i, l));
 }

dfs(0, -2);
parent[0] = -1;
init();
