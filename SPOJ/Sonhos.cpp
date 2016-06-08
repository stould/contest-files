#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
using namespace std;
 
typedef pair<int, int> pii;
 
#define MAXN 55
 
char mazeA[MAXN][MAXN], mazeB[MAXN][MAXN];
int i, j, k, l, test, n, m, starti1, starti2, startj1, startj2, endi1, endi2, endj1, endj2, dist[MAXN][MAXN][MAXN][MAXN], vis[MAXN][MAXN][MAXN][MAXN];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
 
int bfs() {
    dist[starti1][startj1][starti2][startj2] = 0;
    vis[starti1][startj1][starti2][startj2] = 1;
    queue<pair<pii, pii> > q;
    q.push(make_pair(make_pair(starti1, startj1), make_pair(starti2, startj2)));
    while(!q.empty()) {
        pair<pii, pii> tmp = q.front();
        pair<int, int> p1 = tmp.first;
        pair<int, int> p2 = tmp.second;
        q.pop();
 
//        printf("%d %d - %d %d\n", p1.first, p1.second, p2,first, p2.second);
 
        if(dist[p1.first][p1.second][p2.first][p2.second] > 50) continue;
        if(p1.first == endi1 && p1.second == endj1 && p2.first == endi2 && p2.second == endj2) return dist[p1.first][p1.second][p2.first][p2.second];
 
        for(int i = 0; i < 4; i++) {
            int tp1x = p1.first + dx[i];
            int tp1y = p1.second + dy[i];
 
            int tp2x = p2.first + dx[i];
            int tp2y = p2.second + dy[i];
 
            if(!(tp1x >= 0 && tp2x >= 0 && tp1y >= 0 && tp2y >= 0 && tp1x < n && tp1y < m && tp2x < n && tp2y < m)) continue;
 
            if(mazeA[tp1x][tp1y] == '#') {
                tp1x = p1.first;
                tp1y = p1.second;
            }
            if(mazeB[tp2x][tp2y] == '#') {
                tp2x = p2.first;
                tp2y = p2.second;
            }
 
            if(mazeA[tp1x][tp1y] != 'B' && mazeB[tp2x][tp2y] != 'B' && vis[tp1x][tp1y][tp2x][tp2y] == 0) {
                dist[tp1x][tp1y][tp2x][tp2y] = dist[p1.first][p1.second][p2.first][p2.second] + 1;
                vis[tp1x][tp1y][tp2x][tp2y] = 1;
                q.push(make_pair(make_pair(tp1x, tp1y), make_pair(tp2x, tp2y)));
            }
        }
    }
    return -1;
}
 
int main(void) {
    scanf("%d", &test);
    for( ; test-- > 0; ) {
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++) for(j = 0; j < m; j++) {
            mazeA[i][j] = mazeB[i][j] = ' ';
            for(k = 0; k < n; k++) for(l = 0; l < m; l++) {
                dist[i][j][k][l] = vis[i][j][k][l] = 0;
            }
        }
        for(i = 0; i < n; i++) {
            scanf("%s", mazeA[i]);
            for(j = 0; j < m; j++) {
                if(mazeA[i][j] == 'R') {
                    starti1 = i;
                    startj1 = j;
                }
                if(mazeA[i][j] == 'F') {
                    endi1 = i;
                    endj1 = j;
                }
            }
        }
        for(i = 0; i < n; i++) {
            scanf("%s", mazeB[i]);
            for(j = 0; j < m; j++) {
                if(mazeB[i][j] == 'R') {
                    starti2 = i;
                    startj2 = j;
                }
                if(mazeB[i][j] == 'F') {
                    endi2 = i;
                    endj2 = j;
                }
            }
        }
        int check = bfs();
        if(check == -1) {
            printf("impossivel\n");
        } else {
            printf("%d\n", dist[endi1][endj1][endi2][endj2]);
        }
    }
    return 0;
}
 
