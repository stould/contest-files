#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 100005;

set<int> g[MAXN];
int subSize[MAXN];
int pai[MAXN];
int sz;

int dfs0(int x, int ult) {
    subSize[x] = 1;
    
    for (auto y: g[x]) {
        if (y == ult) continue;
        dfs0(y, x);
        subSize[x] += subSize[y];
    }
    
    return x;
}

int dfs1(int x, int ult) {
    for (auto y: g[x]) {
        if (y == ult) continue;
        if (subSize[y] * 2  >= sz) {
            return dfs1(y, x);
        }
    }
    return x;
}

void centroid(int x, int lastCen) {
    sz = 0;

    dfs0(x, x);
    
    int cent = dfs1(x, x);
    
    if (x == lastCen) {
        pai[cent] = cent;
    } else {
        pai[cent] = lastCen;
    }

    for (auto y : g[cent]) {
        g[y].erase(g[y].find(cent));
        centroid(y, cent);
    }
    g[cent].clear();
}

int main(void) {
    return 0;
}
