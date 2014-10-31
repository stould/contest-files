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

const int MAXN = 300;

int T, N, M;
int Q[MAXN], hold[MAXN], item[MAXN][MAXN];
map<int, int> dp[MAXN];

int func(int pos, int sum, int id) {
	if (sum < 0) {
		return 2;
	} else if (sum == 0) {
		return 1;
	} else if (pos >= Q[id]) {
		return 2;
	} else {
		if (dp[pos][sum] == 0) {
			dp[pos][sum] = 2;

			int y = func(pos + 1, sum, id);
			int n = func(pos + 1, sum - item[id][pos], id);

			if (y == 1 || n == 1) {
				dp[pos][sum] = 1;
			}
		}
		return dp[pos][sum];
	}
}


const Int NEED_FLOW = 100101010010101010LL;

struct edge {
	int from, to;
	Int cap;
	Int cost;
	Int flow;
};

vector<edge> edges;

void add_edge(int from, int to, Int cap, Int cost) {
	edge e = {from, to, cap, cost, 0};
	edges.push_back(e);
	edge e2 = {to, from, 0, -cost, 0};
	edges.push_back(e2);
}

Int mincost(int n, int s, int t) {
	Int cost = 0LL;
	Int flow = 0LL;

	while(flow < NEED_FLOW) {
		vector<int> p(n, -1);
		vector<Int> d(n);

		d[s] = 0;
		p[s] = s;

		bool changed = true;

		while(changed) {
			changed = false;
			
			for(int i = 0; i < (int) edges.size(); ++i) {
				edge& e = edges[i];
				if(e.cap == e.flow || p[e.from] == -1)
					continue;
				if(p[e.to] == -1 || d[e.to] > d[e.from] + e.cost) {
					d[e.to] = d[e.from] + e.cost;
					p[e.to] = i;
					changed = true;
				}
			}
		}
		if(p[t] == -1) {
			break;
		}
		if(d[t] >= 0) { // only for mincost, not mincostmaxflow
			break;
		}		
		int cur = t;
		Int maxAdd = NEED_FLOW - flow;

		while(cur != s) {
			edge& e = edges[p[cur]];
			cur = e.from;
			maxAdd = min(maxAdd, e.cap - e.flow);
		}

		flow += maxAdd;
		cost += d[t] * maxAdd;
		cur = t;
		
		while(cur != s) {
			int id = p[cur];
			edges[id].flow += maxAdd;
			edges[id ^ 1].flow -= maxAdd;
			cur = edges[id].from;
		}
	}
	// cost and flow are final here
	return cost;
}

int main(void) {
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> M >> N;

		int source = 0, sink = N + M + 3;

		edges.clear();
		
		for (int i = 1; i <= M; i++) {
			cin >> hold[i];
			add_edge(source, i, 1, 0);
		}
		
		for (int i = 1; i <= N; i++) {			
			cin >> Q[i];
			
			for (int j = 0; j < Q[i]; j++) {
				cin >> item[i][j];
			}
			
			for (int j = 0; j <= Q[i]; j++) {
				dp[j].clear();
			}
			
			for (int j = 1; j <= M; j++) {
				if (func(0, hold[j], i) == 1) {
					add_edge(j, M + i, 1, -hold[j]);
				}
			}
			add_edge(M + i, sink, 1, 0);
		}

		int ans = mincost(sink + 1, source, sink);

		cout << abs(ans) << "\n";
	}
    return 0;
}
