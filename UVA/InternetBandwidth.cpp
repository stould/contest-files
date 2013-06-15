#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stdio.h>

#define MAXN 110
#define INF 1000000000;

using namespace std;

vector<int> graph[MAXN];
int i, j, n, s, t, u, v, c, cost, test = 1, capacity[MAXN][MAXN];

int max_flow(int source, int sink) {
    int residual[MAXN][MAXN]; memset(residual, 0, sizeof(residual));
    while(1) {
        int prev[MAXN]; memset(prev, -1, sizeof(prev));
        int actual[MAXN]; memset(actual, 0, sizeof(actual));
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
            for(int i = 1; i <= n; i++) {
                sum += residual[source][i];
            }
            return sum;
        }
    }
}

int main(void) {
    while(scanf("%d", &n) && n != 0) {
        for(i = 0; i < MAXN; i++) {
            graph[i].clear();
            for(j = 0; j < MAXN; j++) {
                capacity[i][j] = capacity[j][i] = 0;
            }
        }
        scanf("%d%d%d", &s, &t, &c);
        for(i = 0; i < c; i++) {
            scanf("%d%d%d", &u, &v, &cost);
            graph[u].push_back(v);
            graph[v].push_back(u);
            capacity[u][v] += cost;
            capacity[v][u] += cost;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", test++, max_flow(s, t));
    }
    return 0;
}
