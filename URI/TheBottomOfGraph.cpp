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

const int MAXN = 5050;

int N, M;
vector<int> graph[MAXN];
vector<int> graphT[MAXN];
vector<int> order;
int comp[MAXN];
bool vis[MAXN], fail[MAXN];

void dfs(int node) {
	vis[node] = true;
	
	for (int i = 0; i < (int) graph[node].size(); i++) {
		int u = graph[node][i];

		if (!vis[u]) {
			dfs(u);
		}
	}
	
	order.push_back(node);
}

void dfs_rev(int node, int c) {
	vis[node] = true;
	comp[node] = c;
	
	for (int i = 0; i < (int) graphT[node].size(); i++) {
		int u = graphT[node][i];
		
		if (!vis[u]) {
			dfs_rev(u, c);
		}
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	for ( ; cin >> N >> M && N != 0; ) {
		int A, B;
		
		order.clear();
		
		for (int i = 0; i <= N; i++) {
			graph[i].clear();
			graphT[i].clear();
			vis[i] = fail[i] = false;
			comp[i] = -1;
		}
		
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			graph[A].push_back(B);
			graphT[B].push_back(A);
		}
		
		for (int i = 1; i <= N; i++) {
			if (!vis[i]) {
				dfs(i);
			}
		}

		memset(vis, false, sizeof(vis));
		reverse(order.begin(), order.end());

		int c = 0;
		
		for (int i = 0; i < N; i++) {
			int u = order[i];
			
			if (!vis[u]) {
				dfs_rev(u, c++);
				fail[c - 1] = false;
			}
			//cout << u << " " << comp[u] << endl;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < (int) graph[i].size(); j++) {
				if (comp[i] != comp[graph[i][j]]) {
					fail[comp[i]] = true;
					break;
				}
			}
		}

		vector<int> ans;
		
		for (int i = 1; i <= N; i++) {
			if (!fail[comp[i]]) {
				ans.push_back(i);
			}
		}

		for (int i = 0; i < (int) ans.size(); i++) {
			if (i) cout << " ";
			cout << ans[i];
		}
		
		cout << "\n";
	}
    return 0;
}
