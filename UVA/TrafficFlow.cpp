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

int N, M;
int T;

struct Edge {
	int f, t, c;

	Edge(){}

	Edge(int f, int t, int c): f(f), t(t), c(c) {

	}

	bool operator<(const Edge& e) const {
		return c > e.c;
	}
};

Edge ed[10005];

struct UnionFind {
	int* id;
	int* sz;

	int N;

	UnionFind(int n): N(n) {
		id = new int[N];
		sz = new int[N];

		int i;

		for (i = 0; i < N; i++) {
			id[i] = i;
			sz[i] = 1;
		}
	}

	int root(int p) {
		for ( ; p != id[p]; ) {
			id[p] = id[id[p]];
			p = id[p];
		}

		return p;
	}

	bool find(int p, int q) {
		return root(p) == root(q);
	}

	bool unite(int p, int q) {
		int a = root(p);
		int b = root(q);

		if (a == b) {
			return false;
		} else {
			if (sz[a] > sz[b]) swap(a, b);

			sz[a] += sz[b];

			id[a] = b;
		}
	}
};

int main(void) {
	T = in();

	int A, B, C;
	int i;
	int x;

	for (x = 1; x <= T; x++) {
		N = in();
		M = in();

		int cnt = N;
		int ans = 10001010;

		for (i = 0; i < M; i++) {
			A = in();
			B = in();
			C = in();

			ed[i] = Edge(A, B, C);
		}

		UnionFind uf(N);

		sort(ed, ed + M);

		for (i = 0; i < M && cnt; i++) {
			if (!uf.find(ed[i].f, ed[i].t)) {
				chmin(ans, ed[i].c);
				
				if (i == 0) {
					cnt -= 2;
				} else {
					cnt -= 1;
				}
				uf.unite(ed[i].f, ed[i].t);
			}
		}

		printf("Case #%d: %d\n", x, ans);
	}
    return 0;
}