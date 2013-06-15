#include <queue>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int maze[101][101];
int dist[101];
bool vist[101];

const int INF = 10010001;
int N, from, to, ds, i, j, t = 1;

#define REP(i, n) for(i = 0; i < n; i++)

int dijkstra() {
    dist[0] = 0;
    while(1) {
        int actual = -1;

        for(int i = 0; i < N; i++) {
            if(!vist[i] && (actual == -1 || dist[actual] > dist[i])) actual = i;
        }

        if(actual == -1) break;

        vist[actual] = true;

        for(int i = 0; i < N; i++) {
            int tmp = dist[actual] + maze[actual][i];
            if(tmp < dist[i]) {
                dist[i] = tmp;
            }
        }
    }
    return dist[N - 1];
}

int main() {
    scanf("%d", &N);

    while(N != 0) {
        REP(i, N) {
            dist[i] = INF;
            vist[i] = false;
            REP(j, N) {
                maze[i][j] = INF;
            }
        }
        while(1) {
            scanf("%d%d%d", &from, &to, &ds);
            if(from == 0 && to == 0 && ds == 0) break;
            from -= 1;
            to -= 1;
            maze[from][to] = maze[to][from] = ds;
        }
        printf("Teste %d\n%d\n\n", t, dijkstra());
        N--;
        t++;
        scanf("%d", &N);
    }
}
