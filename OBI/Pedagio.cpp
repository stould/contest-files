#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

const int INF = 100000000;

int c, e, l, p, i, j, x, y, t = 1, maze[60][60], dist[60], vis[60];

int main(void) {
    while(scanf("%d %d %d %d", &c, &e, &l, &p)) {
        if(!c && !e && !l && !p) break;

        for(i = 1; i <= c; i++) {
            dist[i] = INF;
            vis[i] = 0;
            for(j = 1; j <= c; j++) {
                maze[i][j] = INF;
            }
        }
        for(i = 0; i < e; i++) {
            scanf("%d%d", &x, &y);
            maze[x][y] = maze[y][x] = 1;
        }

        queue<int> q;
        q.push(l);
        dist[l] = 0;

        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            vis[tmp] = true;

            for(i = 1; i <= c; i++) {
                if(!vis[i] && maze[tmp][i] == 1) {
                    vis[i] = true;
                    dist[i] = dist[tmp] + 1;
                    q.push(i);
                }
            }
        }
        cout << "Teste " << t++ << endl;
        int happen = 0;

        for(i = 1; i <= c; i++) {
            if(dist[i] <= p && dist[i] != 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
