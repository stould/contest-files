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

vector<pair<int, pair<int, int> > > p;
int n, m, f, t, c;

int main(void) {
    scanf("%d%d", &n, &m);
    UnionFind u(n + 1);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &f, &t, &c);
        p.push_back(make_pair(c, make_pair(f, t)));
    }
    int sum = 0;
    sort(p.begin(), p.end());
    for(int i = 0; i < p.size(); i++) {
        bool found = u.find(p[i].second.first, p[i].second.second);
        if(!found) {
            sum += p[i].first;
            u.unite(p[i].second.first, p[i].second.second);
        }
    }
    printf("%d\n", sum);
    return 0;
}

