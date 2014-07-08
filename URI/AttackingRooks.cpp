#include <bits/stdc++.h>
  
int in() { int x; scanf("%d", &x); return x; }
  
using namespace std;
  
typedef long long Int;
typedef unsigned uint;
 
const int MAXN = 100 * 100 * 100 + 11;
const int INF = 10110;
int N;
 
string str[110];
 
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
 
map<pair<int, pair<int, int> >, int> mr, mc;
  
int main(void) {
    for ( ; cin  >> N; ) {
        init(N * N * N + 10);
        mr.clear();
        mc.clear();
 
        int ir = 1, rc = 1;
 
        for (int i = 0; i < N; i++) {
            cin >> str[i];
        }
 
        set<int> tor, toc;
 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (str[i][j] == '.') {      
                    int rl = j, rr = j;
                    int cu = i, cd = i;
 
                    for (int k = i - 1; k >= 0; k--) {
                        if (str[k][j] == 'X') {
                            break;
                        }
                        cu = k;
                    }
                    for (int k = i + 1; k < N; k++) {
                        if (str[k][j] == 'X') {
                            break;
                        }
                        cd = k;
                    }
                    for (int k = j - 1; k >= 0; k--) {
                        if (str[i][k] == 'X') {
                            break;
                        }
                        rl = k;
                    }
                    for (int k = j + 1; k < N; k++) {
                        if (str[i][k] == 'X') {
                            break;
                        }
                        rr = k;
                    }
                    pair<int, pair<int, int> > cp = make_pair(j, make_pair(cu, cd));
                    pair<int, pair<int, int> > rp = make_pair(i, make_pair(rl, rr));
 
                    if (mr[rp] == 0) mr[rp] = ir++;
                    if (mc[cp] == 0) mc[cp] = rc++;
 
                    add_edge(mr[rp], N * N + mc[cp], 1);
 
                    tor.insert(mr[rp]);
                    toc.insert(mc[cp]);
                }
            }  
        }
        for (set<int>::iterator it = tor.begin(); it != tor.end(); it++) {
            add_edge(0, *it, 1);
        }
        for (set<int>::iterator it = toc.begin(); it != toc.end(); it++) {
            add_edge(N * N + *it, N * N * N, 1);
        }
 
        printf("%d\n", max_flow(0, N * N * N));
    }
    return 0;
}
