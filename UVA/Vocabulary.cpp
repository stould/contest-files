#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

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

const int MAXN = 2 * 550 + 10;
const Int INF = 10100100LL;

int V, C;
int freqV[550][30], freqC[550][30];


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

 
bool func(int a, int b) {
    for (int i = 0; i < 26; i++) {
		if (freqV[a][i] < freqC[b][i]) {
			return false;
		}
    }

    return true;
}

string vc[MAXN];
string ch[MAXN];

int main(void) {
    for ( ; cin >> V >> C; ) {
		memset(freqV, 0, sizeof(freqV));
		memset(freqC, 0, sizeof(freqC));
		for (int i = 0; i < MAXN; i++) {
			G[i].clear();
		}

        for (int i = 1; i <= V; i++) {
            cin >> vc[i];
			
			for (int j = 0; j < (int) vc[i].size(); j++) {
				freqV[i][vc[i][j] - 'a'] += 1;
			}
			
			add_edge(0, i, 1);
        }

        for (int i = 1; i <= C; i++) {
            cin >> ch[i]; 

			for (int j = 0; j < (int) ch[i].size(); j++) {
				freqC[i][ch[i][j] - 'a'] += 1;
			}

			add_edge(V + i, V + C + 2, 1);
		}
		for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= C; j++) {
                if (func(i, j)) {
					add_edge(i, V + j, 1);
                }
            }
        }
		
		printf("%d\n", max_flow(0, V + C + 2));
	}
    return 0;
}
