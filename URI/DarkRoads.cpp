#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;


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
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
};

int n, m, f, t, c;

struct edge {
    int from, to, cost;

    edge() {}
    edge(int from, int to, int cost): from(from), to(to), cost(cost) {};
    bool operator<(const edge& e) const {
        return cost < e.cost;
    }
};


int main(void) {
    while(scanf("%d%d", &n, &m) && !(n == 0 && m == 0)) {
        UnionFind u(n + 1);
        int all = 0;
        vector<edge> ve(m);
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &ve[i].from, &ve[i].to, &ve[i].cost); all += ve[i].cost;
        }
        int sum = 0;
        sort(ve.begin(), ve.end());
        for(int i = 0; i < ve.size(); i++) {
            if(!u.find(ve[i].from, ve[i].to)) {
                sum += ve[i].cost;
                u.unite(ve[i].from, ve[i].to);
            }
        }
        printf("%d\n", all - sum);
    }
    return 0;
}

