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
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 100007;
int N, E, A, B, Q, C, G1, G2, T;
int vis[MAXN];

vector<int> graph[MAXN];

int bfs1(void) {
    queue<int> q; q.push(A);

    memset(vis, 0, sizeof(vis));

    vis[A] = 1;

    int i;

    for ( ; !q.empty(); ) {
        int now = q.front(); q.pop();

        if (now == B) return 1;

        for (i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if ((now == G1 && next == G2) || (now == G2 && next == G1)) continue;

            if (!vis[next]) {
                vis[next] = 1;
                q.push(next);
            }
        }
    }

    return 0;
}

int bfs2(void) {
    queue<int> q; q.push(A);

    if (A == C || B == C) return 0;

    memset(vis, 0, sizeof(vis));

    vis[A] = 1;

    int i;

    for ( ; !q.empty(); ) {
        int now = q.front(); q.pop();

        if (now == B) return 1;

        for (i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (next == C) continue;

            if (!vis[next]) {
                vis[next] = 1;
                q.push(next);
            }
        }
    }

    return 0;
}

int main(void) {
    freopen("i.in", "r", stdin);
    int i;

    for ( ; scanf("%d%d", &N, &E) == 2; ) {

        for (i = 0; i < MAXN; i++) graph[i].clear();

        for (i = 0; i < E; i++) {
            A = in(), B = in();

            graph[A].push_back(B);
            graph[B].push_back(A);
        }

        Q = in();

        for ( ; Q--; ) {
            T = in();

            if (T == 1) {
                A = in(), B = in(), G1 = in(), G2 = in();

                printf("%s\n", bfs1() ? "SIM" : "NAO");
            } else {
                A = in(), B = in(), C = in();

                printf("%s\n", bfs2() ? "SIM" : "NAO");
            }
        }
    }
    return 0;
}
