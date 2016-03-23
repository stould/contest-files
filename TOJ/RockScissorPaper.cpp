#include <stdio.h>
#include <string.h>

#define MAXN 107

int T, R, C, D;

char base[MAXN][MAXN];
char next[MAXN][MAXN];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0,-1, 1};

int ok(int x, int y) {
    return x >= 0 && y >= 0 && x < R && y < C;
}

int func(char x, char y) {
    if (x == 'R' && y == 'S') return 1;
    if (x == 'P' && y == 'R') return 1;
    if (x == 'S' && y == 'P') return 1;
    return 0;
}

int main(void) {
  //  freopen("i.in", "r", stdin);
    scanf("%d", &T);

    int i, j, k, x, test;

    for (test = 1; test <= T; test++) {
        scanf("%d%d%d", &R, &C, &D);

        for (i = 0; i < R; i++) {
            scanf("%s", base[i]);
        }

        for (x = 0; x < D; x++) {
            for (i = 0; i < R; i++) {
                for (j = 0; j < C; j++) {
                    next[i][j] = base[i][j];
                }
            }
            for (i = 0; i < R; i++) {
                for (j = 0; j < C; j++) {
                    for (k = 0; k < 4; k++) {
                        int next_i = i + dx[k];
                        int next_j = j + dy[k];

                        if (ok(next_i, next_j) && next[next_i][next_j] == base[next_i][next_j]) {
                            if (func(base[i][j], next[next_i][next_j])) {
                                next[next_i][next_j] = base[i][j];
                            }
                        }
                    }
                }
            }
            for (i = 0; i < R; i++) {
                for (j = 0; j < C; j++) {
                    base[i][j] = next[i][j];
                }
            }
        }

        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                printf("%c", base[i][j]);
            }
            puts("");
        }
        if (test != T) puts("");
    }
    return 0;
}
