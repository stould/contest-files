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

int N;
Int M[110][110];

const Int SHOLD = 1000000000000LL;

typedef Int Flow;
typedef Int Cost;

const Flow INF = 1000101010010100LL;

struct Edge {
    Int src, dst;
    Cost cst;
    Flow cap;
    Int rev;
};
bool operator<(const Edge a, const Edge b) {
    return a.cst > b.cst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph&G, int u, int v, Flow c, Cost l) {
    G[u].push_back((Edge){ u, v, l, c, int(G[v].size()) });
    G[v].push_back((Edge){ v, u, -l, 0, int(G[u].size()-1) });
}

pair<Flow, Cost> flow(Graph&G, int s, int t, Int K) {
    int n = G.size();
    Flow flow = 0;
    Cost cost = 0;
    for ( ; ; ) {
        priority_queue<Edge> Q;
        vector<int> prev(n, -1), prev_num(n, -1);
        vector<Cost> length(n, INF);
        Q.push((Edge){-1,s,0,0,0});
        prev[s]=s;
        for (;!Q.empty();) {
            Edge e=Q.top();
			Q.pop();
            Int v = e.dst;
            for (Int i=0; i<(int)G[v].size(); i++) {
                if (G[v][i].cap>0 && length[G[v][i].dst]>e.cst+G[v][i].cst) {
                    prev[G[v][i].dst]=v;
                    Q.push((Edge){v, G[v][i].dst, e.cst+G[v][i].cst,0,0});
                    prev_num[G[v][i].dst]=i;
                    length[G[v][i].dst]=e.cst+G[v][i].cst;
                }
            }
        }
        if (prev[t]<0) return make_pair(flow, cost);

        Flow mi=INF;
        Cost cst=0;
        for (int v=t; v!=s; v=prev[v]) {
            mi=min(mi, G[prev[v]][prev_num[v]].cap);
            cst+=G[prev[v]][prev_num[v]].cst;
        }

		K -= cst*mi;
        cost+=cst*mi;

        for (int v=t; v!=s; v=prev[v]) {
            Edge &e=G[prev[v]][prev_num[v]];
            e.cap-=mi;
            G[e.dst][e.rev].cap+=mi;
        }
        flow += mi;
    }

}

int main(void) {
	while (scanf("%d", &N) == 1) {
		Graph gf(N + N + 5);

		for (int i = 1; i <= N; i++) {
			add_edge(gf, 0, i, 1, 0);
			add_edge(gf, N + i, N + N + 2, 1, 0);

			for (int j = 1; j <= N; j++) {
				cin >> M[i][j];
				add_edge(gf, i, N + j, 1, SHOLD - M[i][j]);
			}
		}

		pair<Int, Int> f = flow(gf, 0, N + N + 2, INF);

		printf("%lld\n", -f.second  + (Int) N * SHOLD);
	}
	return 0;
}
