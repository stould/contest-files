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

const int MAXN = 107;
int N, dist[MAXN], vis[MAXN], matrix[MAXN][MAXN];

struct edge {
    int f, t, c;

    edge() {}

    edge(int f, int t, int c): f(f), t(t), c(c) {}
};

bool dfs(int x) {
    vis[x] = 1;

    int i;

    for (i = 1; i <= N; i++) if (matrix[x][i]) {
        if (i == N) return true;
        if (!vis[i] && dfs(i)) return true;
    }

    return false;
}


string func(int start, int end, vector<edge>& graph) {
    int i, j;

    for (i = 0; i < MAXN; i++) {
        dist[i] = INT_MAX / 2;
    }

    dist[start] = -100;

    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < (int) graph.size(); j++) {
            int now = graph[j].f, next = graph[j].t, cost = dist[now] + graph[j].c;

            if (dist[next] > cost && cost < 0) {
                dist[next] = cost;
            }
        }
    }

    bool winnable = dist[N] <= 0;

    for (i = 0; i < graph.size(); i++) {
        int now = graph[i].f, next = graph[i].t, cost = dist[now] + graph[i].c;

        if (cost < dist[next] && cost < 0) {
            memset(vis, 0, sizeof(vis));
            if (dfs(now)) winnable = 1;
        }
    }

    return !winnable ? "hopeless" : "winnable";
}

int main(void) {
    int i, x, cost, next;
    for( ; 1 == scanf("%d", &N) && N != -1; ) {
        vector<edge> graph;

        memset(matrix, 0, sizeof(matrix));

        for (i = 1; i <= N; i++) {
            scanf("%d%d", &cost, &x);

            cost *= -1;

            for ( ; x--; ) {
                scanf("%d", &next);
                graph.push_back(edge(i, next, cost));
                matrix[i][next] = 1;
            }
        }
        cout << func(1, N, graph) << "\n";
    }
    return 0;
}
