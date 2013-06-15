#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

#define REP(i, n) for(i = 0; i < n; i++)

typedef long long ll;

using namespace std;

int a, b, n, m, ans = 0, adj[110][110], vis[110], mt[110];

bool dfs(int x) {
    if(vis[x]) return false;
    vis[x] = true;
    for(int i = 1; i <= n; i++) if(adj[x][i] == 1) {
        if(mt[i] == -1 || dfs(mt[i])) {
            mt[i] = x;
            return true;
        }
    }
    return false;
}

int main(void) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = 1;
        }
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        adj[a][b] = adj[b][a] = 0;
    }
    memset(mt, -1, sizeof(mt));
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(i);
    }
    printf("%d\n", ans);
    return 0;
}
