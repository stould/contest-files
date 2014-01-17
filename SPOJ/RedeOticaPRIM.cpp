#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;

vector<pair<int, int> > ans;

const int INF = 10000000;
int i, j, n, m, p, u, v, w, g[110][110], used[110], min_e[110], sel_e[110], t = 1;

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n >> m && n > 0 && m > 0) {
        memset(g, 63, sizeof(g));
        for(i = 0; i < m; i++) {
            cin >> u >> v >> w;
            g[u][v] = g[v][u] = w;
        }
        ans.clear();
        for(i = 1; i <= n; i++) {
            used[i] = false;
            min_e[i] = INF;
            sel_e[i] = -1;
        }
        min_e[1] = 0;
        for (i = 1; i <= n; ++i) {
            int v = -1;
            for (j = 1; j <= n; ++j) {
                if (!used[j] && (v == -1 || min_e[j] < min_e[v])) {
                    v = j;
                }
            }
            used[v] = true;
            if (sel_e[v] != -1) {
                ans.push_back(make_pair(min(v, sel_e[v]), max(v, sel_e[v])));
            }
            for (j = 1; j <= n; j++)
                if (g[v][j] < min_e[j]) {
                     min_e[j] = g[v][j];
                    sel_e[j] = v;
                }
        }
        sort(ans.begin(), ans.end());
        cout << "Teste " << (t++) << endl;
        for(i = 0; i < (int) ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
        cout << endl;
    }
    return 0;
}
