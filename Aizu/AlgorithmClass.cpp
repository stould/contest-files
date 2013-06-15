#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, i, j, k, v, ok, maze[200][200], memo[200][200];

const int INF = 10000001;

int main(void) {
    freopen("i.in", "r", stdin);
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;

        ok = 0;
        memset(memo, 0, sizeof(memo));

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &maze[i][j]);
            }
        }

        for(i = 0; i < n; i++) {
            int m = INF;
            for(j = 0; j < n; j++) {
                if(maze[i][j] <= m) {
                    m = maze[i][j];
                }
            }
            for(j = 0; j < n; j++) {
                if(maze[i][j] == m) {
                    memo[i][j] += 1;
                }
            }
        }

        for(j = 0; j < n; j++) {
            int m = -1;
            for(i = 0; i < n; i++) {
                if(maze[i][j] >= m) {
                    m = maze[i][j];
                }
            }
            for(i = 0; i < n; i++) {
                if(maze[i][j] == m) {
                    memo[i][j] += 1;
                }
            }
        }

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(memo[i][j] == 2) {
                    v = maze[i][j];
                    ok = 1;
                }
            }
        }

        if(ok) {
            printf("%d\n", v);
        } else {
            printf("%d\n", 0);
        }
    }
    return 0;
}
