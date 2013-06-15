#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int a, b, r, c, maze[20][20], vis[20][20];
char name[100];

int main(void) {
    #ifdef LOCAL
    freopen("i.in", "r", stdin);
    #endif
    while(~scanf("%s", name)) {
        scanf("%d%d", &r, &c);
        memset(maze, 0, sizeof(maze)); memset(vis, 0, sizeof(vis));
        for(int i = 0; i < 4; i++) {
            scanf("%d%d", &a, &b);
            maze[a][b] = 1;
        }
        scanf("%d%d", &a, &b);
        maze[a][b] = 2;
        printf("%s\n", name);

    }
    return 0;
}


