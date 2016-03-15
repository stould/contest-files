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
     
const int MAXN = 6010;
int T, N, u, v, ans, vis[MAXN], root_marked[MAXN];
vector<int> graph[MAXN];
     
void dfs(int now, int father = -1) {
    vis[now] = 1;
     
    int sons = 0;
    REP(i, graph[now].size()) {
        int next = graph[now][i];
        if(!vis[next]) {
            dfs(next, now);
            sons += 1;
        }
    }
    if(sons == 0 || root_marked[now] == 0) {
        ans += 1;
        root_marked[father] = root_marked[now] = 1;
    }
}
     
int main(void) {
    scanf("%d", &T);
    for( ; T--; ) {
        scanf("%d", &N);
     
        REP(i, MAXN) {
            graph[i].clear();
            vis[i] = 0; root_marked[i] = 0;
        }
     
        REP(i, N-1) {
            scanf("%d%d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        ans = 0;
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}
     
