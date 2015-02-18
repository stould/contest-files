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

const int MAXN = 210;
const Int INF = 1001000010010LL;

int N, M;

int A[5050];
int B[5050];

Int D, K;
Int C[5050];

struct edge {
    int to;
    Int cap;
    Int cost;
    int rev;
};

vector<edge> g[MAXN];

Int h[MAXN];
Int dist[MAXN];
int prevv[MAXN];
int preve[MAXN];

void add_edge(int from, int to, int cap, int cost) {
    g[from].push_back((edge){to, cap, cost, g[to].size()});
    g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
}

pair<Int, Int> min_cost_flow(int s, int t) {
    Int res = 0LL;
	Int f = 0;

    for (int i = 0; i < MAXN; i++) {
		h[i] = 0;
	}

    while (true) {
        Int d = INF;
        priority_queue <pair<Int, int> > q;

        for (int i = 0; i <= N; i++) {
			dist[i] = INF;
		}

        dist[s] = 0;

        q.push(make_pair(0LL, s));

        while (!q.empty()) {
            Int c = -q.top().first;
            int v = q.top().second;

            q.pop();

            if (dist[v] < c) continue;

            for (int i = 0; i < g[v].size(); i++) {
                edge &e = g[v][i];
				
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    q.push(make_pair(-dist[e.to], e.to));
                }
            }
        }
		
        if (dist[t] == INF) {
			break;
		}

        for (int i = 0; i <= N; i++) {
			h[i] += dist[i];
		}
		
        for (int i = t; i != s; i = prevv[i]) {
			d = min(d, g[prevv[i]][preve[i]].cap);
		}
		
        f += d;		
        res += d * h[t];
		
        for (int i = t; i != s; i = prevv[i]) {
            edge &e = g[prevv[i]][preve[i]];
            e.cap -= d;
            g[i][e.rev].cap += d;
        }
    }
	
    return make_pair(f, res);
}


int main(void) {
    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		for (int i = 0; i < MAXN; i++) {
			g[i].clear();
		}

        for (int i = 0; i < M; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }

        cin >> D >> K;

        for (int i = 0; i < M; i++) {
            add_edge(A[i], B[i], K, C[i]);
            add_edge(B[i], A[i], K, C[i]);
        }
		
        add_edge(0, 1, D, 0);
		
        pair<Int, Int> fl = min_cost_flow(0, N);

        if (fl.first == D) {
            printf("%lld\n", fl.second);
        } else {
            puts("Impossible.");
        }
    }
	
    return 0;

}
