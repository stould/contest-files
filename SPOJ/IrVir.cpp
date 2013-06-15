#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 2020

using namespace std;

int i, n, m, p, v, w, ans;
vector<int> used, component, order, g[MAXV], gr[MAXV];

void dfs1(int x) {
    used[x] = 1;
    for(int b = 0; b < g[x].size(); b++) {
        if(!used[g[x][b]]) dfs1(g[x][b]);
    }
    order.push_back(x);
}

void dfs2(int x) {
    used[x] = 1;
    for(int b = 0; b < gr[x].size(); b++) {
        if(!used[gr[x][b]]) dfs2(gr[x][b]);
    }
}

int main(void) {
    while(scanf("%d%d", &n, &m) && n > 0 && m > 0) {
        ans = 0;
        for(i = 1; i <= n; i++) {
            g[i].clear(); gr[i].clear();
        }
        order.clear();
        component.clear();
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &v, &w, &p);
            if(p == 1) {
                g[v].push_back(w); gr[w].push_back(v);
            } else if(p == 2) {
                g[v].push_back(w); g[w].push_back(v);
                gr[v].push_back(w); gr[w].push_back(v);
            }
        }
        used.assign(n+1, false);
        for(i = 1; i <= n; i++) if(!used[i]) dfs1(i);
        used.assign(n+1, false);
        reverse(order.begin(), order.end());
        bool strong = true;
        for(i = 0; i < order.size(); i++) {
            int v = order[i];
            if(!used[v]) {
                dfs2(v);
                ans++;
            }
        }
        if(ans == 1) {
            puts("1");
        } else {
            puts("0");
        }
    }
    return 0;
}
