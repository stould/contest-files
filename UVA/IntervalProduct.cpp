#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <sstream>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

#define DEBUG(x...) printf(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define _foreach(it, b, e) for(__typeof__(b) it = (b); it != (e); ++it)
#define foreach(x...) _foreach(x)

typedef long long int Int;

const int inf = 0x3f3f3f3f;
const Int hugeinf = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;

const int MAXN = 100007;

int N, K;
int x[MAXN];

int tree[4 * MAXN];

int func(int a) {
	if (a < 0) return -1;
	else if (a > 0) return 1;
	else return 0;
}

void build(int node, int l, int r) {
	if (l > r) return;

	if (l == r) {
		tree[node] = func(x[l]);
	} else {
		int m = (l + r) >> 1;

		build(2 * node, l, m);
		build(2 * node + 1, m + 1, r);

		tree[node] = tree[2 * node] * tree[2 * node + 1];
	}
}

void update(int node, int l, int r, int pos, int value) {
	if (l > r) return;

	if (l == r) {
		tree[node] = func(value);
	} else {
		int m = (l + r) >> 1;

		if (pos <= m) {
			update(2 * node, l, m, pos, value);
		} else {
			update(2 * node + 1, m + 1, r, pos, value);
		}

		tree[node] = tree[2 * node] * tree[2 * node + 1];
	}
}

int query(int node, int l, int r, int bound_l, int bound_r) {
	if(bound_l > bound_r) return 1;

	if (bound_l <= l && bound_r >= r) {
		return tree[node];
	} else {
		int m = (l + r) >> 1;

		int a = query(2 * node, l, m, bound_l, min(m, bound_r));
		int b = query(2 * node + 1, m + 1, r, max(m + 1, bound_l), bound_r);

		return a * b;
	}
}

int main(void) {
	int i, a, b;
	char kind;
	for ( ; scanf("%d%d", &N, &K) == 2; ) {
		for (i = 0; i < N; i++) {
			scanf("%d", &x[i]);
		}

		build(1, 0, N - 1);

		for ( ; K--; ) {
			cin >> kind >> a >> b;

			if (kind == 'C') {
				update(1, 0, N - 1, a - 1, b);
			} else {
				int curr = query(1, 0, N - 1, a - 1, b - 1);

				if (curr < 0) {
					printf("-");
				} else if (curr == 0) {
					printf("0");
				} else {
					printf("+");
				}
			}
		}
		printf("\n");
	}

	return 0;
}
