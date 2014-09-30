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

#define SET 1
#define RESET 2
#define FLIP 3

#define LEFT(x) (x << 1) 
#define RIGHT(x) (x << 1) + 1

const int MAXN = 1024005;

int T, M, P, A, B, Q, Tp, N;
string S;
char buff[60];
int tree[4 * MAXN], lazy[4 * MAXN];

int do_flip(int p) {
	if (p == SET) {
		return RESET;
	} else if (p == RESET) {
		return SET;
	} else if (p == FLIP) {
		return 0;
	}
	return FLIP;
}

void apply(int node, int type) {
	if (type == SET) {
		tree[node] = 1;
	} else if (type == RESET) {
		tree[node] = 0;
	} else if (type == FLIP) {
		tree[node] = tree[node] == 1 ? 0 : 1;
	}
}

void propagate(int node, int l, int r) {
	if (lazy[node] == 0) return;
	if (lazy[node] == SET) {
		tree[node] = r - l + 1;
	} else if (lazy[node] == RESET) {
		tree[node] = 0;
	} else if (lazy[node] == FLIP) {
		tree[node] = (r - l + 1) - tree[node];
	}

	if (l != r) {
		if (lazy[node] == FLIP) {
			lazy[LEFT(node)] = do_flip(lazy[LEFT(node)]);
			lazy[RIGHT(node)] = do_flip(lazy[RIGHT(node)]);
		} else {
			lazy[LEFT(node)] = lazy[RIGHT(node)] = lazy[node];
		}
	}

	lazy[node] = 0;
}

void build(int node, int l, int r) {
	if (l > r) {
		return;
	} else {
		lazy[node] = 0;	
		if (l == r) {
			tree[node] = (S[l] - '0');
		} else {
			int m = (l + r) / 2;
			build(LEFT(node), l, m);
			build(RIGHT(node), m + 1, r);
			
			tree[node] = tree[LEFT(node)] + tree[RIGHT(node)];
		}
	}
}

void update(int node, int l, int r, int bound_l, int bound_r, int type) {
	propagate(node, l, r);
	if (l > bound_r || r < bound_l) {
		return;
	} else {
		if (l == r) {
			apply(node, type);
			if (type == RESET) {
				lazy[node] = 0;
			}
		} else if (l >= bound_l && r <= bound_r) {
			if (type == SET) {
				tree[node] = r - l + 1;
				lazy[LEFT(node)] = lazy[RIGHT(node)] = SET;
			} else if (type == RESET) {
				tree[node] = 0;
				lazy[LEFT(node)] = lazy[RIGHT(node)] = RESET;
			} else if (type == FLIP) {
				tree[node] = (r - l + 1) - tree[node];

				lazy[LEFT(node)] = do_flip(lazy[LEFT(node)]);
				lazy[RIGHT(node)] = do_flip(lazy[RIGHT(node)]);
			}

		} else {
			int m = (l + r) / 2;
			
			update(LEFT(node), l, m, bound_l, bound_r, type);
			update(RIGHT(node), m + 1, r, bound_l, bound_r, type);
			
			tree[node] = tree[LEFT(node)] + tree[RIGHT(node)];
		}
	}
}

int query(int node, int l, int r, int bound_l, int bound_r) {
	if (l > bound_r || r < bound_l) {
		return 0;
	} else {		
		propagate(node, l, r);
		if (l >= bound_l && r <= bound_r) {
			return tree[node];
		} else {
			int m = (l + r) / 2;
			
			int sl = query(LEFT(node), l, m, bound_l, bound_r);
			int sr = query(RIGHT(node), m + 1, r, bound_l, bound_r);

			return sl + sr;
		}
	}
}

int main(void) {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &M);
		S = "";

		//		memset(lazy, 0, sizeof(lazy));
		
		for ( ; M--; ) {
			scanf("%d%s", &P, buff);
			string tmp(buff);

			for (int i = 0; i < P; i++) {
				S += tmp;
			}
		}

		N = (int) S.size();
		build(1, 0, N - 1);
		scanf("%d", &Q);
		int q = 1;

		printf("Case %d:\n", t);

		for ( ; Q--; ) {
			scanf(" %c%d%d", &Tp, &A, &B);

			if (Tp == 'F') {
				update(1, 0, N - 1, A, B, SET);
			} else if (Tp == 'E') {
				update(1, 0, N - 1, A, B, RESET);				
			} else if (Tp == 'I') {
				update(1, 0, N - 1, A, B, FLIP);
			} else {
				printf("Q%d: %d\n", q++, query(1, 0, N - 1, A, B));
			}
		}
	}
    return 0;
}
