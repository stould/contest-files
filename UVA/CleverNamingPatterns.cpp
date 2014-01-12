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

const int MAXN = 200;
const int INF = 1000;

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
        while ((f=dfs(s, t, INF * INF)) > 0) {
            flow += f;
        }
    }
}

int T, N;
int C[MAXN];
vector<string> vs[MAXN];

string name;

int main(void) {
	cin >> T;

	for (int x = 1; x <= T; x++) {
		cin >> N;

		init(N + 30);
		for (int i = 0; i < MAXN; i++) {
			C[i] = 0;
			vs[i].clear();
		}
		
		int s = 0, t = N + 28;

		set<char> used;

		for (int i = 0; i < N; i++) {
			cin >> C[i];
			for (int j = 0; j < C[i]; j++) {
				cin >> name;

				int pos = tolower(name[0]) - 'a' + 1;

				add_edge(i + 1, N + pos, 1);

				used.insert(pos);

				vs[i].push_back(name);
			}
		}
		for (int i = 1; i <= N; i++) {
			add_edge(s, i, 1);
		}
		for (int i = 1; i <= 26 && used.count(i); i++) {
			add_edge(N + i, t, 1);
		}

		max_flow(s, t);

		vector<string> ans(30, "");

		for (int i = 1; i <= N; i++) {
			int pos = -1;
			for (int j = 0; j < (int) G[i].size(); j++) {
				if (G[i][j].cap == 0LL) {
					pos = G[i][j].to - N;
					break;
				}
			}
			for (int j = 0; j < (int) vs[i - 1].size(); j++) {
				if (tolower(vs[i - 1][j][0]) - 'a' + 1 == pos) {
					ans[tolower(vs[i - 1][j][0]) - 'a'] = vs[i - 1][j];
					break;
				}
			}
		}
		
		printf("Case #%d:\n", x);

		for (int i = 0; i < 26; i++) {
			if (ans[i] != "") {
				for (int j = 0; j < (int) ans[i].size(); j++) {
					if (j == 0) {
						cout << (char) toupper(ans[i][j]);
					} else {
						cout << (char) tolower(ans[i][j]);
					}
				}
				cout << "\n";
			}
		}
	}

    return 0;
}
