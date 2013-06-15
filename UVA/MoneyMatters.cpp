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

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 10010;

int i, test, a, b, n, m, v[MAXN], vis[MAXN], check;
vector<int> graph[MAXN];

void dfs(int x) {
    vis[x] = 1;
    check += v[x];
    int i;
    REP(i, graph[x].size()) {
        int u = graph[x][i];
        if(!vis[u]) {
            dfs(u);
        }
    }
}

int main(void) {
    #ifdef AAJJBB
    freopen("i.in", "r", stdin);
    #endif
    scanf("%d", &test);
    for( ; test--; ) {
        scanf("%d%d", &n, &m);
        REP(i, MAXN) {
            vis[i] = 0;
            graph[i].clear();
        }
        REP(i, n) {
            scanf("%d", &v[i]);
        }
        int outcome = 0;
        REP(i, m) {
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int ok = 1;
        REP(i, n) if(!vis[i]) {
            check = 0;
            dfs(i);
            if(check != 0) {
                ok = 0;
            }
        }
        if(ok) {
            puts("POSSIBLE");
        } else {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}

