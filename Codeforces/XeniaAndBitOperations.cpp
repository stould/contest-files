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

const int MAXN = (1 << 17) + 5;

int N, M, L;
int P[MAXN];
int tree[4 * MAXN];

void build(int node, int l, int r, int level) {
	if (l > r) {
		return;
	} else if (l == r) {
		tree[node] = P[l];
	} else {
		int m = (l + r) / 2;

		build(2 * node, l, m, level + 1);
		build(2 * node + 1, m + 1, r, level + 1);	
		
		if (level % 2 != L % 2) {
			tree[node] = tree[2 * node] | tree[2 * node + 1];
		} else {
			tree[node] = tree[2 * node] ^ tree[2 * node + 1];
		}
	}
}

void update(int node, int l, int r, int pos, int value, int level) {
	if (l == r) {
		tree[node] = value;
	} else {
		int m = (l + r) / 2;
		
		if (pos <= m) {
			update(2 * node, l, m, pos, value, level + 1);
		} else {
			update(2 * node + 1, m + 1, r, pos, value, level + 1);
		}

		if (level % 2 != L % 2) {
			tree[node] = tree[2 * node] | tree[2 * node + 1];
		} else {
			tree[node] = tree[2 * node] ^ tree[2 * node + 1];
		}
	}
}

int main(void) {
	cin >> N >> M;

	N = (1 << N);

	L = (int) log2(N);

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	build(1, 0, N - 1, 0);

	for (int i = 0; i < M; i++) {
		int p, b;
		cin >> p >> b;

		update(1, 0, N - 1, p - 1, b, 0);

		printf("%d\n", tree[1]);
	}
	
    return 0;
}
