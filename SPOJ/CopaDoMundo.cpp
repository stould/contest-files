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

int N, F, R;

struct UnionFind {
	int *id, *sz;
	int N;

	UnionFind(int N): N(N) {
		id = new int[N];
		sz = new int[N];

		for (int i = 0; i < N; i++) {
			id[i] = i;
			sz[i] = 1;
		}
	}
	~UnionFind() {
		delete[] id;
        delete[] sz;
    }
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        if(i == j) return;
        if(sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
    }
};

struct edge {
	int a, b, c;
	char t;

	edge() {}
	
	edge(int a, int b, int c, char t): a(a), b(b), c(c), t(t) {}

	bool operator<(const edge& e) const {
		return c < e.c;
	}
};

int main(void) {
	int A, B, C;
	int ans = 0;
	scanf("%d%d%d", &N, &F, &R);
	vector<edge> vf, vr;
	for (int i = 0; i < F; i++) {
		scanf("%d%d%d", &A, &B, &C);
		vf.push_back(edge(A, B, C, 'F'));
	}
	sort(vf.begin(), vf.end());
	for (int i = 0; i < R; i++) {
		scanf("%d%d%d", &A, &B, &C);
		vr.push_back(edge(A, B, C, 'R'));
	}
	sort(vr.begin(), vr.end());
	UnionFind uf(N + 1);
	for (int i = 0; i < F; i++) {
		if (!uf.find(vf[i].a, vf[i].b)) {
			ans += vf[i].c;
			uf.unite(vf[i].a, vf[i].b);
		}
	}
	for (int i = 0; i < R; i++) {
		if (!uf.find(vr[i].a, vr[i].b)) {
			ans += vr[i].c;
			uf.unite(vr[i].a, vr[i].b);
		}
	}
	printf("%d\n", ans);
    return 0;
}
