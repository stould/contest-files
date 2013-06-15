#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stdio.h>

#define MAXN 110

using namespace std;

vector<int> graph[MAXN];
int capacity[MAXN][MAXN];
const int INF = 1000000000;
int n, m, k, u, v, c[MAXN];

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
            for(int i = 0; i < MAXN; i++) {
                sum += residual[source][i];
            }
            return sum;
        }
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        memset(capacity, 0, sizeof(capacity));
        for(int i = 1; i <= n; i++) graph[i].clear();
        for(int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
            for(int j = 1; j <= n; j++) {
                capacity[i][j] = c[i];
                capacity[j][i] = c[i];
            }
        }
        for(int i = 0; i < k; i++) {
            scanf("%d%d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            graph[0].push_back(i);
        }
        for(int i = 1; i <= m; i++) {
            graph[n+1].push_back(i);
        }
        printf("%d\n", max_flow(0, n+1));
    }
    return 0;
}

