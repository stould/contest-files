#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;


int i, j, x, n, maze[110][110];

int main(void) {
    scanf("%d", &n);
    memset(maze, 0, sizeof(maze));
    for(x = 0; x <= 1; x++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                int tmp;
                scanf("%d", &tmp);
                maze[i][j] += tmp;
            }
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}



