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

const int MAXN = 10110;
const int INF = 100011;

int N, Q, K;
int C[MAXN];
int T[MAXN][MAXN];
int label[MAXN][MAXN];
int Q_T[MAXN];

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
        while ((f=dfs(s,t,INF)) > 0) {
            flow += f;
        }
    }
}


int main(void) {
    while (cin >> N >> Q && N != 0) {
        int cnt = N + 1;

        set<int> seen[N];
        
        for (int i = 0; i < N; i++) {
            cin >> C[i];

            for (int j = 0; j < C[i]; j++) {
                cin >> T[i][j];
                label[i][j] = cnt++;

                seen[i].insert(T[i][j]);
            }

            if (C[i] != N) {
                seen[i].insert(0);
            }
        }

        for ( ; Q--; ) {
            cin >> K;

            vector<int> used(N + 1, 0);
            
            init(MAXN);
            
            int s = 0;
            int t = cnt + 3 * N + 10;

            for (int i = 0; i < K; i++) {
                cin >> Q_T[i];

                add_edge(s, i + 1, 1);
            }


            for (int i = 0; i < N; i++) {
                add_edge(s, i + 1, 1);
               
                for (int j = 0; j < C[i]; j++) {
                    add_edge(label[i][j], cnt + i + 1, 1);
                    
                    for (int k = 0; k < K; k++) {
                        if (Q_T[k] == T[i][j]) {
                            add_edge(k + 1, label[i][j], 1);
                        }
                    }
                }
                
                add_edge(cnt + i + 1, t, 1);
            }

            bool completed = true;

            for (int i = 0; i < N; i++) {
                if (K != N && seen[i].count(0)) {
                    used[i] = 1;
                }
                completed &= used[i];
            }
                        
            int f = max_flow(s, t);
            //cout << f << " " << K << "\n";
            if (f >= K) {
                cout << "Y\n";
            } else {
                cout << "N\n";
            }
        }
    }
    return 0;
}
