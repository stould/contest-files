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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 50010;

int T, N, Q;

vector<int> adj[MAXN];
int parent[MAXN], L[MAXN], vis[MAXN], ans[MAXN];										  
vector<int> level[MAXN];
int P[MAXN][20];
Int dist[MAXN];

void ans_dfs(int x, int curr) {
	if (x == -1) {
		return;
	}

	curr += dist[x];
	
	

	ans[x] += curr;
	
	cout << x << " " << dist[x] << " " << ans[x] << endl;

	dist[x] = 0;

	ans_dfs(parent[x], curr);	
}

void dfs(int pos, int par){
    if(parent[pos] == -1) {
        parent[pos] = par;
		
        for(int i = adj[pos].size() - 1,to;i >= 0;--i){
            to = adj[pos][i];
            if(to != par) {
                dfs(to, pos);
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


int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 0; i <= N; i++) {
			vis[i] = 0;
			L[i] = parent[i] = -1;
			dist[i] = 0LL;
			ans[i] = 0;
			adj[i].clear();
		}

		for (int i = 0; i < N - 1; i++) {
			int A, B;
			cin >> A >> B;

			adj[A].push_back(B);
			adj[B].push_back(A);
		}
		
		dfs(0, -2);
		parent[0] = -1;
		init();

		cin >> Q;

		for (int q = 0; q < Q; q++) {
			int A, B, C;

			cin >> A >> B >> C;

			int lca = LCA(A, B);
			
			//cout << A << " " << B << " => " << lca << " " << parent[lca] << endl;
			if (A == lca or B == lca) {				
				if (parent[lca] >= 0) {
					dist[parent[lca]] -= C;
				}
			
				if (A != lca) {
					dist[A] += C;
				} else {
					dist[B] += C;
				}
			} else {
				//dist[lca] -= C;
				if (parent[lca] >= 0) {
					dist[parent[lca]] -= 2 * C;
				}
				//cout << "ed " << 2 * C << endl;

				dist[A] += C;

				if (A != B) {
					dist[B] += C;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			cerr << "deb " << i << " " << dist[i] << endl;
		}
		for (int i = 1; i < N; i++) {
			if (adj[i].size() == 1) {			
				ans_dfs(i, 0);
			}
		}

		cout << "Case #" << t << ":\n";

		for (int i = 0; i < N; i++) {
			//cout << i << " " << parent[i] << "\n";
			cout << ans[i] << "\n";
		}
	}
	
	return 0;
}
