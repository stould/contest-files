#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int i, j, N, M, maze[20][20], vis[20][20], dist[20][20];

int dx[4] = {1,  0, -1, 0};
int dy[4] = {0, -1,  0, 1};

int bfs(int x, int y) {
    vis[x][y] = true;
    queue<int> q;
    q.push(x);
    q.push(y);
    int ans = 0;

    while(!q.empty()) {
        int t_x = q.front(); q.pop();
        int t_y = q.front(); q.pop();

        if(maze[t_x][t_y] == 0) {
            ans = dist[t_x][t_y]; break;
        }

        for(int k = 0; k < 4; k++) {
            int tmp_x = t_x + dx[k];
            int tmp_y = t_y + dy[k];

            if(tmp_x >= 0 && tmp_y >= 0 && tmp_x < N && tmp_y < M && !vis[tmp_x][tmp_y] && (maze[tmp_x][tmp_y] == 0 || maze[tmp_x][tmp_y] == 1)) {
                vis[tmp_x][tmp_y] = true;
                dist[tmp_x][tmp_y] = dist[t_x][t_y] + 1;

                q.push(tmp_x);
                q.push(tmp_y);
            }
        }
    }
    return ans;
}


int main(void) {
    memset(maze, 0, sizeof(maze));
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));

    cin >> N >> M;

    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }

    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            if(maze[i][j] == 3) {
                cout << bfs(i, j) << endl; goto end;
            }
        }
    }
    end:;
    return 0;
}
