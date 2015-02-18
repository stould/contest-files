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

int T, N, R;
pair<int, int> pn[MAXN], pr[MAXN];

typedef int Flow;
typedef int Cost;

const Flow INF = 0x3f3f3f3f;

struct Edge {
    int src, dst;
    Cost cst;
    Flow cap;
    int rev;
};
bool operator<(const Edge a, const Edge b) {
    return a.cst>b.cst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph&G, int u, int v, Flow c, Cost l) {
    G[u].push_back((Edge){ u, v, l, c, int(G[v].size()) });
	G[v].push_back((Edge){ v, u, -l, 0, int(G[u].size()-1) });
}

pair<Flow, Cost> flow(Graph&G, int s, int t, int K) {
    int n = G.size();
    Flow flow = 0;
    Cost cost = 0;
    for ( ; ; ) {
        priority_queue<Edge> Q;
        vector<int> prev(n, -1), prev_num(n, -1);
        vector<Cost> length(n, INF);
        Q.push((Edge){-1,s,0,0,0});
        prev[s] = s;
        for (;!Q.empty();) {
            Edge e = Q.top(); 
			Q.pop();
            int v = e.dst;
            for (int i=0; i<(int)G[v].size(); i++) {
                if (G[v][i].cap > 0 && length[G[v][i].dst] > e.cst + G[v][i].cst) {
                    prev[G[v][i].dst] = v;
                    Q.push((Edge){v, G[v][i].dst, e.cst+G[v][i].cst,0,0});
                    prev_num[G[v][i].dst] = i;
                    length[G[v][i].dst] = e.cst + G[v][i].cst;
                }
            }
        }
        if (prev[t]<0) return make_pair(flow, cost);

        Flow mi = INF;
        Cost cst = 0;
        for (int v=t; v!=s; v=prev[v]) {
            mi=min(mi, G[prev[v]][prev_num[v]].cap);
            cst+=G[prev[v]][prev_num[v]].cst;
        }

		if (cst > K) return make_pair(flow, cost);
		
		if (cst != 0) mi = min(mi, K/cst);

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
	for ( ; scanf("%d%d", &R, &N) == 2; ) {
		for (int i = 1; i <= R; i++) {
			scanf("%d%d", &pr[i].first, &pr[i].second);
		}
		for (int i = 1; i <= N; i++) {
			scanf("%d%d", &pn[i].first, &pn[i].second);
		}
		int s = 0, t = R + N + 3;

		Graph graph(t + 2);
		
		for (int i = 1; i <= R; i++) {
			add_edge(graph, s, i, 1, 0);
			for (int j = 1; j <= N; j++) {
				int dst = abs(pr[i].first - pn[j].first) + abs(pr[i].second - pn[j].second);				
				add_edge(graph, i, R + j, 1, dst);
			}
		}
		for (int i = 1; i <= N; i++) {
			add_edge(graph, i + R, t, 1, 0);
		}
		pair<Flow, Cost> f = flow(graph, s, t, 10101010);

		printf("%d\n", f.second);
	}
    return 0;
}
