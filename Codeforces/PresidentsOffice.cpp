#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, m;
char ch;

int dx[4] = {1,  0, -1, 0};
int dy[4] = {0, -1,  0, 1};

string maze[110];
bool vis[110][110];
set<char> s;

void dfs(int i, int j) {
    vis[i][j] = true;
    s.insert(maze[i][j]);
    for(int x = 0; x < 4; x++) {
        int ti = i + dx[x];
        int tj = j + dy[x];

        if(ti >= 0 && ti < n && tj >= 0 && tj < m && !vis[ti][tj] && maze[ti][tj] != '.' && maze[i][j] == ch) {
            dfs(ti, tj);
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    cin >> n >> m >> ch;
    for(int i = 0; i < n; i++) {
        cin >> maze[i];
    }
    memset(vis, false, sizeof(vis));
    s.clear();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == ch) {
                dfs(i, j);
                goto end;
            }
        }
    }
    end:;
    cout << s.size() - 1 << endl;
}
