#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) {
    a = (a > b) ? b : a;
}
template<typename T> void chmax(T& a, T b) {
    a = (a < b) ? b : a;
}
int in() {
    int x;
    scanf("%d", &x);
    return x;
}

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1010;
int N, M;

int root;
int l;
vector<int> g[MAXN];
vector<int> q[MAXN];
int deg[MAXN];
int vis[MAXN];
vector<int> tin, tout;
int timer;
vector < vector<int> > up;

void dfs(int v, int p = 0) {
    //printf("%d\n", v);
    tin[v] = ++timer;
    vis[v] = 1;
    up[v][0] = p;
    //cerr << v << " " << p << "\n";
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!vis[to] && to != p)
            dfs (to, v);
    }
    tout[v] = ++timer;
}

void dfsRev(int x, int avoid) {
    vis[x] = 1;

    int i;

    for (i = 0; i < (int) q[x].size(); i++) {
        int u = q[x][i];

        if (!vis[u] && u != avoid) {
            dfsRev(u, avoid);
        }
    }
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (upper (a, b)) return a;
    if (upper (b, a)) return b;
    for (int i = l; i>=0; --i) {
        if (! upper (up[a][i], b)) {
            a = up[a][i];
        }
    }
    return up[a][0];
}

int main(void) {
    freopen("i.in", "r", stdin);
    int i;
    int j;
    int k;
    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        tin.resize(N), tout.resize(N),  up.resize (N);
        l = 1;
        while ((1<<l) <= N) ++l;
        for (i = 0; i < N; ++i) up[i].resize (l+1);
        timer = 0;

        for (i = 0; i <= N; i++) {
            g[i].clear();
            q[i].clear();
            deg[i] = vis[i] = 0;
        }

        for (i = 0; i < M; i++) {
            int x = in();
            x--;
            int y = in();
            y--;
            g[x].push_back(y);
            deg[x] += 1;
            //deg[y] += 1;
        }

        dfs(0);
        //cerr << "s";
        int ans = 0;
        for (i = 1; i < N; i++) {
            for (j = i + 1; j < N; j++) {
                int p = lca(i, j);
                if (p == 0) {
                    ans += 1;
                } else {
                    if (p != i && p != j || (deg[i] == 1 || deg[j] == 1)) continue;
                    ans += 1;
                }
                //printf("asd");
            }
        }
        printf("%d\n", ans + N - 1);
    }
    return 0;
}
