#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

typedef long long ll;
typedef long double ld;

const int INF = 1000000000;
int n, m, f, t, c, ans;
vector<pair<int, int> > g[600];

int main(void) {
    freopen("i.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &f, &t, &c); f -= 1; t -= 1;
        g[f].push_back(make_pair(t, c));
        g[t].push_back(make_pair(f, c));
    }
    vector<int> min_e(n+1, INF), sel_e(n+1, -1);
    min_e[0] = 0;
    set<pair<int,int> > q;
    q.insert(make_pair(0, 0));
    for (int i = 0; i < n; i++) {
        int v = q.begin()->second;
        q.erase (q.begin());
        if (sel_e[v] != -1) {
            cout << v + 1 << " " << sel_e[v] + 1<< " " << min_e[v] << endl;
            ans += min_e[v];
        }
        for(int j = 0; j < g[v].size(); j++) {
            int to = g[v][j].first, cost = g[v][j].second;
            if (cost < min_e[to]) {
                q.erase (make_pair (min_e[to], to));
                min_e[to] = cost;
                sel_e[to] = v;
                q.insert (make_pair (min_e[to], to));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}



