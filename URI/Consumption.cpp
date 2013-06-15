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
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int i, j, e, v, n, test = 1, vis[30];
char a, b;
vector<int> order, comp, ga[26], gb[26];

void dfs1(int x) {
    vis[x] = 1;
    int u;
    REP(u, ga[x].size()) {
        if(!vis[ga[x][u]]) dfs1(ga[x][u]);
    }
    order.push_back(x);
}

void dfs2(int x) {
    comp.push_back(x);
    vis[x] = 1;
    int u;
    REP(u, gb[x].size()) {
        if(!vis[gb[x][u]]) dfs2(gb[x][u]);
    }
}

int main(void) {
    scanf("%d", &n);
    for( ; n > 0; --n) {
        scanf("%d%d", &v, &e);
        REP(i, 26) {
            ga[i].clear(); gb[i].clear();
        }
        REP(i, e) {
            scanf(" %c %c", &a, &b);
            int u = (int) a - 'a';
            int v = (int) b - 'a';
            ga[u].push_back(v);
            gb[v].push_back(u);
        }
        order.clear();
        memset(vis, 0, sizeof(vis));
        REP(i, v) if(!vis[i]) dfs1(i);
        memset(vis, 0, sizeof(vis));
        printf("Case #%d\n", test++);
        int ans = 0;
        REP(i, order.size()) {
            int v = order[i];
            if(!vis[v]) {
                comp.clear();
                dfs2(v);
                if(!comp.empty()) ans += 1;
                REP(j, comp.size()) {
                    printf("%c,", (char) 'a' + comp[j] + 'a');
                }
                printf("\n");
            }
        }
        printf("%d connected components\n\n", ans);
    }
    return 0;
}
