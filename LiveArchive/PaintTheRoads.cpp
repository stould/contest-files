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
typedef unsigned long long uInt;
typedef unsigned uint;

int T, N, M, K;

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
    return a.cst > b.cst;
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
    
    for ( ; ; ) {
        priority_queue<Edge> Q;
        vector<int> prev(n, -1), prev_num(n, -1);
        vector<Cost> length(n, INF);
        Q.push((Edge){-1,s,0,0,0});
        prev[s]=s;
        for (;!Q.empty();) {
            Edge e=Q.top();
			Q.pop();
            int v = e.dst;
            for (int i=0; i<(int)G[v].size(); i++) {
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
    cin >> T;

    while (T--) {
        cin >> N >> M >> K;

        Graph G(N + N + 2);
        
        for (int i = 0; i < M; i++) {
            int A, B, C;
            cin >> A >> B >> C;

            A += 1;
            B += 1;
            
            add_edge(G, A, N + B, 1, C);
        }

        for (int i = 1; i <= N; i++) {
            add_edge(G, 0, i, K, 0);
            add_edge(G, N + i, N + N + 1, K, 0);
        }
        
        pair<Flow, Cost> ans = flow(G, 0, N + N + 1);

        if (ans.first == N * K) {
            cout << ans.second << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}
