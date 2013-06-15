#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

const int INF = 1000001;


int edge[10001][10001];
int dist[10001];
bool visited[10001];
int prev[10001];

int N, M;

int dijkstra(int start, int end) {
    dist[start] = 0;

    while(1) {
        int close = -1;

        for(int i = 0; i < N; i++) {
            if(!visited[i] && (close == -1 || dist[i] < dist[close])) {
                close = i;
            }
        }
        if(close == -1) {
            break;
        }
        visited[close] = true;

        for(int i = 0; i < N; i++) {
            int nova = dist[close] + edge[close][i];
            if(nova < dist[i]) {
                dist[i] = nova;
                prev[i] = close;
            }
        }
    }
    return dist[end];
}

int main() {
    int from, to, ds;

    scanf("%d %d", &N, &M);

    memset(edge, INF, sizeof(edge));
    memset(visited, false, sizeof(visited));
    memset(dist, INF, sizeof(dist));
    memset(prev, -1, sizeof(prev));

    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &from, &to, &ds);
        from--;
        to--;
        edge[from][to] = edge[to][from] = ds;
    }

    int total = dijkstra(0, N - 1);

    vector<int> path;
    int p = N - 1;

    for(int p = N - 1; p != -1; p = prev[p]) {
        path.push_back(prev[p]);
    }
    int mx = 0;

    for(int i = 0; i < (int) path.size() - 1; i++) {
        int a = path[i], b = path[i + 1];
        edge[a][b] *= 2;
        edge[b][a] *= 2;
        mx = max(mx, dijkstra(0, N - 1));
        edge[a][b] /= 2;
        edge[b][a] /= 2;
    }

    printf("%d\n", mx - total);
    return 0;
}
