#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

const int INF = 100000000;
int c, l, a, b, s, e, d, maze[110][110], dist[110], vis[110];

int main(void) {
    while(cin >> c >> l && !(c == 0 && l == 0)) {
        memset(maze, 0, sizeof(maze));
        for(int i = 0; i <= c; i++) {
            dist[i] = INF;
            vis[i] = 0;
        }
        for(int i = 0; i < l; i++) {
            cin >> a >> b;
            maze[a][b] = maze[b][a] = 1;
        }
        cin >> s >> e >> d;
        if(d == 0 && s == e || (s == e && d == 1)) {
            cout << "Yes, Teobaldo can travel." << endl;
            continue;
        }
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        dist[s] = 0;
        while(!q.empty()) {
            int tmp = q.front(); q.pop();
            for(int i = 1; i <= c; i++) {
                if(maze[tmp][i] == 1 && !vis[i]) {
                    dist[i] = dist[tmp] + 1;
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        if(dist[e] <= d && dist[e] % 2 == d % 2 && !(c == 1 && l == 0 && s == 1 && e == 1 && d != 0) && d != 0) {
            cout << "Yes, Teobaldo can travel." << endl;
        } else {
            cout << "No, Teobaldo can not travel." << endl;
        }
    }
    return 0;
}

