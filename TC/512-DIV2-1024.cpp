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

class DoubleRoshambo {
public:
	int maxScore(vector <string>, vector <string>);
};
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

pair<Flow, Cost> flow(Graph&G, int s, int t, int K) {
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

bool win(char a, char b) {
	if (a == 'R') {
		return b == 'S';
	} else if (a == 'P') {
		return b == 'R';
	} else {
		return b == 'P';
	}
}

int outcome(string a, string b) {
	if (win(a[1], b[1])) {
		if (win(a[0], b[0])) {
			return 2;
		} else if (a[0] == b[0]) {
			return 1; 
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

int DoubleRoshambo::maxScore(vector <string> A, vector <string> E) {
	int N = (int) A.size();
	
	int s = 0, t = N + N + 5;		
	
	Graph G(t + 2);
	
	for (int i = 0; i < N; i++) {
		add_edge(G, s, i + 1, 1, 0);

		for (int j = 0; j < N; j++) {
			add_edge(G, i + 1, N + j + 1, 1, 2 - outcome(A[i], E[j]));
		}	

		add_edge(G, N + i + 1, t, 1, 0);
	}

	return 2 * N - flow(G, s, t, INF).second;
}

//Powered by [KawigiEdit] 2.0!
