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

int N;

vector<pair<int, int> > graph[MAXN];
vector<int> ans;

int vis[MAXN];
int parent[MAXN];
int mark[MAXN];

vector<int> leaf;

void dfs(int x, int p, int kind) {
	vis[x] = 1;

	int i;

	for (i = 0; i < (int) graph[x].size(); i++) {
		int u = graph[x][i].first;
		int t = graph[x][i].second;

		if (!vis[u]) {
			mark[u] = mark[x];

			if (t == 2) mark[u] += 1;

			if (kind == 2) {
				dfs(u, x, 2);
			} else {
				dfs(u, x, kind);
			}
		}
	}
}

int main(void) {
	N = in();

	int A, B, C;

	int i;

	for (i = 0; i < N - 1; i++) {
		A = in();
		B = in();
		C = in();

		graph[A].push_back(make_pair(B, C));
		graph[B].push_back(make_pair(A, C));
	}

	for (i = 1; i <= N; i++) if (graph[i].size() == 1) leaf.push_back(i);

	for (i = 0; i <= N; i++) {
		vis[i] = mark[i] = 0;		
	}

	dfs(1, -1, 0);

	for (i = 0; i < (int) leaf.size(); i++) {
		if (mark[leaf[i]] > 0) {
			ans.push_back(leaf[i]);
		}
	}

	printf("%d\n", (int) ans.size());

	for (i = 0; i < (int) ans.size(); i++) {
		printf("%d ", ans[i]);
	}

    return 0;
}