#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stdio.h>

#define MAXN 7
#define INF 100000000;

using namespace std;

vector<int> graph[MAXN];
int capacity[MAXN][MAXN];

int max_flow(int source, int sink) {
    int residual[MAXN][MAXN]; memset(residual, 0, sizeof(residual));
    int prev[MAXN], actual[MAXN];
    while(1) {
        memset(prev,  -1, sizeof(prev));
        memset(actual, 0, sizeof(actual));

        prev[source] = source;
        actual[source] = INF;

        queue<int> q; q.push(source);

        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if(capacity[u][v] - residual[u][v] > 0 && prev[v] == -1) {
                    prev[v] = u;
                    actual[v] = min(actual[u], capacity[u][v] - residual[u][v]);
                    if(v != sink) {
                        q.push(v);
                    } else {
                        while(prev[v] != v) {
                            u = prev[v];
                            residual[u][v] += actual[sink];
                            residual[v][u] -= actual[sink];
                            v = u;
                        }
                        goto end;
                    }
                }
            }
        }
        end:;
        if(prev[sink] == -1) {
            int sum = 0;
            for(int i = 0; i < MAXN; i++) {
                sum += residual[source][i];
            }
            return sum;
        }
    }
    return -1;
}

int main(void) {
    memset(capacity, 0, sizeof(capacity));
    graph[0].push_back(1); capacity[0][1] = 3;
    graph[1].push_back(2); capacity[1][2] = 3;
    graph[2].push_back(3); capacity[2][3] = 2;
    graph[0].push_back(4); capacity[0][4] = 1;
    graph[4].push_back(5); capacity[4][5] = 4;
    graph[5].push_back(6); capacity[5][6] = 2;
    graph[6].push_back(3); capacity[6][3] = 3;
    graph[0].push_back(1); capacity[0][1] = 3;
    graph[4].push_back(2); capacity[4][2] = 5;
    printf("%d\n", max_flow(0, 3));
    return 0;
}
