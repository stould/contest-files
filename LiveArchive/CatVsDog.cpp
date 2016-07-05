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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1010;
const int INF = 1011;

int T;
int C, D, N;
string P[MAXN], Q[MAXN];
vector<int> graph[MAXN];
int color[MAXN];

void dfs(int x, int c) {
    color[x] = c;

    for (int i = 0; i < (int) graph[x].size(); i++) {
        if (color[graph[x][i]] == -1) {
            dfs(graph[x][i], c ^ 1);
        }
    }
}

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
        for (int i = 0; i < (int) G[v].size(); i++) {
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
    cin >> T;

    while (T--) {
        cin >> C >> D >> N;

        init(N + 2);
        
        for (int i = 0; i < MAXN; i++) {
            graph[i].clear();
            color[i] = -1;
        }

        for (int i = 1; i <= N; i++) {
            cin >> P[i] >> Q[i];

            for (int j = 1; j < i; j++) {
                if (P[i] == Q[j] || Q[i] == P[j]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (color[i] == -1) {
                dfs(i, 0);
            }
        }

        for (int i = 1; i <= N; i++) {
            if (color[i] == 0) {
                add_edge(0, i, 1);

                for (int j = 0; j < (int) graph[i].size(); j++) {
                    add_edge(i, graph[i][j], 1);
                }
            } else {
                add_edge(i, N + 1, 1);
            }
        }

        cout << N - max_flow(0, N + 1) << "\n";
    }
    return 0;
}
