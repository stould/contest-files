#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

int maze[100][100];

int main(void) {
    int n, m;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &maze[i][j]);
            }
        }
        bool end = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                end = true;
                for(int k = 0; k < n; k++) {
                    if(maze[i][k] < maze[i][j] || maze[k][j] > maze[i][j]) end = false;
                }
                if(end) { m = maze[i][j]; goto fim; }
            }
        }
        fim:
            printf("%d\n", m);
            continue;
        printf("0\n");
    }
    return 0;
}
