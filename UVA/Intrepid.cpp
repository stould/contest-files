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
typedef unsigned uint;

const int MAXN = 100005;

int N, F;
int VF[MAXN];
vector<pair<int, int> > tree[MAXN];

//LCA
int parent[MAXN], L[MAXN], vis[MAXN], height[MAXN];
vector<int> level[MAXN];
int P[MAXN][20];
Int dist[MAXN];

void dfs(int pos, int par, int deep) {
    if (parent[pos] == -1) {
		height[pos] = deep;
        parent[pos] = par;
		
        for(int i = tree[pos].size() - 1,to;i >= 0;--i){
            to = tree[pos][i].first;
            if(to != par) {
                dist[to] = dist[pos] + tree[pos][i].second;
                dfs(to,pos, deep + 1);
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
	for (int i = 0;i < N; ++i) {
		L[i] = get_level(i);
	}

	for (int i = 0;i < N;++i) {
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
        if(P[p][i] !=- 1 && P[p][i] != P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }

    return parent[p];
}

//sort by tree level
bool cmp(int x, int y) {
	return dist[x] < dist[y];	
}

//spent to go from x to y
Int climb_time(int x, int y) {
	return dist[x] - dist[LCA(x, y)];
}

int main(void) {
	for ( ; scanf("%d%d", &N, &F) == 2; ) {
		for (int i = 0; i <= N; i++) {
			vis[i] = height[i] = 0;
			L[i] = parent[i] = -1;
			dist[i] = 0LL;
			tree[i].clear();
		}

		int A, B, C;

		for (int i = 1; i < N; i++) {
			scanf("%d%d%d", &A, &B, &C);

			A -= 1;
			B -= 1;

			tree[A].push_back(make_pair(B, C));
			tree[B].push_back(make_pair(A, C));
		}
		
		for (int i = 0; i < F; i++) {
			scanf("%d", &VF[i]);
			VF[i] -= 1;
		}

		dfs(0, -2, 0);
		parent[0] = -1;
		init();

		sort(VF, VF + F, cmp);
		
		Int ans = 0LL;

		for (int i = 0; i < F - 1; i++) {
			ans += climb_time(VF[i], VF[i + 1]);
		}

		printf("%lld\n", ans);
		
	}
    return 0;
}
