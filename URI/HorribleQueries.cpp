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

const Int INF = 10010010100LL;
const int MAXN = 262145;

int T;
int P, Q, C, N;
Int V;
Int tree[MAXN];
Int ladd[MAXN];

void update(int node, int l, int r, int bound_l, int bound_r, Int add) {
	if (l > bound_r || r < bound_l) {
		return;
	} else {
		if (l >= bound_l && r <= bound_r) {
			if (l != r) {
				ladd[2 * node] += add;
				ladd[2 * node + 1] += add;
			}			
			tree[node] += (Int) (r - l + 1LL) * add;			
		} else {
			int m = (l + r) / 2;

			update(2 * node, l, m, bound_l, bound_r, add);
			update(2 * node + 1, m + 1, r, bound_l, bound_r, add);

			tree[node] += (Int) (min(r, bound_r) - max(l, bound_l) + 1) * add;
		}
	}
}

Int query(int node, int l, int r, int bound_l, int bound_r) {
	if (l > bound_r || r < bound_l) {
		return 0LL;
	} else {
		if (ladd[node] > 0LL) {
			if (l != r) {
				ladd[2 * node] += ladd[node];
				ladd[2 * node + 1] += ladd[node];
			}
			tree[node] += ladd[node] * (Int) (r - l + 1LL);
			ladd[node] = 0LL;
		}

		if (l >= bound_l && r <= bound_r) {
			return tree[node];
		} else {
			int m = (l + r) / 2;

			Int a = query(2 * node, l, m, bound_l, bound_r);
			Int b = query(2 * node + 1, m + 1, r, bound_l, bound_r);

			return a + b;
		}
	}
}

int main(void) {
	T = in();

	int i;
	int kind;

	for ( ; T--; ) {
		N = in();
		C = in();

		for (i = 0; i < MAXN; i++) {
			tree[i] = ladd[i] = 0LL;
		}

		for ( ; C--; ) {
			kind = in();

			if (kind == 0) {
				P = in();
				Q = in();
				V = in();

				update(1, 1, N, P, Q, V);
			} else {
				P = in();
				Q = in();

				printf("%lld\n", query(1, 1, N, P, Q));
			}
		}
	}

    return 0;
}