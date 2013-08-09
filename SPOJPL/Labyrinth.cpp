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

const int MAXN = 1007;
int T, R, C;
char maze[MAXN][MAXN];
int vis[MAXN][MAXN];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pair<pair<int, int> , int>  bfs(int root_i, int root_j) {
    memset(vis, -1, sizeof(vis));

    queue<pair<int, int> > q; q.push(make_pair(root_i, root_j));

    int i, far_node_i = root_i, far_node_j = root_j, distance = INT_MIN;

    vis[root_i][root_j] = 0;

    for ( ; !q.empty(); ) {
        pair<int, int> curr = q.front(); q.pop();

        for (i = 0; i < 4; i++) {
            int next_i = curr.first + dx[i], next_j = curr.second + dy[i];

            if (next_i >= 0 && next_i < R && next_j >= 0 && next_j < C && vis[next_i][next_j] == -1 && maze[next_i][next_j] == '.') {
                q.push(make_pair(next_i, next_j));
                vis[next_i][next_j] = vis[curr.first][curr.second] + 1;

                if (vis[next_i][next_j] > distance) {
                    distance = vis[next_i][next_j];
                    far_node_i = next_i;
                    far_node_j = next_j;
                }
            }
        }
    }

    if (distance == INT_MIN) distance = 0;

    return make_pair(make_pair(far_node_i, far_node_j), distance);
}

int main(void) {
    T = in();

    int i, j;

    for ( ; T--; ) {
        C = in(), R = in();

        int start_i, start_j;

        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                scanf(" %c", &maze[i][j]);

                if (maze[i][j] == '.') {
                    start_i = i;
                    start_j = j;
                }
            }
        }

        pair<pair<int, int>, int> before = bfs(start_i, start_j);
        pair<pair<int, int>, int> ans = bfs(before.first.first, before.first.second);

        printf("Maximum rope length is %d.\n", ans.second);

    }
    return 0;
}
