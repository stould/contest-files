#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2255;

int N, K;
int P[MAXN][MAXN];
int SZ[MAXN];

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

int main() {
	freopen("arrays.in", "r", stdin);
	freopen("arrays.out", "w", stdout);
 
	cin >> N >> K;

	int s = 0;
	int t = 2400;

	Graph G(2500);
   
	for (int i = 1; i <= N; i++) {
		cin >> SZ[i];
   
		add_edge(G, s, i, K, 0);
   
		for (int j = 0; j < SZ[i]; j++) {
			cin >> P[i][j];

			add_edge(G, i, N + P[i][j], 1, 0);
		}
	}

	for (int i = 1; i <= 1000; i++) {
		add_edge(G, N + i, t, 1, -i);
	}
 
	pair<int, int> f = flow(G, s, t);

	cout << abs(f.second) << "\n";
 
	vector<vector<int> > ans(N + 1, vector<int>());
 
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (int) G[i].size(); j++) {
			if (G[i][j].dst > N && G[i][j].cap == 0) {
				ans[i].push_back(G[i][j].dst - N);
			}
		}
		cout << ans[i].size() << " ";
		for (int j = 0; j < (int) ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
 
	return 0;
}
