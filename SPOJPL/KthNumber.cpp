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
const int MAX_LOG = 20;

int N, M;
int P[MAXN];
int root[MAXN];
int tree[4 * MAX_LOG * MAXN];
int realValue[MAXN];
int L[4 * MAX_LOG * MAXN], R[4 * MAX_LOG * MAXN];
int INDEX = 1;

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
    int next = INDEX++;

    L[next] = L[node];
    R[next] = R[node];
    tree[next] = tree[node];
    
    if (l == r) {
        tree[next] += val;
    } else {
        int m = (l + r) / 2;

        if (pos <= m) {
            L[next] = update(L[node], l, m, pos, val);
        } else {
            R[next] = update(R[node], m + 1, r, pos, val);
        }

        tree[next] = tree[L[next]] + tree[R[next]];
    }

    
    return next;
}

int query(int node, int l, int r, int bl, int br) {
    if (l > br || r < bl) {
        return 0;
    } else if (l >= bl && r <= br) {
        return tree[node];
    } else {
        int m = (l + r) / 2;

        int sa = query(L[node], l, m, bl, br);
        int sb = query(R[node], m + 1, r, bl, br);

        return sa + sb;
    }
}

int func(int node_l, int node_r, int pl, int pr, int k) {
    if (pl == pr) {
        return pl;
    } else {
        int m = (pl + pr) / 2;
       
        int sl = query(node_l, 0, N - 1, 0, m);
        int sr = query(node_r, 0, N - 1, 0, m);

        int sum = sr - sl;

        //cout << realValue[m] << " " <<  sum <<" \n";
        
        if (sum >= k) {
            return func(node_l, node_r, pl, m, k);
        } else {
            return func(node_l, node_r, m + 1, pr, k);
        }
    }
}


int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    set<int> aux;
    unordered_map<int, int> compress;    
    int val = 0;
    
    for (int i = 1; i <= N; i++) {
        cin >> P[i];        
        aux.insert(P[i]);
    }

    for (auto& it : aux) {
        compress[it] = val;
        realValue[val++] = it;
    }

    build(root[0], 0, N);
    
    for (int i = 1; i <= N; i++) {
        P[i] = compress[P[i]];
        root[i] = update(root[i - 1], 0, N - 1, P[i], 1);
        //cout << "rt " << i << " " << root[i] << " " << tree[root[i]] << "\n";
    }

    for (int i = 0; i < M; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        
        cout << realValue[func(root[l - 1], root[r], 0, N - 1, k)] << "\n";
    }
    return 0;
}
