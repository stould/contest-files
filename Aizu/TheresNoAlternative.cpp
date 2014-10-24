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

struct UnionFind {
    int N, *id, *sz;

    UnionFind(int _N) {
        id = new int[_N];
        sz = new int[_N];
        for(int i = 0; i < _N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        N = _N;
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
	int f, t, c;

	edge(){}

	edge(int f, int t, int c): f(f), t(t), c(c) {}

	bool operator<(const edge& other) const {
		return c < other.c;
	}
};

int main(void) {
	cin >> N >> M;
	
	vector<edge> ve;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		ve.push_back(edge(A, B, C));
	}

	sort(ve.begin(), ve.end());

	int best = 0, cnt = 0;
	int m = 0;
	UnionFind b(N + 1);

	for (int i = 0; i < M && cnt < N - 1; i++) {
		if (!b.find(ve[i].f, ve[i].t)) {
			cnt += 1;
			b.unite(ve[i].f, ve[i].t);
			best += ve[i].c;
			m = max(m, ve[i].c);
		}
	}

	int ans = 0;
	Int sum = 0LL;

	for (int i = 0; i < M && ve[i].c <= m; i++) {
		UnionFind uf(N + 1);
		
		int curr = 0;
		int c = 0;

		for (int j = 0; j < M && c < N - 1; j++) {
			if (i == j) continue;
			if (!uf.find(ve[j].f, ve[j].t)) {
				curr += ve[j].c;
				c += 1;
				uf.unite(ve[j].f, ve[j].t);
			}
		}
		
		if (curr != best) {
			ans += 1;
			sum += ve[i].c;
		}
	}

	cout << ans << " " << sum << "\n";

    return 0;
}
