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

inline void read(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if (c=='-') {
		neg = 1;
        c = getchar_unlocked();
    }
    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if (neg) {
        x = -x;
    }
}

const Int INF = 100101010010101010LL;;
const int MAXN = 20005;

int N, M, P;
vector<pair<int, int> > graphA[MAXN], graphB[MAXN];

void shortest_path(int from, Int dist[], vector<pair<int, int> > graph[]) {
	for (int i = 0; i <= N; i++) dist[i] = INF;

	dist[from] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	
	q.push(make_pair(0, from));
		
	for ( ; !q.empty(); ) {
		int d = q.top().first;
		int id = q.top().second;
		q.pop();

		if (d > dist[id]) continue;
		for (int i = 0; i < (int) graph[id].size(); i++) {
			int next = graph[id][i].first;
			int toll = graph[id][i].second;
			
			if (dist[next] > d + toll) {
				dist[next] = d + toll;
				q.push(make_pair(dist[next], next));
			}
		}
	}
}

struct Edge {
	int f, t, c;
	Edge(){}
	Edge(int _f, int _t, int _c): f(_f), t(_t), c(_c){}

	bool operator<(const Edge& other) const {
		return c < other.c;
	}
};


int main(void) {
	int test;
	read(test);

	for ( ; test--; ) {
		int s, t;
		read(N); read(M);
		read(s); read(t);
		read(P);

		priority_queue<Edge> e;

		for (int i = 0; i < M; i++) {
			int u, v, c;
			read(u);
			read(v);
			read(c);

			e.push(Edge(u, v, c));

			graphA[u].push_back(make_pair(v, c));
			graphB[v].push_back(make_pair(u, c));
		}


		Int dS[MAXN], dT[MAXN];
		
		shortest_path(s, dS, graphA);
		shortest_path(t, dT, graphB);

		Int ans = -1LL;

		/*
		for (int i = 0; i < M; i++) {
			Edge r = e.top();
			e.pop();
			
			int sum = dS[r.f] + dT[r.t] + r.c;
			
			if (sum <= P) {
				chmax(ans, (Int) r.c);
			}
		}

		*/

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < (int) graphA[i].size(); j++) {
				int u = i, v = graphA[i][j].first;
				int toll = graphA[i][j].second;

				if (dS[u] + dT[v] + toll <= P) {
					chmax(ans, (Int) toll);
				}
			}
		}
		printf("%lld\n", ans);

		for (int i = 0; i < MAXN; i++) {
			graphA[i].clear();
			graphB[i].clear();
		}		
	}
    return 0;
}
