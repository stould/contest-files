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

const int MAXN = 105005;
const int MAX_LOG = 25;

int N, M;
int P[MAXN];
vector<int> tree[MAXN];
int lca[MAXN][MAX_LOG];
int par[MAXN];
int root[MAXN];
int level[MAXN];
int L[4 * MAXN * MAX_LOG];
int R[4 * MAXN * MAX_LOG];
int seg_tree[4 * MAXN * MAX_LOG];
int INDEX;

void clean() {
    for (int i = 0; i < MAXN; i++) {
        root[i] = 0;
        level[i] = 0;
        par[i] = 0;
        
        tree[i].clear();    
    }
    
    INDEX = 1;
}

void build(int node, int l, int r) {
    if (l == r) {
        return;
    } else {
        int m = (l + r) / 2;
        L[node] = INDEX++;
        R[node] = INDEX++;

        build(L[node], l, m);
        build(R[node], m + 1, r);
    }
}

int update(int node, int l, int r, int pos, int val) {
    int now = INDEX++;

    L[now] = L[node];
    R[now] = R[node];

    seg_tree[now] = seg_tree[node];
    
    if (l == r) {
        seg_tree[now] += val;
    } else {
        int m = (l + r) / 2;

        if (pos <= m) {
            L[now] = update(L[node], l, m, pos, val); 
        } else {
            R[now] = update(R[node], m + 1, r, pos, val);
        }
        
        seg_tree[now] = seg_tree[L[now]] + seg_tree[R[now]];
    }
    
    return now;
}

int query(int node, int l, int r, int pos) {
    if (l == r) {
        return seg_tree[node];
    } else {
        int m = (l + r) / 2;
        
        if (pos <= m) {
            return query(L[node], l, m, pos);
        } else {
            return query(R[node], m + 1, r, pos);
        }
    }
}

void dfs(int node, int parent) {
    lca[node][0] = parent;

    for (int i = 1; i < MAX_LOG; i++) {
        lca[node][i] = lca[lca[node][i - 1]][i - 1];
    }

    for (auto& it : tree[node]) {
        if (it != parent) {
            root[it] = update(root[node], 0, MAXN - 1, P[it], 1);
            
            level[it] = level[node] + 1;
            par[it] = node;
            
            dfs(it, node);
        }
    }
}

int getLca(int a, int b) {
    if (level[a] < level[b]) {
        swap(a, b);
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (level[a] - (1 << i) >= level[b]) {
            a = lca[a][i];
        }
    }
    if (a == b) {
        return a;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (lca[a][i] != lca[b][i]) {
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    
    return lca[a][0];
}

int main(void) {
    while (scanf("%d%d", &N, &M) == 2) {
        clean();

        for (int i = 1; i <= N; i++) {
            scanf("%d", &P[i]);
        }
        
        for (int i = 0; i < N - 1; i++) {
            int a, b;

            scanf("%d%d", &a, &b);
            
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        
        root[1] = update(root[0], 0, MAXN - 1, P[1], 1);
        dfs(1, 1);
        
        for (int i = 0; i < M; i++) {
            int a, b, c;
            
            scanf("%d%d%d", &a, &b, &c);
            
            int lc = getLca(a, b);
            
            int res = 0;
            
            res += query(root[a], 0, MAXN - 1, c);
            res += query(root[b], 0, MAXN - 1, c);
            res -= 2 * query(root[lc], 0, MAXN - 1, c);

            if (P[lc] == c) {
                res += 1;
            }

            if (res > 0) {
                puts("Find");
            } else {
                puts("NotFind");
            }
        }
        puts("");
    }
    
    return 0;
}
