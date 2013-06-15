#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAXN = 110;
const int INF = 1000000000;
int test, n, m, a, b, c, ans, cont, capacity[MAXN][MAXN];
vector<int> graph[MAXN];

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
//Doesn't work
int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d", &test);
    for( ; test-- > 0; ) {
        scanf("%d%d", &n, &m);
        memset(capacity, 0, sizeof(capacity));
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            capacity[a][b] += c;
            capacity[b][a] += c;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i = 1; i < n; i++) {
            capacity[0][i] = 1;
            capacity[i][n] = 100;
            graph[0].push_back(i);
            graph[i].push_back(n);
        }
        printf("%d\n", max_flow(0, n));
    }
    return 0;
}
