#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1000007;
int N, M, T, x, y, ans, cnt, vis[MAXN], in[MAXN], id[MAXN];

vector<int> graph[MAXN], graphB[MAXN], order;

void dfs1(int x) {
    int i;
    vis[x] = 1;

    for (i = 0; i < graph[x].size(); i++) {
        if (!vis[graph[x][i]]) {
            dfs1(graph[x][i]);
        }
    }

    order.push_back(x);
}

void dfs2(int x, int cp) {
    int i;

    vis[x] = 1; id[x] = cp;

    for (i = 0; i < graphB[x].size(); i++) {
        if (!vis[graphB[x][i]]) {
            dfs2(graphB[x][i], cp);
        }
    }
}

int main(void) {
    int i, j;
    scanf("%d", &T);
    for ( ; T--; ) {
        scanf("%d%d", &N, &M);

        order.clear();

        for (i = 0; i <= N; i++) {
            graph[i].clear(); graphB[i].clear();
            vis[i] =  in[i] = 0; id[i] = -1;
        }

        for (i = 0; i < M; i++) {
            scanf("%d%d", &x, &y); x--; y--;
            graph[x].push_back(y);
            graphB[y].push_back(x);
        }

        for (i = 0; i < N; i++) if (!vis[i]) dfs1(i);

        reverse(all(order)); memset(vis, 0, sizeof(vis)); ans = cnt = 0;

        for (i = 0; i < N; i++) if (!vis[order[i]]) {
            dfs2(order[i], cnt++);
        }

        for (i = 0; i < N; i++) for (j = 0; j < graph[i].size(); j++) if (id[i] != id[graph[i][j]]) in[id[graph[i][j]]] += 1;

        for (i = 0; i < cnt; i++) if (in[i] == 0) ans += 1;

        printf("%d\n", ans);
    }
    return 0;
}
