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

const int MAXN = 1000008;

int N, K;
int tree[4 * MAXN], lazy[4 * MAXN];
vector<int> ans;

inline int inp() {
	int noRead = 0;
	char p = getchar_unlocked();
	for( ; p < 33; ) {
		p = getchar_unlocked();
	}
	while (p > 32) {
		noRead = (noRead << 3) + (noRead << 1) + (p - '0');
		p = getchar_unlocked();
	}
	return noRead;
} 

void propagate(int node, int l, int r) {
	if (lazy[node]) {
		tree[node] = tree[node] + (r - l + 1) * lazy[node];
		
		if (l != r) {
			lazy[2 * node + 0] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
	}
	lazy[node] = 0;
}

void update(int node, int l, int r, int bound_l, int bound_r) {
	if (l > r || l > bound_r || r < bound_l) {
		return;		
	} else if (l >= bound_l && r <= bound_r) {
		lazy[node] += 1;
		propagate(node, l, r);
	} else {
		int m = (l + r) / 2;

		update(2 * node, l, m, bound_l, bound_r);
		update(2 * node + 1, m + 1, r, bound_l, bound_r);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

void query(int node, int l, int r) {
	propagate(node, l, r);
	if (l == r) {
		ans.push_back(tree[node]);
	} else {
		int m = (l + r) / 2;

		query(2 * node, l, m);
		query(2 * node + 1, m + 1, r);
	}
}

int main(void) {
	N = inp();
	K = inp();

	for (int i = 0; i < K; i++) {
		int A = inp(), B = inp();
		tree[A] += 1;
		tree[B + 1] -= 1;
	}

	for (int i = 1; i <= N; i++) {
		ans.push_back(tree[i]);
		tree[i + 1] += tree[i];
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans[N / 2]);

    return 0;
}
