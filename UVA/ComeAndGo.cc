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

const int MAXN = 2005;
const int INF = INT_MAX / 3;

int N, M;
int A, B, P, T;

int vis[MAXN], level[MAXN];

vector<int> graph[MAXN];
stack<int> st;
vector<vector<int> > comp;

void dfs(int x) {
    level[x] = T++;
    vis[x] = 1;
    st.push(x);
    
    bool root = true;
    
    for (int i = 0; i < (int) graph[x].size(); i++) {
        int u = graph[x][i];
        
        if (!vis[u]) {
            dfs(u);
        }
        if (level[u] < level[x]) {
            level[x] = level[u];
            root = false;
        }
    }
    
    if (root) {
        vector<int> conn;
        
        int p = -1;
        
        for ( ; p != x; ) {
            p = st.top();
            st.pop();
            
            level[p] = INF;
            conn.push_back(p);
        }        
        comp.push_back(conn);
    }
}



int main(void) {
    for ( ; scanf("%d%d", &N, &M) == 2 && N + M != 0; ) {
        T = 0;
        for (int i = 0; i < MAXN; i++) {
            vis[i] = level[i] = 0;
            graph[i].clear();
        }
        st = stack<int>();
        comp.clear();
        for (int i = 0; i < M; i++) {
            scanf("%d%d%d", &A, &B, &P);
            
            graph[A].push_back(B);
            
            if (P == 2) {
                graph[B].push_back(A);
            }                                               
        }
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        if (comp.size() == 1) {
            puts("1");
        } else {
            puts("0");
        }
    }
    return 0;
}
