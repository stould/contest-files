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

int T, N, M, K;
int P[220];

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
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;

		UnionFind uf(N + 1);
		vector<edge> ve;

		for (int i = 0; i < K; i++) {
			cin >> P[i];
			ve.push_back(edge(0, P[i], 0));
		}

		int A, B, C;

		for (int i = 0; i < M; i++) {
			cin >> A >> B >> C;
			ve.push_back(edge(A, B, C));
		}
		
		sort(ve.begin(), ve.end());
		
		int ans = 0;

		for (int i = 0; i < (int) ve.size(); i++) {
			if (!uf.find(ve[i].f, ve[i].t)) {
				uf.unite(ve[i].f, ve[i].t);
				ans += ve[i].c;
			}
		}
		
		cout << "Case #" << t << ": " << ans << "\n";
	}
	
    return 0;
}
