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

const int MAXN = 2 * 40 * 10 + 10;

int T, N, M;
char S[50][15];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

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

int func(int x, int y) {
	return x * M + y;
}

int main(void) {
	scanf("%d", &T);
	
	for ( ; T--; ) {
		scanf("%d%d", &N, &M);
		
		for (int i = 0; i < N; i++) {
			scanf("%s", S[i]);
		}

		init(N * M + 10);

		int star = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (S[i][j] == '*') {
					star += 1;
					for (int k = 0; k < 4; k++) {
						int pi = i + dx[k];
						int pj = j + dy[k];
						
						if (pi >= 0 && pj >= 0 && pi < N && pj < M && S[pi][pj] == '*') {
							add_edge(1 + func(i, j), 1 + func(pi, pj), 1);
						}
					}
					if ((i + j) % 2 == 1) {
						add_edge(0, 1 + func(i, j), 1);
					} else {
						add_edge(1 + func(i, j), N * M + 1, 1);
					}
				}
			}
		}

		printf("%d\n", star - max_flow(0, N * M + 1));
	}
    return 0;
}
