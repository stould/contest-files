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

const int MAXN = 100003;

int T, N, C;
Int tree[4 * MAXN], lazy[4 * MAXN];

void propagate(int node, int l, int r) {
	if (lazy[node] > 0) {
		tree[node] = tree[node] + (r - l + 1) * lazy[node];

		if (l != r) {
			lazy[2 * node + 0] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int bound_l, int bound_r, int val) {
	propagate(node, l, r);	
	if (l > r || l > bound_r || r < bound_l) {
		return;
	} else if (l >= bound_l && r <= bound_r) {
		lazy[node] += val;
		propagate(node, l, r);
	} else {
		int m = (l + r) / 2;

		update(2 * node, l, m, bound_l, bound_r, val);
		update(2 * node + 1, m + 1, r, bound_l, bound_r, val);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

Int query(int node, int l, int r, int bound_l, int bound_r) {
	propagate(node, l, r);
	if (l > r || l > bound_r || r < bound_l) {
		return 0LL;
	} else if (l >= bound_l && r <= bound_r) {
		return tree[node];
	} else {
		int m = (l + r) / 2;
		return query(2 * node, l, m, bound_l, bound_r) + query(2 * node + 1, m + 1, r, bound_l, bound_r);
	}
}

int main(void) {
	scanf("%d", &T);
	for ( ; T--; ) {
		scanf("%d%d", &N, &C);
		
		for (int i = 0; i < 4 * MAXN; i++) {
			tree[i] = lazy[i] = 0;
		}

		int type, p, q, v;

		for (int i = 0; i < C; i++) {
			scanf("%d%d%d", &type, &p, &q);

			p -= 1;
			q -= 1;

			if (type == 0) {
				scanf("%d", &v);
				update(1, 0, N - 1, p, q, v);
			} else {
				printf("%lld\n", query(1, 0, N - 1, p, q)); 
			}
		}
	}
    return 0;
}
