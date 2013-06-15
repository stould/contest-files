#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int i, j, k, n, m, maze[1010][1010], dp[1010][1010];

int max(int a, int b) { return a > b ? a : b; }

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d%d", &n, &m) == 2 && !(n == 0 && m == 0)) {
        memset(dp, 0, sizeof(dp)); memset(maze, 0, sizeof(maze));
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                scanf("%d", &maze[i][j]);
            }
        }
        dp[0][0] = maze[0][0];
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < m; j++) {
                if (i == 0 && j != 0) {
                    continue;
                }
                int leftsum = 0;
                for (k = j - 1; k >= 0; k--) {
                    leftsum += maze[i][k];
                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + leftsum + maze[i + 1][k]);
                }
                int rightsum = 0;
                for (k = j + 1; k < m; k++) {
                    rightsum += maze[i][k];
                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + rightsum + maze[i + 1][k]);
                }
            }
        }
        printf("%d\n", dp[n-1][m-1]);
    }
    return 0;
}
