#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

const int INF = 111101;

int N, M, S, L;

struct

int main() {
    cin >> N >> M >> S;

    S -= 1;

    int maze[N][N];

    memset(maze, INF, sizeof(maze));

    for(int i = 0; i < M; i++) {
        int f, t, w;
        scanf("%d %d %d", &f, &t, &w);
        maze[f - 1][t - 1] = w;
        maze[t - 1][f - 1] = w;
    }

    cin >> L;

    vector<int> dist(N, INF);

    dist[S] = 0;

    queue<int> q;

    q.push(S);

    int valids = 0;

    while(!q.empty()) {
        int start = q.front();
        q.pop();

        bool occur = false;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(i == start && dist[start] + maze[i][j] < dist[j]) {
                    dist[j] = dist[start] + maze[i][j];
                    q.push(j);
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(dist[i] == L) valids++;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(maze[i][j] != INF) {
                if(maze[i][j] < L && L - dist[i] < maze[i][j] && maze[i][j] - (L - dist[i] + dist[j] > l)) {
                    valids++;
                }
                if()
            }
        }
    }
    cout << valids << endl;
    return 0;
}
