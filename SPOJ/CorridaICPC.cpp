#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
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

const int MAXN = 110;
const int INF = 1001000010;

int T, N, M;
int goal;
bool best, eq;

vector<int> graph[MAXN];
int dist[MAXN][MAXN];

bool vis[MAXN];

void dfs(int x, int root, int len, int seen) {
	if (best) return;
	vis[x] = true;

	if (x == root && seen > 1) {
		if (seen % 2 == 1) {			
			if (len <= goal) {
				best = true;
			}
			if (len == goal) {
				eq = true;
			}
		}
		return;
	} else {
		for (int i = 0; i < (int) graph[x].size(); i++) {
			int u = graph[x][i];
			
			if (!vis[u] || (u == root && seen % 2 == 1)) {
				dfs(u, root, len + dist[x][u], u == root ? seen : seen + 1);
			}
		}
	}
}

int main(void) {
    T = in();

    for ( ; T--; ) {
        N = in(), M = in();

		for (int i = 1; i <= N; i++) {
			graph[i].clear();
			for (int j = 1; j <= N; j++) {
				dist[i][j] = 0;
			}
		}

        for(int i = 0; i < M; i++) {			
            int a = in();
			int b = in();
			int c = in();

			graph[a].push_back(b);
			graph[b].push_back(a);

            chmax(dist[a][b], c);
            chmax(dist[b][a], c);
        }

		int ans = INF;
		int l = 0, h = 20, m;
		
		for ( ; l <= h; ) {		
			m = (l + h) / 2;

			goal = m;

			bool ok = false;
			
			for (int i = 1; i <= N; i++) {
				best = eq = false;
				
				memset(vis, false, sizeof(vis));
				dfs(i, i, 0, 1);

				if (best) {
					ok = true;
					break;
				}
			}
			
			if (eq) {
				chmin(ans, m);
			}

			if (ok) {
				h = m - 1;
			} else {
				l = m + 1;
			}
		}

        if (ans == INF) {
            puts("impossivel");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
