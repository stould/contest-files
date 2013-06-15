#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

int i, n, a, b, t = 1, maze[110][110], vis[110];

void dfs(int a) {
    printf("%d ", a);
    vis[a] = true;
    for(i = 1; i <= n; i++) {
        if(maze[a][i] == 1 && !vis[i]) {
            dfs(i);
            break;
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d", &n)) {
        if(!n) break;
        memset(maze, 0, sizeof(maze));

        printf("Teste %d\n", t++);

        while(scanf("%d%d", &a, &b)) {
            if(!a && !b) break;
            memset(vis, 0, sizeof(vis));

            maze[a][b] = 1;
            dfs(1);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
