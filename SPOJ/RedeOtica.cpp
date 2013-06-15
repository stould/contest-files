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
        if(cost != e.cost) {
            return cost < e.cost;
        } else {
            if(from != e.from) {
                return from < e.from;
            } else {
                return to < e.to;
            }
        }
    }
};

vector<pair<int, int> > ans;
edge l[2000000];
bool vis[2000000];

int i, j, n, p, t = 1;

int main(void) {
    freopen("i.in", "r", stdin);
    while(scanf("%d%d", &n, &p)) {
        if(!n && !p) break;
        for(i = 1; i <= n; i++) vis[i] = false;
        for(i = 0; i < p; i++) {
            scanf("%d%d%d", &l[i].from, &l[i].to, &l[i].cost);
            if(l[i].to < l[i].from) {
                int tmp = l[i].to;
                l[i].to = l[i].from;
                l[i].from = tmp;
            }
        }
        sort(l, l + p);
        ans.clear();
        for(i = 0; i < p; i++) {
            if(vis[l[i].from] && vis[l[i].to]) continue;
            vis[l[i].from] = vis[l[i].to] = true;
            ans.push_back(make_pair(l[i].from, l[i].to));
        }
        cout << "Teste " << (t++) << endl;
        for(i = 0; i < (int) ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
        cout << endl;
    }
    return 0;
}

