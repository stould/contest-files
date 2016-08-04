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

const int MAXN = 5020;

int N, M;
vector<int> G[MAXN], R[MAXN];
int vis[MAXN], comp[MAXN];
vector<int> order;

void add(int a, int b) {
    int ia = a;
    int ib = b;

    if (a < 0) {
        ia = ((-a) * 2) + 1;
    } else {
        ia = (2 * a);
    }

    if (b < 0) {
        ib = ((-b) * 2) + 1;
    } else {
        ib = (2 * b);
    }

    G[ia ^ 1].push_back(ib);
    G[ib ^ 1].push_back(ia);
    

    R[ia].push_back(ib ^ 1);
    R[ib].push_back(ia ^ 1);    
}

void dfs(int node) {
    vis[node] = true;

    for (auto& it : G[node]) {
        //cout << node << " " << it << "\n";
        if (!vis[it]) {
            dfs(it);
        }
    }
    
    order.push_back(node);
}

void dfsRev(int node, int cp) {
    vis[node] = true;
    comp[node] = cp;    

    for (auto& it : R[node]) {
        if (!vis[it]) {
            dfsRev(it, cp);
        }
    }
}

bool twoSat() {
    memset(vis, false, sizeof(vis));
    order.clear();

    for (int i = 0; i < 2 * N; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    memset(vis, false, sizeof(vis));
    int curr_comp = 1;
    
    for (int i = (int) order.size() - 1; i >= 0; i--) {
        if (!vis[order[i]]) {
            dfsRev(order[i], curr_comp++);
        }
    }
    
    for (int i = 0; i < 2 * N; i++) {
        if (comp[i] == comp[i ^ 1]) {
            return false;
        }
    }
    
    return true;
}

int main(void) {
    while (cin >> N >> M) {
        for (int i = 0; i < MAXN; i++) {
            G[i].clear();
            R[i].clear();
        }

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            add(a, b);
        }

        if (twoSat()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}
