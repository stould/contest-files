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
int T, N;

int pos[MAXN], radius[MAXN];
int L[MAXN], R[MAXN];

int funcL(int id) {
	int l = 0, h = id - 1, m;
	int best = INT_MAX;

	for ( ; l <= h; ) {
		m = (l + h) / 2;

		if (pos[id] - radius[id] <= pos[m]) {
			h = m - 1;
			chmin(best, m);
		} else {
			l = m + 1;
		}
	}
	return best == INT_MAX ? id : best;
}

int funcR(int id) {
	int l = id + 1, h = N - 1, m;
	int best = INT_MIN;

	for ( ; l <= h; ) {
		m = (l + h) / 2;

		if (pos[id] + radius[id] >= pos[m]) {
			l = m + 1;
			chmax(best, m);
		} else {
			h = m - 1;
		}
	}
	return best == INT_MIN ? id : best;
}

// first = leftmost explosion, second = rightmost explosion
pair<int, int> tree[4 * MAXN];

void build(int node, int l, int r) {
	if (l == r) {
		tree[node].first = L[l];
		tree[node].second = R[l];
	} else {
		int m = (l + r) / 2;

		build(2 * node, l, m);
		build(2 * node + 1, m + 1, r);

		pair<int, int>  a = tree[2 * node];
		pair<int, int>  b = tree[2 * node + 1];

		tree[node].first = min(a.first, b.first);
		tree[node].second = max(a.second, b.second);
	}
}

pair<int, int> query(int node, int l, int r, int bound_l, int bound_r) {
	if (bound_l > bound_r) {
		return make_pair(INT_MAX, INT_MIN);
	} else if (l >= bound_l && r <= bound_r) {
		return tree[node];
	} else {
		int m = (l + r) / 2;

		pair<int, int> a = query(2 * node, l, m, bound_l, min(m, bound_r));
		pair<int, int> b = query(2 * node + 1, m + 1, r, max(m + 1, bound_l), bound_r);

		int ll = min(a.first, b.first);
		int rr = max(a.second, b.second);

		return make_pair(ll, rr);
	}
}

void updateL(int node, int l, int r, int pos, int value) {
	if (l > r) {
		return;
	} else if (l == r) {
		chmin(tree[node].first, value);
	} else {
		int m = (l + r) / 2;

		if (pos <= m) {
			updateL(2 * node, l, m, pos, value);
		} else {
			updateL(2 * node + 1, m + 1, r, pos, value);
		}

		tree[node].first = min(tree[2 * node].first, tree[2 * node + 1].first);
	}
}

void updateR(int node, int l, int r, int pos, int value) {
	if (l > r) {
		return;
	} else if (l == r) {
		chmax(tree[node].second, value);
	} else {
		int m = (l + r) / 2;

		if (pos <= m) {
			updateL(2 * node, l, m, pos, value);
		} else {
			updateL(2 * node + 1, m + 1, r, pos, value);
		}

		tree[node].second = max(tree[2 * node].second, tree[2 * node + 1].second);
	}
}


int main(void) {
	T = in();

	for ( ; T--; ) {
		N = in();

		for (int i = 0; i < N; i++) {
			pos[i] = in();
			radius[i] = in();

			L[i] = funcL(i);
			for ( ; L[L[i]] < L[i]; ) {
				L[i] = L[L[i]];
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			R[i] = funcR(i);
			for ( ; R[R[i]] > R[i]; ) {
				R[i] = R[R[i]];
			}
   		}

		build(1, 0, N - 1);
		
		for (int i = 0; i < N; i++) {
			pair<int, int> curr = query(1, 0, N - 1, L[i], i);

			updateL(1, 0, N - 1, i, curr.first);
		}

		for (int i = N - 1; i >= 0; i--) {
			pair<int, int> curr = query(1, 0, N - 1, i, R[i]);

			updateR(1, 0, N - 1, i, curr.second);
		}

		for (int i = 0; i < N; i++) {
			pair<int, int> a = query(1, 0, N - 1, i, R[i]);
			pair<int, int> b = query(1, 0, N - 1, L[i], i);

			int l_b = min(a.first, min(b.first, min(a.second, b.second)));
			int r_b = max(a.first, max(b.first, max(a.second, b.second)));

			printf("%d ", r_b - l_b + 1);
		}
		printf("\n");
	}
    return 0;
}
