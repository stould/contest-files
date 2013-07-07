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

template<typename T> void chmin(T& a, T b) {
    a = (a > b) ? b : a;
}
template<typename T> void chmax(T& a, T b) {
    a = (a < b) ? b : a;
}

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 211;
const int INF = 1000000000;

int X, N, P, V, T = 1;

int c[MAXN][MAXN], f[MAXN][MAXN], s, t, d[MAXN], ptr[MAXN], q[MAXN];

void add_edge (int a, int b, int f) {
    c[a][b] = f;
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, MAXN * sizeof d[0]);
	d[s] = 0;
	while (qh < qt) {
		int v = q[qh++];
		for (int to=0; to<MAXN; ++to)
			if (d[to] == -1 && f[v][to] < c[v][to]) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
	}
	return d[t] != -1;
}

int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (int & to=ptr[v]; to<MAXN; ++to) {
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, c[v][to] - f[v][to]));
		if (pushed) {
			f[v][to] += pushed;
			f[to][v] -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, MAXN * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int main(void) {
    scanf("%d", &X);

    int i, j;

    for ( ; X--; ) {
        for (i = 0; i < MAXN; i++) {
            d[i] = ptr[i] = q[i] = 0;
            for (j = 0; j < MAXN; j++) {
                c[i][j] = f[i][j] = 0;
            }
        }
        scanf("%d", &N);

        s = 0, t = 2*N+1;

        for (i = 1; i <= N; i++) {
            add_edge(s, i, 1);
            add_edge(i+N, t, 1);
        }

        for (i = 1; i <= N; i++) {
            scanf("%d", &P);
            for (j = 0; j < P; j++) {
                scanf("%d", &V);
                add_edge(i, V+N, 1);
            }
        }

        int f = dinic();

        printf("Instancia %d\n", T++);

        if (f == N) {
            printf("pair programming\n");
        } else {
            printf("extreme programming\n");
        }
        printf("\n");
    }
    return 0;
}
