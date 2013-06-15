#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

using namespace std;

typedef pair<int, int> pii;

char mazeA[60][60], mazeB[60][60];
int i, j, test, n, m, starti1, starti2, startj1, startj2, endi1, endi2, endj1, endj2, visA[60][60], visB[60][60], dist[60][60][60][60];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &test);
    for( ; test-- > 0; ) {
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++) {
            scanf("%s", mazeA[i]);
            for(j = 0; j < n; j++) {
                if(mazeA[i][j] == 'R') {
                    starti1 = i; startj1 = j; mazeA[i][j] = '.';
                }
                if(mazeA[i][j] == 'F') {
                    endi1 = i; endj1 = j;
                }
            }
        }
        for(i = 0; i < m; i++) {
            scanf("%s", mazeB[i]);
            for(j = 0; j < m; j++) {
                if(mazeB[i][j] == 'R') {
                    starti2 = i; startj2 = j; mazeB[i][j] = '.';
                }
                if(mazeB[i][j] == 'F') {
                    endi2 = i; endj2 = j;
                }
            }
        }
        memset(visA, 0, sizeof(visA)); memset(visB, 0, sizeof(visB));
        memset(dist, 0, sizeof(dist));
        queue<pair<pii, pii> > q;
        q.push(make_pair(make_pair(starti1, startj1), make_pair(starti2, startj2)));
        while(!q.empty()) {
            pair<pii, pii> tmp = q.front();
            pair<int, int> p1 = tmp.first;
            pair<int, int> p2 = tmp.second;
            q.pop();

            printf("%d %d - %d %d\n", p1.first, p1.second, p2.first, p2.second);

            visA[p1.first][p1.second] = true;
            visB[p2.first][p2.second] = true;

            for(int i = 0; i < 4; i++) {
                int tp1x = p1.first + dx[i];
                int tp1y = p1.second + dy[i];

                int tp2x = p2.first + dx[i];
                int tp2y = p2.second + dy[i];

                if(tp1x >= 0 && tp2x >= 0 && tp1y >= 0 && tp2y >= 0 && tp1x < n && tp1y < n && tp2x < m && tp2y < m && !visA[tp1x][tp1y] && !visB[tp2x][tp2y]) {
                    dist[tp1x][tp1y][tp2x][tp2y] = min(dist[tp1x][tp1y][tp2x][tp2y], dist[p1.first][p1.second][p2.first][p2.second] + 1);
                    q.push(make_pair(make_pair(tp1x, tp1y), make_pair(tp2x, tp2y)));
                }
            }
        }
        printf("%d\n", dist[endi1][endj1][endi2][endj2]);
    }
    return 0;
}
