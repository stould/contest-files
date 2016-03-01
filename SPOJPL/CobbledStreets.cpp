#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
 
using namespace std;
 
const int MOD = 1000000007;
int test, p, n, m;
 
struct edge {
    int a, b, c;
 
    edge(){}
    edge(int _a, int _b, int _c): a(_a), b(_b), c(_c){}
 
    bool operator<(const edge& e) const {
        return c < e.c;
    }
};
 
struct UnionFind {
    int n, *id, *size;
 
    UnionFind(int _n) {
        n = _n;
        id = new int[n];
        size = new int[n];
 
        for(int i = 0; i < n; i++) {
            id[i] = i;
            size[i] = 1;
        }
    }
 
    bool find(int p, int q) {
        return root(p) == root(q);
    }
 
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
 
    bool unite(int p, int q) {
        int i = root(p);
        int j = root(q);
 
        if(i == j) return false;
 
        if(size[i] < size[j]) {
            id[i] = j; size[j] += size[i];
        } else {
            id[j] = i; size[i] += size[j];
        }
        return true;
    }
};
 
int main(void) {
    scanf("%d", &test);
    for( ; test-- > 0; ) {
        scanf("%d%d%d", &p, &n, &m);
        vector<edge> ve(m);
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &ve[i].a, &ve[i].b, &ve[i].c);
        }
        sort(ve.begin(), ve.end());
        int ans = 0;
        UnionFind uf(n+1);
        for(int i = 0; i < m; i++) {
            if(!uf.find(ve[i].a, ve[i].b)) {
                uf.unite(ve[i].a, ve[i].b);
                ans += ve[i].c;
            }
        }
        printf("%d\n", ans * p);
    }
    return 0;
}
