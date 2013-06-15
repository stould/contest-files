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
int n, p, e, u, v, t, max = 0, pedra[30], len[300], min_e[300], used[300], sel_e[300];
vector<pair<int, int> > graph[300];

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
    freopen("i.in", "r", stdin);
    scanf("%d%d%d", &n, &p, &e);
    for(int i = 0; i < p; i++) {
        scanf("%d", &pedra[i]);
    }
    ways(100);
    memset(graph, 63, sizeof(graph));
    bool valid = true;
    for(int i = 0; i < e; i++) {
        scanf("%d%d%d", &u, &v, &t);
        graph[u].push_back(make_pair(v, len[t]));
        graph[v].push_back(make_pair(u, len[t]));
    }
    for(int i = 0; i <= n; i++) {
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
        for(int j = 0; j < graph[v].size(); j++) {
            if(graph[v][j].second < min_e[graph[v][j].first] && graph[v][j].second != 0) {
                min_e[graph[v][j].first] = graph[v][j].second;
                sel_e[graph[v][j].first] = v;
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

