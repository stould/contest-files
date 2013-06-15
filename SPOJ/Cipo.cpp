#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

struct edge {
    int from, to, cost;

    edge() {}
    edge(int from, int to, int cost): from(from), to(to), cost(cost) {};

    bool operator<(const edge& e) const {
        return cost < e.cost;
    }
};

edge l[2000010];
edge m[2000010];
edge h[2000010];
bool vis[2000010];

int i, j, n, p, t = 1;

int main(void) {
    while(scanf("%d %d", &n, &p) == 2) {
        int ll = 0, lm = 0, lh = 0;
        for(i = 1; i <= n; i++) vis[i] = false;
        for(i = 0; i < p; i++) {
            int tma, tmb, tmc;
            scanf("%d %d %d", &tma, &tmb, &tmc);
            if(tmc == 1235) {
                l[ll].from = tma;
                l[ll].to = tmb;
                l[ll].cost = tmc;
                ll += 1;
            } else if(tmc == 8977) {
                m[lm].from = tma;
                m[lm].to = tmb;
                m[lm].cost = tmc;
                lm += 1;
            } else if(tmc == 10923) {
                h[lh].from = tma;
                h[lh].to = tmb;
                h[lh].cost = tmc;
                lh += 1;
            }
        }
        int all = 0;
        for(i = 0; i < ll; i++) {
            if(vis[l[i].from] && vis[l[i].to]) continue;
            vis[l[i].from] = vis[l[i].to] = true;
            all += l[i].cost;
        }
        for(i = 0; i < lm; i++) {
            if(vis[m[i].from] && vis[m[i].to]) continue;
            vis[m[i].from] = vis[m[i].to] = true;
            all += m[i].cost;
        }
        for(i = 0; i < lh; i++) {
            if(vis[h[i].from] && vis[h[i].to]) continue;
            vis[h[i].from] = vis[h[i].to] = true;
            all += h[i].cost;
        }
        printf("Instancia %d\n%d\n\n", (t++), all);
    }
    return 0;
}
