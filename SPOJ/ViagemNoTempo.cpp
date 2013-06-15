#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int INF = 1000000000;
int test, n, m, a, b, c, ans, cont, graph[110][110];

int globalMinCut(int n) {
    bool a[n];
    int v[n];
    int w[n];
    for(int i = 0; i < n; i++) v[i] = i;
    int best = INF;
    while(n > 1) {
        int maxj = 1;
        a[v[0]] = true;
        for(int i = 1; i < n; ++i) {
            a[v[i]] = false;
            w[i] = graph[v[0]][v[i]];
            if(w[i] > w[maxj]) {
                maxj = i;
            }
        }
        int prev= 0 ,buf = n;
        while(--buf) {
            a[v[maxj]]=true;
            if(buf == 1) {
                best = min(best, w[maxj]);
                for(int k = 0; k < n; k++) {
                    graph[v[k]][v[prev]]= (graph[v[prev]][v[k]] += graph[v[maxj]][v[k]]);
                }
                v[maxj] = v[--n];
            }
            prev = maxj;
            maxj = -1;
            for(int j = 1; j < n; ++j) {
                if(!a[v[j]]) {
                    w[j] += graph[v[prev]][v[j]];
                    if(maxj < 0 || w[j] > w[maxj]) {
                        maxj=j;
                    }
                }
            }
        }
    }
    return best;
}

int main(void) {
    scanf("%d", &test);
    for( ; test-- > 0; ) {
        scanf("%d%d", &n, &m);
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c); a -= 1; b -= 1;
            graph[a][b] = graph[b][a] = c;
        }
        printf("%d\n", globalMinCut(n));
    }
    return 0;
}
