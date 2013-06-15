#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 110;
int N, M, K, con;

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
    int a, b, cost;
    edge(){}
    edge(int _a, int _b, int _cost): a(_a), b(_b), cost(_cost) {}

    bool operator<(const edge& e) const {
        return cost < e.cost;
    }
};

vector<edge> ve;
set<int> mem[MAXN];
set<int>::iterator it;

int main(void) {
    scanf("%d%d", &N, &M);

    bool all_zero = true;

    for(int i = 1; i <= N; i++) {
        scanf("%d", &K);
        if(K != 0) all_zero = false;
        REP(j, K) {
            scanf("%d", &con);
            mem[i].insert(con);
        }
    }

    if(all_zero) {
        printf("%d\n", N); return 0;
    }

    int ans = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) if(i != j) {
            bool has_common = false;
            for_each(it, mem[i]) if(mem[j].count(*it)) {
                has_common = true; break;
            }
            if(has_common) {
                ve.push_back(edge(i, j, 0));
            } else {
                ve.push_back(edge(i, j, 1));
            }
        }
    }
    sort(ve.begin(), ve.end());

    UnionFind uf(N+1);

    REP(i, (int) ve.size()) {
        int u = ve[i].a, v = ve[i].b;
        if(!uf.find(u, v)) {
            ans += ve[i].cost;
            uf.unite(u, v);
        }
    }

    printf("%d\n", ans);
    return 0;
}
