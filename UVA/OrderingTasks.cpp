#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int a, b, i, n, m, maze[110][110], vis[110];
vector<int> order;

void dfs(int x) {
    vis[x] = 1;
    int j;
    for(j = 1; j <= n; j++) {
        if(!vis[j] && maze[x][j]) dfs(j);
    }
    order.push_back(x);
}

int main(void) {
    ios::sync_with_stdio(false);
    while(cin >> n >> m && !(n == 0 && m ==0)) {
        order.clear();
        memset(maze, 0, sizeof(maze)); memset(vis, 0, sizeof(vis));
        for(i = 0; i < m; i++) {
            cin >> a >> b;
            maze[a][b] = 1;
        }
        for(i = 1; i <= n; i++) {
            if(!vis[i]) dfs(i);
        }
        reverse(order.begin(), order.end());
        for(i = 0; i < order.size(); i++) {
            if(i == order.size() - 1) {
                cout << order[i] << "\n";
            } else {
                cout << order[i] << " ";
            }
        }
    }
    return 0;
}
