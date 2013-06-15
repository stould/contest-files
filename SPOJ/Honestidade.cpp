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
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
    }
};

int n, m, k, u, v, c, test = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    while(~scanf("%d%d%d", &n, &m, &k)) {
        UnionFind uf(n + 1);
        vector<pair<int, int> > mem[k + 1];
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &c);
            mem[c].push_back(make_pair(u, v));
        }
        set<int> used;
        for(int i = 1; i < k; i++) {
            for(int j = 0; j < mem[i].size(); j++) {
                if(!uf.find(mem[i][j].first, mem[i][j].second))) {
                    uf.unite(mem[i][j].first, mem[i][j].second);
                    used.insert(i);
                }
            }
        }
        printf("Instancia %d\n");
        if(used.size() == k - 1) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
        printf("\n");
    }
    return 0;
}

