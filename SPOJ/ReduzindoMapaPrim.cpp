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
int n, m, f, t, c, ans, g[600][600];

int main(void) {
    scanf("%d%d", &n, &m);
    memset(g, 63, sizeof(g));
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &f, &t, &c); f -= 1; t -= 1;
        g[f][t] = g[t][f] = c;
    }
    vector<bool> used(n);
    vector<int> min_e(n, INF), sel_e(n, -1);
    min_e[0] = ans = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for(int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || min_e[j] < min_e[v])) {
                v = j;
            }
        }
        used[v] = true;
        if (sel_e[v] != -1) {
            ans += min_e[v];
        }
        for (int to = 0; to < n; ++to) {
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}


