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
typedef unsigned uint;

const int MAXN = 2020;

int N;
vector<int> graph[MAXN];

int vis[MAXN];
int deg[MAXN];

void dfs(int x, int v = 1) {
    vis[x] = v;

    int i;

    for (i = 0; i < (int) graph[x].size(); i++) {
        int u = graph[x][i];

        if (!vis[u]) {
            dfs(u, v + 1);
        }
    }
}

int main(void) {
    N = in();

    int i;

    memset(vis, 0, sizeof(vis));
    memset(deg, 0, sizeof(deg));

    for (i = 0; i < N; i++) {
        int curr = in();

        if (curr != -1) {
            graph[curr].push_back(i + 1);
            deg[i + 1] += 1;
        }
    }

    int ans = 0;

    for (i = 1; i <= N; i++) {
        if (deg[i] == 0) {
            dfs(i);
            chmax(ans, *max_element(vis + 1, vis + N + 1));
        }
    }

    printf("%d\n", ans);
    return 0;
}