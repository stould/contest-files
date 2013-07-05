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
    if (!b) return a;
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

const int MAXN = 1010;
const int INF = 100101000;

int C, R, W, dist[MAXN*MAXN], vis[MAXN*MAXN], f[MAXN*MAXN];
int graph[MAXN*MAXN];

int dx[24] = { 0,0,-1,1, -1,-1, 1,1,   0,0,-2,2,- 2,-2, 2,2,-2, 2,-2, 2,-1,-1, 1,1};
int dy[24] = {-1,1, 0,0,  1,-1,-1,1,  -2,2, 0,0,  2,-2,-2,2,-1,-1, 1, 1,-2, 2,-2,2};
int ct[24] = { 2,2, 2,2,  3, 3, 3,3,   5,5, 5,5,  7, 7, 7,7, 6, 6, 6, 6, 6, 6, 6,6};

int CF, RF, CT, RT;

int conv (int x, int y) {
    return (x-1) * C + (y-1);
}

pair<int, int> rev (int x) {
    return make_pair((x/C)+1, (x%C)+1);
}

struct MyLess {
    bool operator () (int x, int y) {
        return f[x] > f[y];
    }
};

int func (void) {
    int i, j;

    dist[conv(RF,CF)] = 0;
    vis[conv(RF,CF)] = 0;

    priority_queue<int, vector<int>, MyLess> q;

    q.push(conv(RF, CF));

    for ( ; !q.empty(); ) {
        int now = q.top(); q.pop();

        if (vis[now]) {
            continue;
        }

        vis[now] = 1;

        if (now == conv(RT, CT)) return dist[now];

        pair<int, int> od = rev(now);

        for (i = 0; i < 24; i++) {
            int ni = od.first + dx[i];
            int nj = od.second + dy[i];

            int next = conv(ni, nj);

            if (ni <= 0 || nj <= 0 || ni > R || nj > C || graph[next] == 1 || vis[next]) continue;

            if (next >= 0 && next < R * C) {
                int next_cost = dist[now] + ct[i];
                int heuristic = max(abs(ni - RT),abs(nj - CT))*2;

                if (next_cost < dist[next]) {
                    dist[next] = next_cost;
                    f[next] = heuristic + next_cost;
                    q.push(next);
                }

            }
        }
    }

    return dist[conv(RT,CT)];

}

int main(void) {
    freopen("i.in", "r", stdin);
    //freopen("o.ot", "w", stdout);
    int i, j, x;
    for ( ; scanf("%d%d", &C, &R) == 2 && (C + R != 0); ) {
        scanf("%d%d%d%d%d", &CF, &RF, &CT, &RT, &W);

        for (i = 0; i <= R * C; i++) {
            graph[i] = vis[i] = 0;
            dist[i] = f[i] = INF;
        }

        for (x = 0; x < W; x++) {
            int c1, r1, c2, r2;
            scanf("%d%d%d%d", &c1, &r1, &c2, &r2);

            for (i = r1; i <= r2; i++) {
                for (j = c1; j <= c2; j++) {
                    graph[conv(i, j)] = 1;
                }
            }
        }

        int cost = func();

        if (cost == INF) {
            puts("impossible");
        } else {
            printf("%d\n", cost);
        }
    }

    return 0;
}
