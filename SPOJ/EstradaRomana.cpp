#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

const int INF = 1061109567;
int n, p, e, u, v, t, max = 0, pedra[25], len[110], min_e[260], used[260], sel_e[260], graph[260][260];

void ways(int x) {
    memset(len, 0, sizeof(len));
    len[0] = 1;
    for(int i = 0; i < p; i++) {
        for(int j = pedra[i]; j <= x; j++) {
            len[j] += len[j - pedra[i]];
        }
    }
}


int main(void) {
    scanf("%d%d%d", &n, &p, &e);
    for(int i = 0; i < p; i++) {
        scanf("%d", &pedra[i]);
    }
    ways(100);
    memset(graph, 63, sizeof(graph));
    bool valid = true;
    for(int i = 0; i < e; i++) {
        scanf("%d%d%d", &u, &v, &t);
        graph[u][v] = graph[v][u] = len[t];
    }
    for(int i = 1; i <= n; i++) {
        used[i] = false;
        min_e[i] = INF;
        sel_e[i] = -1;
    }
    min_e[1] = 0;
    int ans = 0, in_path = 0;
    for(int i = 1; i <= n; i++) {
        int v = -1;
        for(int j = 1; j <= n; j++) {
            if(!used[j] && (v == -1 || min_e[j] < min_e[v])) v = j;
        }
        if(v == -1) {
            valid = false;
            break;
        }
        used[v] = true;
        if(sel_e[v] != -1) {
            in_path += 1;
            ans += min_e[v];
        }
        for(int j = 1; j <= n; j++) {
            if(graph[v][j] < min_e[j] && graph[v][j] != 0) {
                min_e[j] = graph[v][j];
                sel_e[j] = v;
            }
        }
    }
    if(!valid || in_path != n - 1) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}
