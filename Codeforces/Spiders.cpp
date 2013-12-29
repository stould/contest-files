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

int N;
int A, B, len, vis[110];
vector<int> graph[110];

int func(void) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int> > q; q.push(make_pair(1, 0)); vis[1] = 1;

    int i, goal = -1, m_dist = -1, ans = -1;

    for ( ; !q.empty(); ) {
        int pos = q.front().first;
        int dist = q.front().second;

        if (dist > m_dist) {
            m_dist = dist;
            goal = pos;
        }

        q.pop();

        for (i = 0; i < graph[pos].size(); i++) {
            int u = graph[pos][i];

            if (!vis[u]) {
                vis[u] = 1;
                q.push(make_pair(u, dist + 1));
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    q.push(make_pair(goal, 0)); vis[goal] = 1;


    for ( ; !q.empty(); ) {
        int pos = q.front().first;
        int dist = q.front().second;

        ans = max(ans, dist);

        q.pop();

        for (i = 0; i < graph[pos].size(); i++) {
            int u = graph[pos][i];

            if (!vis[u]) {
                vis[u] = 1;
                q.push(make_pair(u, dist + 1));
            }
        }
    }

    return ans;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    N = in();

    int i, j, ans = 0;

    for (i = 0; i < N; i++) {
        len = in();

        for (j = 0; j <= 100; j++) graph[j].clear();

        for (j = 0; j < len - 1; j++) {
            A = in(), B = in();
            graph[A].push_back(B);
            graph[B].push_back(A);
        }

        ans += func();
    }

    printf("%d\n", ans);
    return 0;
}
