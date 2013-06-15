#include <iostream>
#include <stdio.h>
#include <string.h>

int a, b, c, n, m, v[3], maze[200][200], ans = 0;

int main(void) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        maze[a][b] = maze[b][a] = c;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                if(maze[i][j] + maze[i][k] + maze[j][k] >= ans) {
                    ans = maze[i][j] + maze[i][k] + maze[j][k];
                    v[0] = i; v[1] = j; v[2] = k;
                }
            }
        }
    }
    printf("%d %d %d\n", v[0], v[1], v[2]);
    return 0;
}
