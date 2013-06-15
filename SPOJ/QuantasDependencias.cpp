#include <iostream>
#include <string.h>

using namespace std;

int n, t, mx, vis[110], graph[110][110];

void dfs(int x) {
    vis[x] = true;
    mx += 1;

    for(int i = 0; i < n; i++) {
        if(!vis[i] && graph[x][i] == true) {
            dfs(i);
        }
    }
}

int main(void) {
    while(cin >> n && n > 0) {
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < n; i++) {
            cin >> t;
            for(int j = 0; j < t; j++) {
                int tmp;
                cin >> tmp;
                graph[i][tmp - 1] = 1;
            }
        }
        int ans = 1, amount = 0;
        for(int i = 0; i < n; i++) {
            mx = 0;
            memset(vis, 0, sizeof(vis));
            dfs(i);
            if(mx > amount) {
                amount = mx;
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
