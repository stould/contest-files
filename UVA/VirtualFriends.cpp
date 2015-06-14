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
int id = 1;
map<string, int> sd;

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

int get_id(string s) {
	if (sd[s] == 0) {
		sd[s] = id++;
	}
	return sd[s];
}

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		
		string A, B;
		
		UnionFind uf(MAXN);
		
		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			
			int ia = uf.root(get_id(A));
			int ib = uf.root(get_id(B));
			
			uf.unite(ia, ib);
			
			
			cout << uf.sz[uf.root(ia)] << "\n";
		}
	}
	return 0;
}
