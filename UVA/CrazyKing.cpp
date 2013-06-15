#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

char maze[101][101];
bool memo[101][101];
int dist[101][101];

int tests, N, M, xa, ya, i, j, k;

const int INF = 11001001;

int kingdx[8] = {1,  1,  0, -1, -1, -1, 0, 1};
int kingdy[8] = {0, -1, -1, -1,  0,  1, 1, 1};

int knightdx[8] = {1, 2,  2,  1, -1, -2, -2, -1};
int knightdy[8] = {2, 1, -1, -2, -2, -1,  1,  2};

queue<pair<int, int> > q;

int main() {
    freopen("CrazyKingTest.in", "r", stdin);
    scanf("%d", &tests);

    while(tests > 0) {
        scanf("%d%d", &M, &N);
        for(i = 0; i < M; i++) {
            for(j = 0; j <= N; j++) {
                scanf("%c", &maze[i][j]);
                memo[i][j] = false;
                dist[i][j] = INF;
                if(maze[i][j] == 'Z') {
                    memo[i][j] = true;
                    for(k = 0; k < 8; k++) {
                        xa = i + knightdx[i];
                        ya = j + knightdy[i];
                        if(xa >= 0 && ya >= 0 && xa <= M && ya < N) {
                            memo[xa][ya] == true;
                        }
                    }
                }
            }
        }
        int actual = INF;
        for(i = 0; i < M; i++) {
            for(j = 0; j <= N; j++) {
                if(maze[i][j] == 'A') {
                    printf("%d %d\n", i, j);
                    q.push(make_pair(i, j));
                    dist[i][j] = 0;
                    while(!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        for(k = 0; k < 8; k++) {
                            xa = p.first + kingdx[i];
                            ya = p.second + kingdy[i];

                            if(xa >= 0 && ya >= 0 && xa <= M && ya < N && !memo[xa][ya] && maze[xa][ya] != 'Z') {
                                memo[xa][ya] = true;
                                q.push(make_pair(xa, ya));
                                dist[xa][ya] = dist[p.first][p.second] + 1;
                                if(maze[xa][ya] == 'B') actual = dist[xa][ya];
                            }
                        }
                    }
                }
            }
        }
        if(actual == INF) {
            printf("King Peter, you can't go now!\n");
        } else {
            printf("Minimal possible length of a trip is %d\n", actual);
        }
        tests--;
    }
    return 0;
}
