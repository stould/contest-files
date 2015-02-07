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

const int MAXN = 110;

int T, N, M;
int mat[MAXN][MAXN];

struct edge {
	int a, b;
	int len;

	edge(){}

	edge(int a, int b, int len):
		a(a), b(b), len(len){}

	bool operator<(const edge& other) const {
		return len < other.len;
	}
};

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

int main(void) {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;

		int A, B;
		UnionFind uf(N);
		vector<edge> ve;
		
		memset(mat, 0, sizeof(mat));
				
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			mat[A][B] = mat[B][A] = 1;
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				ve.push_back(edge(i, j, mat[i][j]));
			}
		}

		sort(ve.begin(), ve.end());

		int ans = 0;

		for (int i = 0; i < (int) ve.size(); i++) {
			if (!uf.find(ve[i].a, ve[i].b)) {
				uf.unite(ve[i].a, ve[i].b);
				ans += ve[i].len;
			}
		}

		cout << ans << "\n";
	}
	
    return 0;
}
