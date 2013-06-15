#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int n, m, maze[10000][10000], dist[100000], prev[100000];
bool mem[100000];

const int INF = 10000000;

void dijsktra() {
    dist[0] = 0;
    while(1) {
        int start = -1;
        for(int i = 0; i < n; i++) {
            if(dist[i] < dist[start] && !mem[i]) {
                start = i;
            }
        }
        if(start == -1) break;

        for(int i = 0; i < n; i++) {
            int spent = maze[i][start] + dist[i];
            if(dist[i] > spent) {
                dist[start] = spent;
                prev[start] = i;
            }
        }
    }
}

int main(void) {
    cin >> n >> m;

    memset(dist, 63, sizeof(dist));
    memset(prev, -1, sizeof(prev));
    memset(maze, 63, sizeof(maze));
    memset(mem, 0, sizeof(mem));

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        maze[a][b] = maze[b][a] = c;
    }
    dijsktra();
    cout << dist[n - 1] << endl;
    return 0;
}
