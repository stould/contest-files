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

int N, M, P, Q, U;
vector<pair<int, int> > graph[1010];

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
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
};

int main(void) {
    scanf("%d%d", &N, &M);
    vector<edge> ve;
    REP(i, M) {
        scanf("%d%d%d", &P, &Q, &U);
        ve.push_back(edge(P, Q, U));
        ve.push_back(edge(Q, P, U));
    }
    sort(ve.begin(), ve.end());
    UnionFind u(N);
    int ans = 0;
    REP(i, 2*M) {
        if(!u.find(ve[i].from, ve[i].to)) {
            u.unite(ve[i].from, ve[i].to);
            ans += ve[i].cost;
        }
    }
    printf("%d", ans);
    return 0;
}
