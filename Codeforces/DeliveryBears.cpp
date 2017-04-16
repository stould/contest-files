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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 510;
const int INF = 1001;

int N, M, K;
vector<int> paths;
int A[MAXN], B[MAXN], C[MAXN];

struct edge {
    int to,rev;    
    double cap;
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

Int dfs(int v, int t, double f) {
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

double max_flow(int s, int t) {
    double flow = 0;
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

double func(int pos, double carry, int used) {
    if (pos == (int) paths.size()) {
        return carry;
    } else if (used == 0) {
        return -INF;
    } else {
        double ans = -1000;
        
        for (int i = used; i >= 1; i--) {
            if (used - i >= (int) paths.size() - pos + 1) {
                ans = max(ans, func(pos + 1, min(carry, paths[pos] / (double) i), used - i));
            }
        }

        return ans;
    }
}

int main(void) {
    cin >> N >> M >> K;

    init(N + 1);
    
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    double l = 0.0, h = 100000000000000.0;

    for (int x = 0; x < 100; x++) {
        double m = (l + h) / 2;

        init(N + 1);
        
        for (int i = 0; i < M; i++) {
            add_edge(A[i], B[i], C[i] / m);
        }

        if (max_flow(1, N) < K) {
            h = m;
        } else {
            l = m;
        }
    }
    
    cout << fixed << setprecision(12) << l * K << endl;
    
    return 0;
}
