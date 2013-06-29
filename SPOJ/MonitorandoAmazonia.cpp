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

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

struct point {
    int x, y;
};

const int MAXN = 1009;
const double EPS = 1e-4;
int N;
int vis[MAXN];
double dist[MAXN][MAXN];
point p[MAXN];
int graph[MAXN][2];

void dfs(int p) {
    vis[p] = 1;

    int u = graph[p][0], v = graph[p][1];

    if (!vis[u]) dfs(u);
    if (!vis[v]) dfs(v);
}

bool eq(double a, double b) {
    return fabs(a - b) < EPS;
}

pair<int, int> func(int f) {
    int i, a = -1, b = -1;

    double dist_a = 10101010010010.0, dist_b = 10101010010010.0, curr;

    for (i = 0; i < N; i++) if (i != f) {
        curr = dist[f][i];

        if (curr < dist_a) {
            dist_b = dist_a;
            dist_a = curr;
            b = a; a = i;
        } else if (eq(curr, dist_a)) {
            if (a == -1) {
                a = i; dist_a = curr;
            } else if (p[i].x < p[a].x || (p[i].x == p[a].x && p[i].y < p[a].y)) {
                dist_b = dist_a;
                dist_a = curr;
                b = a; a = i;
            } else if (curr < dist_b || (eq(curr, dist_b) && p[i].x < p[b].x || (p[i].x == p[b].x && p[i].y < p[b].y))) {
                dist_b = curr; b = i;
            }
        } else if (curr < dist_b) {
            dist_b = curr; b = i;
        } else if (eq(curr, dist_b)) {
            if (b == -1 || p[i].x < p[b].x || (p[i].x == p[b].x && p[i].y < p[b].y)) {
                dist_b = curr; b = i;
            }
        }
    }

    return make_pair(a, b);
}

int main(void) {
    int i, j;

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {

        for (i = 0; i < N; i++) {
            scanf("%d%d", &p[i].x, &p[i].y);
            graph[i][0] = graph[i][1] = -1;
            vis[i] = 0;
        }

        for (i = 0; i < N; i++) {
            for (j = 0; j <= i; j++) {
                dist[i][j] = dist[j][i] = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
            }
        }

        for (i = 0; i < N; i++) {
            pair<int, int> p = func(i);

            graph[i][0] = p.first;
            graph[i][1] = p.second;
        }

        dfs(0);

        int r = accumulate(vis, vis + N, 0);

        if (N > 3 && r != N) {
            puts("There are stations that are unreachable.");
        } else {
            puts("All stations are reachable.");
        }
    }
    return 0;
}
