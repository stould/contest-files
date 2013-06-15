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
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

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

int i, j, n, u, v, ans = 0;
vector<int> graph[1010];


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

int main(void) {
    scanf("%d", &n);
    UnionFind uf(n+1);
    vector<pair<int, int> > close;
    REP(i, n - 1) {
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
        if(uf.find(u, v)) {
            close.push_back(make_pair(u, v));
            ans += 1;
        } else {
            uf.unite(u, v);
        }
    }
    printf("%d\n", ans);
    REP(i, close.size()) {
        FOR(j, 1, n+1) {
            if(!uf.find(close[i].first, j)) {
                printf("%d %d %d %d\n", close[i].first, close[i].second, close[i].first, j);
                uf.unite(close[i].first, j);
                break;
            }
    }
        }
    return 0;
}

