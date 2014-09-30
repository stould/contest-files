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

typedef Int Flow;
typedef Int Cost;

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

pair<Flow, Cost> flow(Graph&G, int s, int t) {
    int n = G.size();
    Flow flow = 0;
    Cost cost = 0;
    for ( ; ;) {
        priority_queue<Edge> Q;
        vector<int> prev(n, -1), prev_num(n, -1);
        vector<Cost> length(n, INF);
        Q.push((Edge){-1,s,0,0,0});
        prev[s] = s;
        for ( ; !Q.empty(); ) {
            Edge e = Q.top(); Q.pop();
            int v = e.dst;
            for (int i = 0; i < (int) G[v].size(); i++) {
                if (G[v][i].cap > 0 && length[G[v][i].dst] > e.cst + G[v][i].cst) {
                    prev[G[v][i].dst] = v;
                    Q.push((Edge){v, G[v][i].dst, e.cst+G[v][i].cst,0,0});
                    prev_num[G[v][i].dst] = i;
                    length[G[v][i].dst] = e.cst+G[v][i].cst;
                }
            }
        }

        if (prev[t]<0) return make_pair(flow, cost);

        Flow mi=INF;
        Cost cst=0;

        for (int v = t; v != s; v = prev[v]) {
            mi = min(mi, G[prev[v]][prev_num[v]].cap);
            cst += G[prev[v]][prev_num[v]].cst;
        }

        cost += cst * mi;

        for (int v = t; v != s; v = prev[v]) {
            Edge& e = G[prev[v]][prev_num[v]];
            e.cap -= mi;
            G[e.dst][e.rev].cap += mi;
        }
        flow += mi;
    }
}

int main(void) {
    int i;
    int j;

    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
		Graph g(N + 1);

        for (i = 0; i < M; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }

        cin >> D >> K;

        for (i = 0; i < M; i++) {
            add_edge(g, A[i], B[i], K, C[i]);
            add_edge(g, B[i], A[i], K, C[i]);
        }

        add_edge(g, 0, 1, D, 0);

        pair<Int, Int> fl = flow(g, 0, N);

        if (fl.first == D) {
            printf("%lld\n", fl.second);
        } else {
            puts("Impossible.");
        }
    }

    return 0;
}
