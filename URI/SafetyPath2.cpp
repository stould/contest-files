#include <bits/stdc++.h>

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
const int INF = INT_MAX / 3;

int N, M;

struct edge {
    int to;
    int cap;
    int cost;
    int rev;
};

vector <edge> g[MAXN];

int dist[MAXN];
int prevv[MAXN];
int preve[MAXN];

void add_edge(int from, int to, int cap, int cost) {
    g[from].push_back((edge){to, cap, cost, g[to].size()});
    g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
}

pair<int, Int> min_cost_flow(int s, int t, int f) {
    Int res = 0LL;

    while (f > 0) {
        int d = f;
        priority_queue <pair<int, int> > q;

        for (int i = 0; i <= N; i++) {
			dist[i] = INF;
		}

        dist[s] = 0;

        q.push(make_pair(0, s));

        while (!q.empty()) {
            int c = -q.top().first;
            int v = q.top().second;

            q.pop();

            if (dist[v] < c) continue;

            for (int i = 0; i < g[v].size(); i++) {
                edge &e = g[v][i];

                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    q.push(make_pair(-dist[e.to], e.to));
                }
            }
        }
		
        if (dist[t] == INF) {
			break;
		}

		int curr_cost = 0;

        for (int i = t; i != s; i = prevv[i]) {
			d = min(d, g[prevv[i]][preve[i]].cap);
			curr_cost += g[prevv[i]][preve[i]].cost;
		}

		if (f - d < 0) {
			d = (d - f);
		}

        f -= d;		
        res += d * curr_cost;

        for (int i = t; i != s; i = prevv[i]) {
            edge &e = g[prevv[i]][preve[i]];
            e.cap -= d;
            g[i][e.rev].cap += d;
        }
    }
	
    return make_pair(f, res);
}

int main(void) {
	for ( ; scanf("%d", &N) == 1 && N != 0; ) {
		scanf("%d", &M);

		for (int i = 0; i < MAXN; i++) {
			g[i].clear();
		}
		
		for (int i = 0; i < M; i++) {
			int A, B, C;
			scanf("%d%d%d", &A, &B, &C);

			add_edge(A, B, 1, C);
			add_edge(B, A, 1, C);
		}
		
		pair<int, Int> ans = min_cost_flow(1, N, 2);

		if (ans.first != 0) {
			puts("Pernoite.");
		} else {
			printf("%lld\n", ans.second);
		}
	}
    return 0;
}
