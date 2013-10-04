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
const int INF = 1010101000;

int N, M, S, D, U, V, P;
vector<pair<int, int> > graph[MAXN];

bool blocked[MAXN][MAXN];
bool vis[MAXN];
int dist[MAXN];

vector<int> path[MAXN];

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;

	ch = getchar();

	while (1) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') {
	    minus = true;
    } else {
        result = ch-'0';
    }

	while (1) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

struct cmp {
    bool operator()(int a, int b) {
        return dist[a] > dist[b];
    }
};

int identifyPath(void) {
    priority_queue<int, vector<int>, cmp> q;

    q.push(S); dist[S] = 0;

    int i;

    for ( ; !q.empty(); ) {
        int id = q.top(); q.pop();

        for (i = 0; i < graph[id].size(); i++) {
            int next_id = graph[id][i].first;
            int next_cost = graph[id][i].second;

            if (dist[id] + next_cost < dist[next_id]) {
                dist[next_id] = dist[id] + next_cost;
                q.push(next_id);

                path[next_id].clear();
                path[next_id].push_back(id);
            } else if (dist[id] + next_cost == dist[next_id]) {
                path[next_id].push_back(id);
            }
        }
    }

    return dist[D];
}

void dfs(int x) {
    vis[x] = 1;

    int i;

    for (i = 0; i < (int) path[x].size(); i++) {
        int u = path[x][i];

        blocked[u][x] = 1;

        if (!vis[u]) dfs(u);
    }
}

int almostShortestPath(void) {
    priority_queue<int, vector<int>, cmp> q;

    int i;

    for (i = 0; i < N; i++) dist[i] = INF;

    q.push(S); dist[S] = 0;

    for ( ; !q.empty(); ) {
        int id = q.top(); q.pop();

        for (i = 0; i < graph[id].size(); i++) {
            int next_id = graph[id][i].first;
            int next_cost = graph[id][i].second;

            if (dist[id] + next_cost < dist[next_id] && !blocked[id][next_id]) {
                dist[next_id] = dist[id] + next_cost;
                q.push(next_id);
            }
        }
    }

    return dist[D] == INF ? -1 : dist[D];
}

int main(void) {
    int i, j;

    for ( ; ; ) {
        N = readInt();
        M = readInt();

        if (N + M == 0) break;

        S = readInt();
        D = readInt();

        for (i = 0; i < N; i++) {
            graph[i].clear();
            path[i].clear();

            vis[i] = false;
            dist[i] = INF;

            for (j = 0; j < N; j++) {
                blocked[i][j] = false;
            }
        }

        for (i = 0; i < M; i++) {
            U = readInt();
            V = readInt();
            P = readInt();

            graph[U].push_back(make_pair(V, P));
        }

        if (identifyPath() == INF) {
            printf("-1\n"); continue;
        }

        dfs(D);

        printf("%d\n", almostShortestPath());
    }
    return 0;
}
