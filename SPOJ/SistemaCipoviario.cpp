#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

struct edge {
    int from, to, cost;

    edge() {}
    edge(int from, int to, int cost): from(from), to(to), cost(cost) {};

    bool operator<(const edge& e) const {
        return cost < e.cost;
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

edge l[2000010];
edge m[2000010];
edge h[2000010];

int i, j, n, p, t = 1;

int main(void) {
    while(scanf("%d%d", &n, &p) == 2) {
        int ll = 0, lm = 0, lh = 0;
        UnionFind u(n + 1);
        for(i = 0; i < p; i++) {
            int tma, tmb, tmc;
            scanf("%d%d%d", &tma, &tmb, &tmc);
            if(tmc == 1235) {
                l[ll].from = tma;
                l[ll].to = tmb;
                l[ll].cost = tmc;
                ll += 1;
            } else if(tmc == 8977) {
                m[lm].from = tma;
                m[lm].to = tmb;
                m[lm].cost = tmc;
                lm += 1;
            } else {
                h[lh].from = tma;
                h[lh].to = tmb;
                h[lh].cost = tmc;
                lh += 1;
            }
        }
        int all = 0;
        for(i = 0; i < ll; i++) {
            int ii = u.root(l[i].from);
            int jj = u.root(l[i].to);
            if(ii == jj) continue;
            u.unite(l[i].from, l[i].to);
            all += l[i].cost;
        }
        for(i = 0; i < lm; i++) {
            int ii = u.root(m[i].from);
            int jj = u.root(m[i].to);
            if(ii == jj) continue;
            u.unite(m[i].from, m[i].to);
            all += m[i].cost;
        }
        for(i = 0; i < lh; i++) {
            int ii = u.root(h[i].from);
            int jj = u.root(h[i].to);
            if(ii == jj) continue;
            u.unite(h[i].from, h[i].to);
            all += h[i].cost;
        }
        printf("Instancia %d\n%d\n\n", (t++), all);
    }
    return 0;
}
