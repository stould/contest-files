#include <iostream>
#include <queue>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int dx[] = {1, 0,  0, -1};
int dy[] = {0, 1, -1,  0};

int n, m;
string maze[1600];
int vis[1600][1600];

bool bfs(int i, int j) {
    queue<pair<int, int> > q;

    q.push(make_pair(i, j));

    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        vis[p.first][p.second]++;

        for(int k = 0; k < 4; k++) {
            int ti = (p.first + dx[k]);
            int tj = (p.second + dy[k]);

            bool passU = (ti < 0);
            bool passD = (ti >= n);
            bool passL = (tj < 0);
            bool passR = (tj >= m);

            if(passU) ti = n - 1;
            if(passD) ti = 0;
            if(passL) tj = m - 1;
            if(passR) tj = 0;

            if(maze[ti][tj] != '#') {
                if(maze[ti][tj] == 'S') return true;
                if(vis[ti][tj] >= 2) break;
                q.push(make_pair(ti, tj));
            }
        }
    }
    return false;
}

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    memset(vis, 0, sizeof(vis));
    bool ok = false;
    int ix, iy;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 'S') {
                ix = i;
                iy = j;
                break;
            }
        }
    }
    if(bfs(ix, iy)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
