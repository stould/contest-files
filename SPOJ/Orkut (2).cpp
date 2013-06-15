#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for((i) = 0; (i) < (n); i++)

using namespace std;

int i, j, n, m, graph[40][40], vis[40], t = 1;
string source, tmp, amigos[40];
vector<int> order;
bool has, round = false;

void dfs(int x) {
    vis[x] = true;
    for(int u = 0; u < n; u++) {
        if(!vis[u] && graph[x][u] == 1) {
            dfs(u);
        }
    }
    order.push_back(x);
}

void dfs2(int x) {
    vis[x] = true;
    for(int u = 0; u < n; u++) {
        if(graph[x][u] == 1) {
            if(!vis[u]) {
                dfs2(u);
                has = true;
            }
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(cin >> n && n != 0) {
        memset(graph, 0, sizeof(graph)); order.clear();
        map<string, int> mp;
        map<int, string> mx;

        REP(i, n) {
            cin >> amigos[i];
            mp[amigos[i]] = i;
            mx[i] = amigos[i];
        }
        REP(i, n) {
            cin >> source >> m;
            REP(j, m) {
                cin >> tmp;
                graph[mp[source]][mp[tmp]] = 1;
            }
        }
        has = false;
        cout << "Teste " << (t++) << "\n";
        memset(vis, 0, sizeof(vis));
        for(i = n - 1; i >= 0; i--) if(!vis[i]) dfs(i);
        memset(vis, 0, sizeof(vis));
        for(i = 0; i < n; i++) if(!vis[order[i]]) dfs2(order[i]);
        if(has) {
            cout << "impossivel";
        } else {
            REP(i, n) {
                cout << mx[order[i]] << " ";
            }
        }
        cout << "\n\n";
    }
    return 0;
}
