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

const int MAXN = 1000005;

int T, N, Q;
int base[MAXN];

struct SegmentTree {
	int N;
	int tree[MAXN];
	int lazy[MAXN];

	SegmentTree(int N, int base[MAXN]): N(N) {
		build(1, 0, N - 1, base);
	}	

	void build(int node, int l, int r, int base[MAXN]) {
		if (l == r) {
			tree[node] = base[l];
		} else {
			int m = (l + r) / 2;

			build(2 * node, l, m, base);
			build(2 * node + 1, m + 1, r, base);

			tree[node] = min(tree[2 * node], tree[2 * node + 1]);
		}
	}

	int query(int node, int l, int r, int bl, int br) {
		if (l > r || l > br || r < bl) {
			return INT_MAX;
		} else if (l >= bl && r <= br) {
			return tree[node];
		} else {
			int m = (l + r) / 2;
			
			int a = query(2 * node, l, m, bl, br);
			int b = query(2 * node + 1, m + 1, r, bl, br);

			return min(a, b);
		}
	}
};

int main(void) {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		printf("Scenario #%d:\n\n", t);

		scanf("%d%d", &N, &Q);

		for (int i = 0; i < N; i++) {
			scanf("%d", &base[i]);
		}

		int A, B;
		SegmentTree tree(N, base);

		for (int i = 0; i < Q; i++) {
			scanf("%d%d", &A, &B);
			printf("%d\n", tree.query(1, 0, N - 1, A - 1, B - 1));
		}
	}
    return 0;
}
