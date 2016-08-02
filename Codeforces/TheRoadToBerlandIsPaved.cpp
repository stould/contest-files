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

const int MAXN = 330;

int N, M;
vector<int> G[MAXN];
vector<int> order;
int vis[MAXN], cmp[MAXN];
stack<int> topo;

void dfs1(int node) {
    vis[node] = true;

    for (int i = 0; i < (int) G[node].size(); i++) {
        int next = G[node][i];

        if (!vis[next]) {
            dfs1(next);
        }
    }
    topo.push(node);
    order.push_back(node);
}

void dfs2(int node, int curr_comp) {
    vis[node] = true;
    cmp[node] = curr_comp;

    for (int i = 0; i < (int) G[node].size(); i++) {
        int next = G[node][i];

        if (!vis[next]) {
            dfs2(next, curr_comp);
        }
    }
}

int main(void) {    
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        A *= 2;
        B *= 2;
        
        if (C == 0) {
            G[A].push_back(B ^ 1);
            G[B].push_back(A ^ 1);

            G[A ^ 1].push_back(B);
            G[B ^ 1].push_back(A);       
        } else {
            G[A].push_back(B);
            G[B].push_back(A);
            
            G[A ^ 1].push_back(B ^ 1);
            G[B ^ 1].push_back(A ^ 1);
        }      
    }

    for (int i = 2; i <= 2 * N + 1; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    memset(vis, false, sizeof(vis));

    int cp = 1;
    
    while (!topo.empty()) {
        int now = topo.top();
        topo.pop();
        
        if (!vis[now]) {
            dfs2(now, cp++);
        }
    }
    
    bool fine = true;
    
    for (int i = 2; i <= 2 * N + 1; i++) {
        if (cmp[i] == cmp[i ^ 1]) {
            fine = false;
        }
    }

    if (!fine) {
        cout << "Impossible" << endl;
    } else {
        vector<int> ans;
        
        memset(vis, false, sizeof(vis));
        
        for (int i = 0; i < (int) order.size(); i++) {
            int now = order[i];
            
            if (!vis[now / 2]) {
                if (now % 2 == 0) {
                    ans.push_back(now / 2);
                }
            }
            vis[now / 2] = 1;
        }

        
        cout << ans.size() << endl;
        
        for (int i = 0; i < (int) ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
