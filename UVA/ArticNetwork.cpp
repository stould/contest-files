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

int T, S, P;

struct UnionFind {
    int n, *id, *size;

    UnionFind(int _n) {
        n = _n;
        id = new int[n];
        size = new int[n];

        fill(size, size + n, 1);
        REP(i, n) id[i] = i;
    }

    int root(int x) {
        while(id[x] != x) {
            id[x] = id[id[x]];
            x = id[x];
        }
        return x;
    }

    bool find(int p, int q) {
        return root(p) == root(q);
    }

    void unite(int p, int q) {
        int i = root(p), j = root(q);

        if(i == j) return;

        if(size[i] < size[j]) {
            id[i] = j; size[j] += size[i];
        } else {
            id[j] = i; size[i] += size[j];
        }

    }
};

struct edge {
    int u, v;
    double cost;

    edge(int _u, int _v, double _cost): u(_u), v(_v), cost(_cost) {
    }

    bool operator<(const edge& e) const {
        return cost < e.cost;
    }
};

int main(void) {
    scanf("%d", &T);
    for( ; T--; ) {
        scanf("%d%d", &S, &P);
        vector<edge> ve;
        vector<pair<int, int> > vp;
        REP(i, P) {
            pair<int, int> p;
            scanf("%d%d", &p.first, &p.second);
            REP(j, vp.size()) {
                ve.push_back(edge(i, j, hypot(vp[j].first - p.first, vp[j].second - p.second)));
            }
            vp.push_back(p);
        }

        sort(ve.begin(), ve.end());

        UnionFind uf(P);

        double ans = 0.0;

        REP(i, ve.size()) {
            if(!uf.find(ve[i].u, ve[i].v)) {
                uf.unite(ve[i].u, ve[i].v);
                P -= 1;
                ans = max(ans, ve[i].cost);
                if(P == S) break;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}

