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

const int MAXN = 1550;

int T;
int N, M;
int P[MAXN];
int cnt[MAXN];
vector<int> G[MAXN];
int dist[MAXN];

void clear() {
    for (int i = 0; i < MAXN; i++) {
        G[i].clear();
        cnt[i] = 0;
    }
}

typedef int Flow;
typedef int Cost;

const Flow INF = 0x3f3f3f3f;

struct Edge {
    int src, dst;
    Cost cst;
    Flow cap;
    int rev;
};

bool operator<(const Edge a, const Edge b) {
    return a.cst > b.cst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph&G, int u, int v, Flow c, Cost l) {
    G[u].push_back((Edge){ u, v, l, c, int(G[v].size()) });
    G[v].push_back((Edge){ v, u, -l, 0, int(G[u].size()-1) });
}

pair<Flow, Cost> flow(Graph&G, int s, int t) {
    int n = G.size();
    Flow flow = 0;
    Cost cost = 0;
    for ( ; ; ) {
        priority_queue<Edge> Q;
        vector<int> prev(n, -1), prev_num(n, -1);
        vector<Cost> length(n, INF);
        Q.push((Edge){-1,s,0,0,0});
        prev[s]=s;
        for (;!Q.empty();) {
            Edge e=Q.top();
            Q.pop();
            int v = e.dst;
            for (int i=0; i<(int)G[v].size(); i++) {
                if (G[v][i].cap>0 && length[G[v][i].dst]>e.cst+G[v][i].cst) {
                    prev[G[v][i].dst]=v;
                    Q.push((Edge){v, G[v][i].dst, e.cst+G[v][i].cst,0,0});
                    prev_num[G[v][i].dst]=i;
                    length[G[v][i].dst]=e.cst+G[v][i].cst;
                }
            }
        }
        if (prev[t]<0) return make_pair(flow, cost);
		
        Flow mi=INF;
        Cost cst=0;
        for (int v=t; v!=s; v=prev[v]) {
            mi=min(mi, G[prev[v]][prev_num[v]].cap);
            cst+=G[prev[v]][prev_num[v]].cst;
        }
        
        cost+=cst*mi;

        for (int v=t; v!=s; v=prev[v]) {
            Edge &e=G[prev[v]][prev_num[v]];
            e.cap-=mi;
            G[e.dst][e.rev].cap+=mi;
        }
        flow += mi;
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);

    for (int i = 0; i < MAXN; i++) {
        dist[i] = INF;
    }

    dist[s] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i];

            if (dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}


int main(void) {
    cin >> T;

    while (T--) {
        cin >> N;

        clear();
        
        for (int i = 1; i <= N; i++) {
            cin >> P[i];
            cnt[P[i]] += 1;
        }

        cin >> M;

        for (int i = 0; i < M; i++) {
            int a, b;

            cin >> a >> b;
            
            G[a].push_back(b);
            G[b].push_back(a);
        }

        Graph flow_graph(2 * N + 5);

        for (int i = 1; i <= N; i++) {
            add_edge(flow_graph, 0, i, cnt[i], 0);
            add_edge(flow_graph, N + i, N + N + 2, 1, 0);

            bfs(i);

            for (int j = 1; j <= N; j++) {
                if (dist[j] != INF) {
                    add_edge(flow_graph, i, N + j, INF, dist[j]);
                }            
            }
        }
        
        pair<Flow, Cost> ans = flow(flow_graph, 0, N + N + 2);

        if (ans.first == N) {
            cout << ans.second << endl;
        } else {
            assert(false);
        }
    }
    
    return 0;
}
