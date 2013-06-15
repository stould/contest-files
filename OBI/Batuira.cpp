#include <queue>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int maze[101][101];
int dist[101];
bool vist[101];

const int INF = 10010001;

#define REP(i, n) for(i = 0; i < n; i++)

int main() {
    int N, from, to, ds, i, j, t = 1;

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
            scanf("%d %d %d", &from, &to, &ds);

            if(from == 0 && to == 0 && ds == 0) break;

            from--;
            to--;

            maze[from][to] = maze[to][from] = ds;
        }

        dist[0] = 0;

        while(1) {
            int fim = -1;

            for(int i = 0; i < N; i++) {
                if(!vist[i] && (fim == -1 || dist[i] < dist[fim])) {
                    fim = i;
                }
            }

            if(fim == -1) break;

            vist[fim] = true;

            for(int i = 0; i < N; i++) {
                int nova = dist[fim] + maze[fim][i];

                if(nova < dist[i]) {
                    dist[i] = nova;
                }
            }
        }
        printf("Teste %d\n%d\n\n", t, dist[N - 1]);
        N--;
        t++;
        scanf("%d", &N);
    }
}
