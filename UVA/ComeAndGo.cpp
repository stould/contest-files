#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

const int INF = 1000000000;
int a, b, c, N, M, maze[2020][2020];

int main(void) {
    while(~scanf("%d%d", &N, &M) && (N > 0 && M > 0)) {
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= M; j++) {
                maze[i][j] = INF;
            }
        }
        for(int i = 0; i < M; i++) {
            scanf("%d%d%d", &a, &b, &c);
            if(c == 1) {
                maze[a][b] = 1;
            } else {
                maze[a][b] = maze[b][a] = 1;
            }
        }
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                for(int k = 1; k <= N; k++) {
                    maze[i][j] = min(maze[i][j], max(maze[i][k], maze[k][j]));
                }
            }
        }
        bool check = true;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(maze[i][j] == INF) check = false;
            }
        }
        if(!check) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }
    return 0;
}
