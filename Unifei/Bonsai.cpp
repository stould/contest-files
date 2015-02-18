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

const int MAXN = 3010;

int N, R;
bool vis[MAXN];
int cost[MAXN];
vector<pair<int, int> > tree[MAXN];

int dfs(int node) {
	vis[node] = true;

	int ans = 0;

	for (int i = 0; i < (int) tree[node].size(); i++) {
		int u = tree[node][i].first;

		if (!vis[u]) {
			ans += dfs(u);
		}
	}

	cost[node] = ans;
}

/*
  Min cost max flow to check whether an edge should be removed
 */

int main(void) {
	for ( ; cin >> N >> R && !(N == 0 && R == 0); ) {
		for (int i = 0; i < N - 1; i++) {
			int A, B, C;
			cin >> A >> B >> C;

			tree[A].push_back(make_pair(B, C));
			tree[B].push_back(make_pair(A, C));
		}
		
		dfs(R);

		for (int i = 1; i <= N; i++) {
			if (tree[i].size() == 1) {
				
			}
		}
	}
 
    return 0;
}
