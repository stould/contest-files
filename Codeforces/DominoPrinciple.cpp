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

struct data {
	int id, pos, h;

	data(){}

	data(int id, int pos, int h): id(id), pos(pos), h(h) {}

	bool operator<(const data& d) const {
		return pos < d.pos;
	}
};

data dt[MAXN];
int R[MAXN];

int tree[4 * MAXN];

void build(int node, int l, int r) {
	if (l == r) {
		tree[node] = R[l];
	} else {
		int m = (l + r) / 2;

		build(2 * node, l, m);
		build(2 * node + 1, m + 1, r);

		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	}
}

int query(int node, int l, int r, int bound_l, int bound_r) {
	if (bound_l > bound_r) {
		return INT_MIN;
	} else if (l >= bound_l && r <= bound_r) {
		return tree[node];
	} else {
		int m = (l + r) / 2;

		int a = query(2 * node, l, m, bound_l, min(m, bound_r));
		int b = query(2 * node + 1, m + 1, r, max(m + 1, bound_l), bound_r);
		
		return max(a, b);
	} 
}

int funcR(int id) {
	int l = id + 1, h = N - 1, m;

	int start = dt[id].pos + dt[id].h - 1;

	int best = INT_MIN;

	for ( ; l <= h; ) {
		int m = (l + h) / 2;

		if (start >= dt[m].pos) {
			l = m + 1;
			chmax(best, m);
		} else {
			h = m - 1;
		}
	}

	return best == INT_MIN ? id : best;
}

void update(int node, int l, int r, int pos, int value) {
	if (l > r) {
		return;
	} else if (l == r) {
		tree[node] = value;
	} else {
		int m = (l + r) / 2;

		if (pos <= m) {
			update(2 * node, l, m, pos, value);
		} else {
			update(2 * node + 1, m + 1, r, pos, value);
		}
		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> dt[i].pos >> dt[i].h;

		dt[i].id = i;
	}

	sort(dt, dt + N);

	for (int i = 0; i < N; i++) {
		R[i] = funcR(i);
	}

	for (int i = 0; i < N; i++) {
		for ( ; R[R[i]] > R[i]; ) {
			R[i] = R[R[i]];
		}
	}

	build(1, 0, N - 1);

	vector<int> pre(N), ans(N);

	for (int i = N - 1; i >= 0; i--) {
		int curr = query(1, 0, N - 1, i, R[i]);

		pre[i] = curr;

		update(1, 0, N - 1, i, curr);
	}

	for (int i = 0; i < N; i++) {
		ans[dt[i].id] = pre[i] - i + 1;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

    return 0;
}
