#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int dx[4] = {1,  0, -1, 0};
int dy[4] = {0, -1,  0, 1};

char maze[51][51];
int i, j, f, W, H, g;

void getSafe() {
    for(int x = 0; x < H; x++) {
        for(int y = 0; y < W; y++) {
            int ok = 0;
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < H && ny < W) {
                    if(maze[nx][ny] == 'T') ok = 1;
                }
            }
            if(ok) {
                maze[x][y] = 'U';
            }
        }
    }
}

void dfs(int i, int j) {
    if(i < 0 || i > H || j < 0 || j > W || maze[i][j] != 'U' || vis[i][j]) return;
    vis[i][j] = true;
    if(maze[i][j] == 'G') f++;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main(void) {
    freopen("u.in", "r", stdin);
    while(~scanf("%d%d", &W, &H)) {
        for(i = 0; i < H; i++) {
            for(j = 0; j < W; j++) {
                cin >> maze[i][j];
            }
        }
        for(i = 0; i < H; i++) {
            for(j = 0; j < W; j++) {
                if(maze[i][j] == 'P') {
                    f = 0;
                    getSafe();
                    dfs(i, j);
                }
            }
        }
    }
    return 0;
}
