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

const int MAXN = 100010;

int N, M;
int tree[4 * MAXN];
bool lazy[4 * MAXN];

void propagate(int node, int l, int r) {
	if (lazy[node]) {
		tree[node] = (r - l + 1) - tree[node];
	}
	if (l != r) {
		lazy[2 * node] ^= lazy[node];
		lazy[2 * node + 1] ^= lazy[node];
	}

	lazy[node] = false;
}

void update(int node, int l, int r, int bound_l, int bound_r, bool debug) {
	propagate(node, l, r);
	if (l > bound_r || r < bound_l) {
		return;
	} else {
		if (l == r) {
			tree[node] ^= 1;
		} else if (l >= bound_l && r <= bound_r) {
			lazy[node] = !lazy[node];
			if (lazy[node]) {
				tree[node] = (r - l + 1) - tree[node];
			}
			lazy[2 * node] = !lazy[2 * node];
			lazy[2 * node + 1] = !lazy[2 * node + 1];
			lazy[node] = false;
		} else {
			int m = (l + r) / 2;

			update(2 * node, l, m, bound_l, bound_r, debug);
			update(2 * node + 1, m + 1, r, bound_l, bound_r, debug);

			tree[node] = tree[2 * node] + tree[2 * node + 1];
		}
	}
}

int query(int node, int l, int r, int bound_l, int bound_r, bool debug) {
	if (l > bound_r || r < bound_l) {
		return 0;
	} else {
		propagate(node, l, r);
		if (l >= bound_l && r <= bound_r) {
			return tree[node];
		} else {
			int m = (l + r) / 2;

			int q1 = query(2 * node, l, m, bound_l, bound_r, debug);
			int q2 = query(2 * node + 1, m + 1, r, bound_l, bound_r, debug);

			return q1 + q2;
		}
	}
}

int main(void) {
	scanf("%d%d", &N, &M);
	int T, A, B;

	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &T, &A, &B);
		
		if (T == 0) {
			update(1, 0, N - 1, A-1, B-1, false);
		} else {
			printf("%d\n", query(1, 0, N - 1, A-1, B-1, false));
		}
	}
    return 0;
}
