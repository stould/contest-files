#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

long long a, b, c, n, m;

struct UnionFind {
    int N, *id, *sz;

    UnionFind(int N) {
        this->N = N;
        id = new int[N];
        sz = new int[N];
        for(int i = 0; i < N; i++) {
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
    long long a, b, c;
    edge(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
    bool operator<(const edge& e) const { return c < e.c; }
};

int main(void) {
    cin >> n >> m;
    UnionFind uf(n+1);
    vector<edge> s;
    vector<edge>::iterator it;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c; s.push_back(edge(a, b, c));
    }
    sort(s.begin(), s.end());
    long long ans = 0;
    for(it = s.begin(); it != s.end(); it++) {
        if(!uf.find(it->a, it->b)) {
            ans += it->c;
            uf.unite(it->a, it->b);
        }
    }
    cout << ans << "\n";
    return 0;
}
