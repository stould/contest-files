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

int N, M;

const int MAXN = 550;
const int INF = 10101;

struct edge {
    int to,rev;
    Int cap;
    edge(int to, Int cap, int rev): to(to), cap(cap), rev(rev) {}
};

vector<edge> G[MAXN];
Int level[MAXN];
int iter[MAXN];

void init(int N) {
    for (int i = 0; i < N; i++) {
        G[i].clear();
    }
}

void add_edge(int from,int to,Int cap) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            edge& e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

Int dfs(int v, int t, Int f) {
    if(v == t) return f;
    for(int& i = iter[v]; i < (int) G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            Int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    Int flow = 0;
    for( ; ; ) {
        bfs(s);
        if (level[t] < 0) {
            return flow;
        }
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f=dfs(s,t,INF*INF)) > 0) {
            flow += f;
        }
    }
}

int main(void) {
	for ( ; cin >> N >> M && (N + M != 0); ) {
		vector<string> vsN[N + 1], vsM[M + 1];

		for (int i = 1; i <= N; i++) {
			int T;
			string Si;

			cin >> T;
			for (int j = 0; j < T; j++) {
				cin >> Si;
				vsN[i].push_back(Si);
			}
			sort(vsN[i].begin(), vsN[i].end());
		}
		for (int i = 1; i <= M; i++) {
			int T;
			string Si;

			cin >> T;
			for (int j = 0; j < T; j++) {
				cin >> Si;
				vsM[i].push_back(Si);
			}
			sort(vsM[i].begin(), vsM[i].end());
		}
		int s = 0, t = N + M + 2;
		
		init(t + 1);

		for (int i = 1; i <= M; i++) {
			add_edge(s, i, INF);

			for (int j = 1; j <= N; j++) {
				bool has = false;
				for (int k = 0; !has && k < (int) vsM[i].size(); k++) {
					if (find(vsN[j].begin(), vsN[j].end(), vsM[i][k]) != vsN[j].end()) {
						has = true;
					}
				}
				if (has) {
					add_edge(i, M + j, 1);
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			add_edge(M + i, t, INF);
		}
		printf("%d\n", max_flow(s, t));
	}
    return 0;
}
