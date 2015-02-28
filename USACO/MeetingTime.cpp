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

const int MAXN = 17;

int N, M;
int ans;
vector<pair<int, int> > graph_a[MAXN];
vector<pair<int, int> > graph_b[MAXN];
set<int> seen_a;

void dfs_a(int node, int len) {
	if (node == N) {
		seen_a.insert(len);
	} else {
		for (int i = 0; i < (int) graph_a[node].size(); i++) {
			int u = graph_a[node][i].first;
			int s = graph_a[node][i].second;

			dfs_a(u, len + s);
		}
	}
}

void dfs_b(int node, int len) {
	if (node == N) {
		if (seen_a.count(len)) {			
			ans = min(ans, len);
		}
	} else {
		for (int i = 0; i < (int) graph_b[node].size(); i++) {
			int u = graph_b[node][i].first;
			int s = graph_b[node][i].second;

			dfs_b(u, len + s);
		}
	}
}

int main(void) {
	freopen("meeting.in", "r", stdin);
	freopen("meeting.out", "w", stdout);
	
	scanf("%d%d", &N, &M);

	int A, B, C, D;
	
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d", &A, &B, &C, &D);

		graph_a[A].push_back(make_pair(B, C));
		graph_b[A].push_back(make_pair(B, D));
	}

	ans = INT_MAX;
	
	dfs_a(1, 0);
	dfs_b(1, 0);

	if (ans == INT_MAX) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << ans << "\n";
	}
	
    return 0;
}
