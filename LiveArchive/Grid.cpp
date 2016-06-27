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

const int MAXN = 5555;
const Int INF = 10000100LL;

int T, N, M;
int P[55][55];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void gen() {
    srand(time(NULL));
    cout << 10 << "\n";
    for (int x = 0; x < 10; x++) {
        cout << 50 << " " << 50 <<"\n";
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                cout << rand() % 1001 << " ";
            }
            cout <<"\n";
        }
        cout << "\n";
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
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    //gen(); return 0;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        init(MAXN);

        int sum = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> P[i][j];
                sum += P[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if ((i + j) % 2 == 0) {
                    add_edge(0, M * i + j + 1, P[i][j]);
                    for (int k = 0; k < 4; k++) {
                        int pi = i + dx[k];
                        int pj = j + dy[k];

                        if (pi >= 0 && pj >= 0 && pi < N && pj < M) {
                            add_edge(M * i + j + 1, M * pi + pj + 1, INF);
                        }
                    }
                } else {
                    add_edge(M * i + j + 1, N * M + N + M, P[i][j]);
                }
            }
        }
        
        int ans = max_flow(0, N * M + N + M);
    
        cout << sum - ans << "\n";
    }
    
    return 0;
}
