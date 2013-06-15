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

typedef long long ll;
typedef long double ld;

int a, b, i, j, n, ans = 0;
vector<int> graph[110];
vector<pair<int, int> > vp;

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
    int a, b;
    edge(){}
    edge(int a, int b): a(a), b(b){}
};

int main(void) {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d", &a, &b); vp.push_back(make_pair(a, b));
    }
    UnionFind uf(n);
    vector<edge> ve;
    REP(i, n) {
        REP(j, n) {
            if(vp[i].first == vp[j].first || vp[i].second == vp[j].second) {
                uf.unite(i, j);
            } else {
                ve.push_back(edge(i, j));
            }
        }
    }
    REP(i, ve.size()) {
        if(!uf.find(ve[i].a, ve[i].b)) {
            ans += 1;
            uf.unite(ve[i].a, ve[i].b);
        }
    }
    printf("%d\n", ans);
    return 0;
}

