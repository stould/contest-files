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

typedef long long ll;
typedef unsigned uint;

const int MAXN = 107;
int N, P, a, b, pivot, vis[MAXN];
vector<int> graph[MAXN];
pair<int, int> vp[MAXN];

void bfs(int start) {
    memset(vis, 0, sizeof(vis));

    queue<int> q; q.push(start); vis[start] = 1;

    int i;

    for ( ; !q.empty(); ) {
        int now = q.front(); q.pop();

        for (i = 0; i < graph[now].size(); i++) {
            int u = graph[now][i];

            if (!vis[u]) {
                q.push(u);
                vis[u] = 1;
            }
        }
    }
}

int ok (int id_a, int id_b) {
    if (vp[id_b].first < vp[id_a].first && vp[id_a].first < vp[id_b].second) return 1;
    if (vp[id_b].first < vp[id_a].second && vp[id_a].second < vp[id_b].second) return 1;
    return 0;
}

int main(void) {
    scanf("%d", &N);

    int i, j;

    pivot = 0;

    for (i = 0; i < N; i++) {
        scanf("%d%d%d", &P, &a, &b);

        if (P == 1) {
            vp[pivot] = make_pair(a, b);
            for (j = 0; j < pivot; j++) {
                if (ok(j, pivot)) {
                    graph[j].push_back(pivot);
                }
                if (ok(pivot, j)) {
                    graph[pivot].push_back(j);
                }
            }
            pivot += 1;
        } else {
            a -= 1; b -= 1;
            bfs(a);

            if (vis[b]) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }
    return 0;
}
