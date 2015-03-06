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

int N, M, K;
Int base[MAXN];
int L[MAXN], R[MAXN];
Int D[MAXN];

struct SegmentTree {
	Int tree[4 * MAXN];
	Int lazy[4 * MAXN];

	SegmentTree() {
		for (int i = 0; i < 4 * MAXN; i++) {
			tree[i] = 0;
			lazy[i] = 0;
		}
	}

	void build(int node, int l, int r) {
		if (l == r) {
			tree[node] = base[l];
		} else {
			int m = (l + r) / 2;

			build(2 * node + 0, l, m);
			build(2 * node + 1, m + 1, r);
			
			tree[node] = tree[2 * node] + tree[2 * node + 1];
		}
	}

	void down(int node, int l, int r) {
		if (lazy[node] != 0) {
			tree[node] += (r - l + 1) * lazy[node];

			if (l != r) {			
				lazy[2 * node + 0] += lazy[node];
				lazy[2 * node + 1] += lazy[node];
			}
		}
		lazy[node] = 0;
	}

	Int query(int node, int l, int r, int bl, int br) {
		down(node, l, r);
		
		if (l > r || l > br || r < bl) {
			return 0;
		} else if (l >= bl && r <= br) {
			return tree[node];
		} else {
			int m = (l + r) / 2;
			
			Int a = query(2 * node + 0, l, m, bl, br);
			Int b = query(2 * node + 1, m + 1, r, bl, br);
			
			return a + b;
		}
	}

	void update(int node, int l, int r, int bl, int br, Int val) {
		down(node, l, r);
		
		if (l > r || l > br || r < bl) {
			return;
		} else if (l >= bl && r <= br) {
			lazy[node] += val;
			down(node, l, r);
		} else {
			int m = (l + r) / 2;
			
			update(2 * node + 0, l, m, bl, br, val);
			update(2 * node + 1, m + 1, r, bl, br, val);

			tree[node] = tree[2 * node] + tree[2 * node + 1];
		}
	}
};

SegmentTree root;
SegmentTree helper;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> base[i];
	}

	root.build(1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		cin >> L[i] >> R[i] >> D[i];
		L[i] -= 1;
		R[i] -= 1;
	}
	

	for (int i = 0; i < K; i++) {
		int A, B;
		cin >> A >> B;

		A -= 1;
		B -= 1;
		
		helper.update(1, 0, M - 1, A, B, 1LL);
	}
	
	for (int i = 0; i < M; i++) {
		root.update(1, 0, N - 1, L[i], R[i], D[i] * (Int) helper.query(1, 0, M - 1, i, i));
	}
	
	for (int i = 0; i < N; i++) {
		cout << root.query(1, 0, N - 1, i, i) << " ";
	}
	cout << "\n";
    return 0;
}
