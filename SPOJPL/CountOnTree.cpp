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

const int MAXN = 100010;
const int MAX_LOG = 20;

int N, M;
int W[MAXN];
vector<int> G[MAXN];
int lca[MAXN][MAX_LOG];
int height[MAXN];


void dfs(int node, int p) {
    lca[node][0] = p;

    for (int i = 1; i < MAX_LOG; i++) {
        lca[node][i] = lca[lca[node][i - 1]][i - 1];
    }

    for (auto& next : G[node]) {
        height[next] = height[node] + 1;
        
        dfs(next, node);        
    }
}

int getLca(int p, int q) {
    if (height[q] > height[p]) {
        swap(p, q);
    }
    
    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (height[p] - (1 << i) >= height[q]) {
            p = lca[p][i];
        }
    }
    
    if (p == q) return p;

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (lca[p][i] != -1 && lca[p][i] != lca[q][i]) {
            p = lca[p][i];
            q = lca[q][i];
        }
    }

    return lca[p][0];
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;

    int val = 0;
    
    set<int> aux;
    unordered_map<int, int> compress;
    
    for (int i = 0; i < N; i++) {
        cin >> W[i];
        aux.insert(W[i]);
    }
    for (auto& it : aux) {
        compress[it] = val++;
    }

    for (int i = 0; i < N; i++) {
        W[i] = compress[W[i]];
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        G[a].push_back(b);
        G[a].push_back(b);
    }

    dfs(1, 1);
    
    
    return 0;
}
