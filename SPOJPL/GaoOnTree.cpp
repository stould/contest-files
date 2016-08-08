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

const int MAXN = 100005;
const int MAX_LOG = 25;

int N, M;
int P[MAXN];
vector<int> tree[MAXN];
int lca[MAXN][MAX_LOG];
int par[MAXN];
int root[MAXN];
int level[MAXN];
int L[4 * MAXN * MAX_LOG];
int R[4 * MAXN * MAX_LOG];
int seg_tree[4 * MAXN * MAX_LOG];
int INDEX;

void clean() {
    for (int i = 0; i < MAXN; i++) {
        root[i] = 0;
        level[i] = 0;
        par[i] = 0;
        
        tree[i].clear();    
    }
    
    INDEX = 1;
}

void build(int node, int l, int r) {
    if (l == r) {
        return;
    } else {
        int m = (l + r) / 2;
        L[node] = INDEX++;
        R[node] = INDEX++;

        build(L[node], l, m);
        build(R[node], m + 1, r);
    }
}

int update(int node, int l, int r, int pos, int val) {
    int now = INDEX++;

    L[now] = L[node];
    R[now] = R[node];

    seg_tree[now] = seg_tree[node];
    
    if (l == r) {
        seg_tree[now] += val;
    } else {
        int m = (l + r) / 2;

        if (pos <= m) {
            L[now] = update(L[node], l, m, pos, val); 
        } else {
            R[now] = update(R[node], m + 1, r, pos, val);
        }
        
        seg_tree[now] = seg_tree[L[now]] + seg_tree[R[now]];
    }
    
    return now;
}

int query(int l_node, int r_node, int lca_parent, int lca_value, int l, int r, int pos) {
    //cout << seg_tree[l_node] << " " << seg_tree[r_node] << "\n";
    if (l == r) {
        int cnt = 0;

        cnt += seg_tree[l_node];
        cnt += seg_tree[r_node];
        cnt -= 2 * seg_tree[lca_parent];

        if (P[lca_value] == pos) {
            cnt -= 1;
        }

        if (cnt < 0) {
            assert(false);
        }
        //if (lca_node == lca_parent) {
        //cout << "cu\n";
        //}
        //cout << pos << " " << cnt << endl;
        return cnt > 0 ? 1 : 0;
    } else {
        int m = (l + r) / 2;
        
        if (pos <= m) {
            return query(L[l_node], L[r_node], L[lca_parent], lca_value, l, m, pos);
        } else {
            return query(R[l_node], R[r_node], R[lca_parent], lca_value, m + 1, r, pos);
        }
    }
}

////// BRUTE
int dumb(int node, int l, int r, int pos) {
    if (l == r) {
        return seg_tree[node];
    } else {
        int m = (l + r) / 2;
        
        if (pos <= m) {
            return dumb(L[node], l, m, pos);
        } else {
            return dumb(R[node], m + 1, r, pos);
        }
    }
}

void dfs(int node, int parent) {
    lca[node][0] = parent;

    for (int i = 1; i < MAX_LOG; i++) {
        lca[node][i] = lca[lca[node][i - 1]][i - 1];
    }

    if (node == 1) {
        root[node] = update(root[0], 0, N, P[node], 1);
    } else {
        root[node] = update(root[parent], 0, N, P[node], 1);
    }

    for (auto& it : tree[node]) {
        if (it != parent) {
            dfs(it, node);

            level[it] = level[node] + 1;
            par[it] = node;
        }
    }
}

int getLca(int a, int b) {
    if (level[a] < level[b]) {
        swap(a, b);
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (level[a] - (1 << i) >= level[b]) {
            a = lca[a][i];
        }
    }
    if (a == b) {
        return a;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (lca[a][i] != lca[b][i]) {
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    
    return lca[a][0];
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    while (cin >> N >> M) {
        clean();
        
        for (int i = 1; i <= N; i++) {
            cin >> P[i];
        }


        
        for (int i = 0; i < N - 1; i++) {
            int a, b;
            cin >> a >> b;
            
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        root[0] = update(0, 0, N, 0, 0);
        dfs(1, 1);

        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            
            int lc = getLca(a, b);

            int res = query(root[a], root[b], root[par[lc]], lc, 0, N, c);
            
            if (res > 0) {
                cout << "Find\n";
            } else {
                cout << "NotFind\n";
            }
        }
        cout << "\n";
    }
    
    return 0;
}
