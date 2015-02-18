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

const int MAXN = 550;
const int INF = INT_MAX / 3;

int N, M;

int vis[MAXN];
int mrk[MAXN];
int deg[MAXN];

vector<int> graph[MAXN];

bool good;

int dfs(int x, int p) {
    mrk[x] = 1;

    if (vis[x]) {
        good = false;
        return -INF;
    }

    vis[x] = 1;

    int i, ans = 0;

    for (i = 0; i < (int) graph[x].size(); i++) {
        int u = graph[x][i];

        if (u != p) ans += dfs(u, x);
    }

    return 1 + ans;
}


int main(void) {
    int i;
    int A, B;
    int T = 1;

    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        for (i = 0; i < MAXN; i++) {
            vis[i] = mrk[i] = deg[i] = 0;
            graph[i].clear();
        }

        for (i = 0; i < M; i++) {
            A = in();
            B = in();

            graph[A].push_back(B);
            graph[B].push_back(A);

            deg[A] += 1;
            deg[B] += 1;
        }

        int tree = 0;

        for (i = 1; i <= N; i++) if (!mrk[i]) {
            good = true;
            int curr = dfs(i, -1);

            if (good) {
                tree += 1;
            }
            memset(vis, 0, sizeof(vis));
        }

        printf("Case %d: ", T++);

        if (tree > 1) {
            printf("A forest of %d trees.\n", tree);
        } else if (tree == 1) {
            puts("There is one tree.");
        } else {
            puts("No trees.");
        }
    }
    return 0;
}

