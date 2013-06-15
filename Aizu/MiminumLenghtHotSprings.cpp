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
#include <string.h>
#include <limits.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}


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

struct Edge {
    int a, b, cost;
    Edge(){}
    Edge(int _a, int _b, int _cost): a(_a), b(_b), cost(_cost){}
    bool operator<(const Edge& e) const {
        return cost < e.cost;
    }
};

typedef long long ll;
typedef long double ld;

int i, j, value, s, d;

int main(void) {
    while(scanf("%d%d", &s, &d) ==  2 && !(s == 0 && d == 0)) {
        vector<Edge> ve;
        REP(i, s) REP(j, d) {
            scanf("%d", &value);
            if(value != 0) {
                ve.push_back(Edge(i, s + j, value));
            }
        }
        REP(i, d - 1) {
            FOR(j, i + 1, d) {
                scanf("%d", &value);
                if(value != 0) {
                    ve.push_back(Edge(s + i, s + j, value));
                }
            }
        }
        REP(i, s) FOR(j, i+1, s) {
            ve.push_back(Edge(i, j, 0));
        }
        sort(ve.begin(), ve.end());
        UnionFind uf((s + d) * 3);
        int cost = 0;
        REP(i, ve.size()) {
            if(!uf.find(ve[i].a, ve[i].b)) {
                cost += ve[i].cost;
                uf.unite(ve[i].a, ve[i].b);
            }
        }
        printf("%d\n", cost);
    }
    return 0;
}

