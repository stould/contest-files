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

const int MAXN = 2020;
const Int INF = 1001010100100101000LL;

int N;
Int M[MAXN][MAXN];

vector<int> G[MAXN];
Int dist[MAXN];

struct UnionFind {
    int N, *id, *sz;

    UnionFind(int _N) {
        id = new int[_N];
        sz = new int[_N];
        for(int i = 0; i < _N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        N = _N;
    }
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        if(i == j) return;
        if(sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
    }
};

struct edge {
    int from, to;
	Int cost;
    edge() {}
    edge(int from, int to, Int cost): from(from), to(to), cost(cost) {};

    bool operator<(const edge& e) const {
		return cost < e.cost;
    }
};

pair<int, Int> bfs(int s) {
	fill(dist, dist + MAXN, INF);

	queue<int> q;
	q.push(s);
	
	dist[s] = 0LL;

	Int ans = 0LL;
	int v = -1;

	for ( ; !q.empty(); ) {
		int now = q.front();
		q.pop();

		if (dist[now] > ans) {
			ans = dist[now];
			v = now;
		}

		for (int i = 0; i < G[now].size(); i++) {
			int next = G[now][i];

			if (dist[next] > M[now][next] + dist[now]) {
				dist[next] = M[now][next] + dist[now];
				q.push(next);				
			}
		}
	}

	return make_pair(v, ans);
}

pair<Int, pair<int, int> > diam(void) {
	pair<int, Int> f = bfs(0);
	int from = f.first;
	pair<int, Int> s =  bfs(f.first);
	int to = s.first;
	
	return make_pair(s.second, make_pair(to, from));
}

int main(void) {
	cin >> N;

	vector<edge> edges;

	UnionFind u(N);

	bool ok = true;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> M[i][j];

			if (i == j && M[i][j] != 0) {
				ok = false;
			} else if (i > j && M[i][j] != M[j][i]) {
				ok = false;
			}
			if (i != j && M[i][j] != 0) {
				edges.push_back(edge(i, j, M[i][j]));
			}
		}
	}

	if (N == 1) {
		if (M[0][0] == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	} else {
		if (edges.size() == 0) {
			cout << "NO\n";
		} else {
			sort(edges.begin(), edges.end());
			
			for (int i = 0; i < (int) edges.size(); i++) {
				if(!u.find(edges[i].from, edges[i].to)) {
					u.unite(edges[i].from, edges[i].to);
					G[edges[i].from].push_back(edges[i].to);
					G[edges[i].to].push_back(edges[i].from);
				}
			}
			
			//dist (from, to)
			pair<Int, pair<int, int> > d = diam();
			
			for (int i = 0; i < N; i++) {
				Int s_i = dist[i];
				Int n_i = d.first - dist[i];
				
				if (M[d.second.first][i] != n_i || M[i][d.second.second] != s_i) {
					ok = false;
				}
			}
			if (ok) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

    return 0;
}
