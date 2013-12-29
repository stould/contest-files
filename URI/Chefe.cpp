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
const int INF = 10101010;

int N, M, I;
int age[MAXN], mp[MAXN];
char C;

vector<int> graph[MAXN];

int bfs(int x) {
    int vis[MAXN]; memset(vis, 0, sizeof(vis));

    vis[x] = 1;

    queue<int> q; q.push(x);

    int i, ans = INF;

    for ( ; !q.empty(); ) {
        int curr = q.front(); q.pop();

        for (i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];

            if (!vis[next]) {
                vis[next] = 1;
                q.push(next);

                chmin(ans, age[next]);
            }
        }
    }

    return ans;
}

int main(void) {
    int i, x, y;

    for ( ; scanf("%d%d%d", &N, &M, &I) == 3; ) {
        for (i = 1; i <= N; i++) {
            scanf("%d", &age[i]); mp[i] = i;
            graph[i].clear();
        }

        for (i = 0; i < M; i++) {
            scanf("%d%d", &x, &y);
            graph[y].push_back(x);
        }

        for (i = 0; i < I; i++) {
            scanf(" %c", &C);

            if (C == 'T') {
                scanf("%d%d", &x, &y);
                swap(age[mp[x]], age[mp[y]]);
                int a = mp[x];
                mp[x] = mp[y];
                mp[y] = a;
            } else {
                scanf("%d", &x);

                int ans = bfs(mp[x]);

                if (ans == INF) {
                    puts("*");
                } else {
                    printf("%d\n", ans);
                }
            }
        }
    }
    return 0;
}
