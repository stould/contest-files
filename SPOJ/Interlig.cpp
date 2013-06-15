#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int n, vis[1010], path[1010][1010];
double x[1010], y[1010];

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
    int a, b;
    double len;

    edge(){}
    edge(int _a, int _b, double _len) {
        a = _a;
        b = _b;
        len = _len;
    }
    bool operator<(const edge &e) const {
        return len < e.len;
    }
};


int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n && n) {
        vector<edge> vs;
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                vs.push_back(edge(i, j, (double)hypot(x[i] - x[j], y[i] - y[j])));
            }
        }
        UnionFind uf(n+1);
        sort(vs.begin(), vs.end());
        double ans = 0.0;
        for(int i = 0; i < vs.size(); i++) {
            if(!uf.find(vs[i].a, vs[i].b)) {
                uf.unite(vs[i].a, vs[i].b);
                if(vs[i].len > ans) {
                    ans = vs[i].len;
                }
            }
        }
        printf("%.4f\n", ans);
    }
    return 0;
}
