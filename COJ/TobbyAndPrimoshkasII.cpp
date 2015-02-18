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

const int MAXN = 500005;

int N, Q, cnt;
int ini[MAXN], fin[MAXN];
vector<int> graph[MAXN];

int tree[4 * MAXN];
int lazy[4 * MAXN];

void propagate(int node, int l, int r) {
	if (lazy[node]) {
		//	printf("propa %d %d %d => %d\n", node, l, r, tree[node]);
		tree[node] = (r - l + 1) - tree[node];

		if (l != r) {		
			lazy[2 * node] ^= 1;
			lazy[2 * node + 1] ^= 1;
		}
	} 
	lazy[node] = 0;
}

int query(int node, int l, int r, int bound_l, int bound_r) {
	propagate(node, l, r);
	//	printf("query %d %d %d = %d %d\n", node, l, r, bound_l, bound_r);
	if (l > r || l > bound_r || r < bound_l) {
		return 0;
	} else if (l >= bound_l && r <= bound_r) {
		return tree[node];
	} else {
		int m = (l + r) / 2;

		int q1 = query(2 * node, l, m, bound_l, bound_r);
		int q2 = query(2 * node + 1, m + 1, r, bound_l, bound_r);
		
		return q1 + q2;
	}
}

void update(int node, int l, int r, int bound_l, int bound_r) {
	//	printf("update %d %d %d = %d %d\n", node, l, r, bound_l, bound_r);
	propagate(node, l, r);
	if (l > r || l > bound_r || r < bound_l) {
		return;
	} else if (l >= bound_l && r <= bound_r) {
		lazy[node] ^= 1;
		propagate(node, l, r);
	} else {
		int m = (l + r) / 2;

		update(2 * node, l, m, bound_l, bound_r);
		update(2 * node + 1, m + 1, r, bound_l, bound_r);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

void dfs(int node, int p) {
	ini[node] = cnt++;
	for (int i = 0; i < (int) graph[node].size(); i++) {
		int next = graph[node][i];
		if (next != p) {			
			dfs(next, node);
		}
	}
	fin[node] = cnt - 1;
}

int main(void) {
	for ( ; scanf("%d%d", &N, &Q) == 2; ) {
		for (int i = 0; i < MAXN; i++) {
			graph[i].clear();
			ini[i] = fin[i] = -1;
		}
		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));

		int A, B;
		for (int i = 0; i < N - 1; i++) {
			scanf("%d%d", &A, &B);
			graph[A].push_back(B);
		}
		cnt = 0;
		dfs(0, -1);
		for (int i = 0; i < Q; i++) {
			scanf("%d%d", &A, &B);
			///				printf("q = %d %d %d\n", A, ini[B], fin[B]);
			if (A == 0) {
				update(1, 0, N -1, ini[B], fin[B]);
			} else {
				printf("%d\n", query(1, 0, N - 1, ini[B], fin[B]));
			}
		}
	}
    return 0;
}
