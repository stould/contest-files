#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

template<typename T>
T max(T a, T b) { return a > b ? a : b; }

int maze[101][101];
int dist[101][101];

int i, j, k, fr, tr, T, N, R, s, d;

int main(void) {
    cin >> T;

    while(T > 0) {
        cin >> N >> R;

        memset(maze, 63, sizeof(maze));
        memset(dist, 63, sizeof(dist));

        for(i = 0; i < R; i++) {
            cin >> fr >> tr;
            maze[fr][tr] = 1;
            maze[tr][fr] = 1;
        }
        cin >> s >> d;

        for(i = 0; i < 101; i++) {
            for(j = 0; j < 101; j++) {
                for(k = 0; k < 101; k++) {
                    dist
                }
            }
        }

        T--;
    }
    return 0;
}
