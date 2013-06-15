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

const int MAXN = 50;
int a, b, start, T, N, M, vis[MAXN], dist[MAXN];
vector<int> graph[MAXN];

void addEdge(int x, int y) {
    graph[x].push_back(y);
    graph[y].push_back(x);
}

void bfs(int x) {
    queue<int> q; q.push(x); vis[x] = 1;
    int ans = 0;

    while(!q.empty()) {
        int now = q.front(); q.pop();

        REP(i, graph[now].size()) {
            int go = graph[now][i];
            if(!vis[go]) {
                vis[go] = 1;
                q.push(go);
                dist[go] = dist[now] + 1;
                ans += 1;
            }
        }
    }
    printf("%d\n", ans*2);
}

int main(void) {
    scanf("%d", &T);
    for( ; T--; ) {
        scanf("%d%d%d", &start, &N, &M);
        REP(i, MAXN) { graph[i].clear(); vis[i] = false; dist[i] = 0; }
        REP(i, M) {
            scanf("%d%d", &a, &b);
            addEdge(a, b);
        }
        bfs(start);
    }
    return 0;
}
