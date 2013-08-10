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

const int MAXN = 10007;
int A, B, N;
int vis[MAXN];

vector<int> graph[MAXN];

pair<int, int> bfs(int root) {
    memset(vis, -1, sizeof(vis));

    queue<int> q; q.push(root);

    int i, far_node = -1, distance = INT_MIN;

    vis[root] = 0;

    for ( ; !q.empty(); ) {
        int curr = q.front(); q.pop();

        for (i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];

            if (vis[next] == -1) {
                vis[next] = vis[curr] + 1;
                q.push(next);

                if (vis[next] > distance) {
                    distance = vis[next];
                    far_node = next;
                }
            }
        }
    }

    return make_pair(far_node, distance);
}

int main(void) {
    N = in();

    int i;

    for (i = 0; i < N - 1; i++) {
        A = in(), B = in();

        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    pair<int, int> prev = bfs(1);

    printf("%d\n", bfs(prev.first).second);

    return 0;
}
