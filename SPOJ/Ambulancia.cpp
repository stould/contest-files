#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int a, b, n, matrix[110][110], vis[110], conn[110], test = 1;
vector<int> m;

void dfs(int x) {
    vis[x] = 1;
    m.push_back(x);
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0 && matrix[x][i] == 1) dfs(i);
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(cin >> n && n > 0) {
        memset(matrix, 0, sizeof(matrix));
        memset(conn, 0, sizeof(conn));
        cout << "Teste " << (test++) << "\n";
        while(cin >> a >> b && !(a == 0 && b == 0)) {
            matrix[a][b] = 1;
            memset(vis, 0, sizeof(vis)); m.clear();
            for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);

            sort(m.begin(), m.end());
            for(int i = 0; i < m.size(); i++) {
                if(m.size() - 1 == i) {
                    cout << m[i] << "\n";
                } else {
                    cout << m[i] << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
