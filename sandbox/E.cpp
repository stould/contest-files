#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 200005;

int N, Q, A, B, K;
vector<pair<int, int> > adj[MAXN];
int parent[MAXN], L[MAXN], vis[MAXN];
vector<int> level[MAXN];
int P[MAXN][20];
Int dist[MAXN];

void dfs(int pos, int par){
    if(parent[pos] == -1){
        parent[pos] = par;
		
        for(int i = (int) adj[pos].size() - 1,to;i >= 0;--i){
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

Int getDist(int a, int b) {
    int lca = LCA(a, b);

    Int ans = dist[a] + dist[b];

    if (parent[lca] != -1) {
        ans -= dist[parent[lca]];
    }
    
    return ans;
}
int main(void) {
    cin >> N >> K;

    set<int> useful;
    
    for (int i = 0; i < 2 * K; i++) {
        int U;
        cin >> U;
        U -= 1;
        
        useful.insert(U);
    }
    
    for (int i = 0; i <= N; i++) {
	vis[i] = 0;
	L[i] = parent[i] = -1;
	dist[i] = 0LL;
	adj[i].clear();
    }
    
    for (int i = 1; i < N; i++) {
        int a, b;
        
	cin >> a >> b;

        a -= 1;
        b -= 1;
        
	adj[a].push_back(make_pair(b, 1));
	adj[b].push_back(make_pair(a, 1));
    }    

    dfs(0, -2);
    parent[0] = -1;
    init();

    queue<int> leaf;
    vector<int> good;
    
    for (int i = 0; i < N; i++) {
        if (adj[i].size() == 1) {
            leaf.push(i);

            if (useful.count(i)) {
                good.push_back(i);
            }
        }
    }
    
    Int ans = 0;

    cout << leaf.size() << "\n";
    
    while (!leaf.empty()) {
        int now = leaf.front();
        leaf.pop();
        cout << now << " " << good.size() << " " << useful.size() << "\n";
        if (good.size() > 1) {
            int ia = good.back();
            good.pop_back();
            int ib = good.back();
            good.pop_back();
            cout << "C " << ia << " " << ib << " " << getDist(ia, ib) << "\n";
            ans += getDist(ia, ib);

            useful.erase(ia);
            useful.erase(ib);
        }
        
        if (useful.count(now)) {
            leaf.push(now);
        } else {
            if (parent[now] != -1) {
                leaf.push(parent[now]);
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
